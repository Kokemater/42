#!/bin/bash

$ARG=$(shuf -i 1-500 | tr '\n' ' '>text.txt ; cat text.txt)

./push_swap $ARG 