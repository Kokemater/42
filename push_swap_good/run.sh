#!/bin/bash

ARG=$(shuf -i 1-500 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG