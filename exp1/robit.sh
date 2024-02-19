#!/bin/bash

# Verifica se pelo menos um arquivo .c foi fornecido
if [ "$#" -lt 1 ]; then
  echo "Usage: $0 <file1.c> <file2.c> [... <fileN.c>]"
  exit 1
fi

# Nome do arquivo de saída para os resultados das comparações
output_file="radiff_results.txt"
# Limpa o arquivo de saída ou cria se não existir
> "$output_file"

# Compila cada arquivo .c fornecido
for file in "$@"; do
  if [[ $file == *.c ]]; then
    base_name=$(basename "$file" .c)
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

# Coleta os nomes dos executáveis compilados
compiled_files=()
for file in "$@"; do
  if [[ $file == *.c ]]; then
    compiled_files+=($(basename "$file" .c))
  fi
done

# Executa radiff2 em todos os pares possíveis e salva a saída no arquivo de resultados
for ((i = 0; i < ${#compiled_files[@]}; i++)); do
  for ((j = i + 1; j < ${#compiled_files[@]}; j++)); do
    file1="${compiled_files[i]}"
    file2="${compiled_files[j]}"
    # Captura a saída do radiff2
    radiff_output=$(radiff2 -ss "$file1" "$file2")
    # Extrai as linhas relevantes (pode haver uma linha de tamanho de arquivo, além de similarity e distance)
    relevant_lines=$(echo "$radiff_output" | grep -E 'similarity:|distance:')
    # Escreve no arquivo de resultados
    echo "Comparando $file1 e $file2:" >> "$output_file"
    echo "$relevant_lines" >> "$output_file"
    echo "" >> "$output_file" # Linha em branco para separar as entradas
  done
done

echo "Resultado das comparações salvo em $output_file"

