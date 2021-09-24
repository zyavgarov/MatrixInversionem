cmake_minimum_required(VERSION 3.20)
project(MatrixInversionem C)

set(CMAKE_C_STANDARD 99)

add_executable(MatrixInversionem matrix_inversion.h matrix_reading.h main.c matrix_reading.c matrix_inversion.c)
target_link_libraries(MatrixInversionem m)