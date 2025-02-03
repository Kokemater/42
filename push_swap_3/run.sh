#!/bin/bash

# Compilar el programa push_swap con sanitizadores de memoria
gcc *.c -o push_swap -g -fsanitize=address

# Generar una lista aleatoria de 500 números del 1 al 500
shuf -i 1-500 > numeros.txt

# Leer la lista y pasarla como argumentos a push_swap, guardando la salida en results.txt
./push_swap $(cat numeros.txt) > results.txt 

# Mostrar el número de líneas de results.txt en la terminal
echo "Número de líneas en results.txt: $(wc -l < results.txt)"
