# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Define el nombre del proyecto
project(test VERSION 1.0)

# Indica el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añade el ejecutable
add_executable(test 
main.c
get_next_line.c
get_next_line.h)
