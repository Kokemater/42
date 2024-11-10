# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Define el nombre del proyecto
project(test VERSION 1.0)


# Añade el ejecutable
add_executable(test 
main.c
get_next_line.c)
