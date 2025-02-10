#!/bin/bash

# Compilar el programa push_swap con sanitizadores de memoria
gcc *.c -Wall -Wextra -Werror -o push_swap -g -fsanitize=address
if [ $? -ne 0 ]; then
    echo "Error de compilación."
    exit 1
fi

# Definir la cantidad de números
n=500  # Cambia este valor si lo necesitas

# Generar una lista aleatoria de 1 a n (sin duplicados) y guardarla en numeros.txt
shuf -i 1-$n -n $n > numeros.txt

# Leer la lista y pasarla como argumentos a push_swap, guardando la salida en results.txt
./push_swap $(cat numeros.txt) > results.txt 

# Mostrar el número de líneas de results.txt en la terminal
echo "Número de líneas en results.txt: $(wc -l < results.txt)"

# Verificar el resultado con checker_linux
ARG=$(cat numeros.txt | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
