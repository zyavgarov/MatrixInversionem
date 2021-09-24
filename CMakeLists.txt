cmake_minimum_required(VERSION 3.20)
project(MatrixInversionem C)

set(CMAKE_C_STANDARD 99)

add_executable(MatrixInversionem main.c matrix_reading.c matrix_inversion.c)
