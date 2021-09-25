//
// Created by pierre on 25.09.2021.
//

#ifndef MATRIXINVERSIONEM_CMAKE_BUILD_DEBUG_MISC_H_
#define MATRIXINVERSIONEM_CMAKE_BUILD_DEBUG_MISC_H_
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define EPS 0.0005
// EPS defines whether the numbers are equivalent to each other
void show_matrix (int m, int n, double ***A);
void show (int n, int m, double ***A, double ***X, double time);
double norm (int n, double ***A);
int is_0 (double x);
#endif //MATRIXINVERSIONEM_CMAKE_BUILD_DEBUG_MISC_H_
