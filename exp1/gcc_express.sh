#!/bin/bash

# Localiza todos os arquivos .c na pasta atual
for file in *.c; do
    # Remove a extensão .c para obter o nome base do arquivo
    base_name=$(basename "$file" .c)
    
    # Compila o arquivo com otimizações -O3 e ligações -lm
    # Gera um executável com sufixo _opt
    gcc -O3 "$file" -o "${base_name}_opt" -lm
    
    # Como queremos compilar duas vezes, repetimos o comando
    # Isso é apenas para seguir a instrução, mas o resultado será o mesmo
    gcc "$file" -o "${base_name}" -lm
done

echo "Compilação concluída."
