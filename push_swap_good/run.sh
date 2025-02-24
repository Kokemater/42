#!/bin/bash

for i in $(seq 1 100); do
    echo "Iteración: $i"
    ARG=$(shuf -i 1-500 | tr '\n' ' ')
    MY_ANSWER=$(./push_swap $ARG)
    LINES=$(echo "$MY_ANSWER" | wc -l)

    if [ "$LINES" -gt 5500 ]; then
        echo "Error en iteración $i, demasiadas líneas: $LINES"
        echo "$ARG" >> error.txt
        echo "$MY_ANSWER" >> error_ans.txt
    fi
done
