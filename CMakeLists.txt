cmake_minimum_required(VERSION 3.25)
project(matrix_calculator C)

set(CMAKE_C_STANDARD 11)

add_executable(matrix_calculator main.c functions.c functions.h)
