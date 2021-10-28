//
// Created by pierre on 25.09.2021.
//

#ifndef MATRIXINVERSIONEM_CMAKE_BUILD_DEBUG_MISC_H_
#define MATRIXINVERSIONEM_CMAKE_BUILD_DEBUG_MISC_H_
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "matrix_reading.h"
#define EPS 0.0000005
// EPS defines whether the numbers are equivalent to each other
void show_matrix (int m, int n, int l, double **A);
void show (int n, int m, int k, char *filename, double **A, double **X, double time);
int is_0 (double x);
void clean_memory (double **A, double **X, int n);
double get_error_norm (double **A, double **X, int n);
#endif //MATRIXINVERSIONEM_CMAKE_BUILD_DEBUG_MISC_H_
