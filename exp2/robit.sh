#!/bin/bash

# Verifica se pelo menos um arquivo .c foi fornecido
if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <file1.c> <file2.c> [... <fileN.c>]"
  exit 1
fi

# Nome do arquivo de saída
output_file="radiff_results.txt"

# Compila cada arquivo .c fornecido
for file in "$@"; do
  if [[ $file == *.c ]]; then
    base_name=$(basename "$file" .c) # Remove a extensão .c para usar como nome base
    gcc -O3 "$file" -o "$base_name" -lm
    if [ $? -ne 0 ]; then
      echo "Erro ao compilar $file"
      exit 1
    fi
  else
    echo "O arquivo $file não é um arquivo .c válido."
    exit 1
  fi
done

# Prepara um arquivo temporário para coletar os resultados
temp_file=$(mktemp)

# Itera sobre cada arquivo binário compilado para formar pares
compiled_files=("$@")
for ((i = 0; i < ${#compiled_files[@]}; i++)); do
  for ((j = i + 1; j < ${#compiled_files[@]}; j++)); do
    file1=$(basename "${compiled_files[i]}" .c)
    file2=$(basename "${compiled_files[j]}" .c)

    # Executa radiff2 e salva a saída temporariamente
    echo "Comparando $file1 e $file2" >> "$temp_file"
    radiff2 -ss "$file1" "$file2" >> "$temp_file"
    echo "-----" >> "$temp_file" # Separador para a próxima comparação
  done
done

# Ordena as comparações pelo campo 'distance' em ordem crescente e mantém a resposta completa
# Esta parte requer uma abordagem customizada, pois o sort padrão do bash não suporta bem essa necessidade complexa diretamente

# Primeiro, extrai as distâncias e linhas correspondentes para ordenação
awk '/Comparando/{file=$2 " " $3}; /distance:/{print $2, file}' "$temp_file" | sort -n -k1,1 | cut -d' ' -f2- > "$output_file.sorted"

# Agora, reconstitui a saída completa com base na ordenação
while IFS= read -r line; do
    grep -A10000 "Comparando $line" "$temp_file" | grep -B10000 '-----' | head -n -1 >> "$output_file"
    echo "" >> "$output_file"
done < "$output_file.sorted"

# Limpa arquivos temporários
rm "$temp_file" "$output_file.sorted"

echo "Resultado das comparações salvo em $output_file"
