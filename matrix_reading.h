//
// Created by pierre on 24.09.2021.
//

#ifndef MATRIXINVERSIONEM__MATRIX_READING_H_
#define MATRIXINVERSIONEM__MATRIX_READING_H_
#include <malloc.h>
#include <stdlib.h>
int max (int i, int j);
int read_matrix (int n, double **A, int k, char *filename);
double f (int k, int n, int i, int j);
#endif //MATRIXINVERSIONEM__MATRIX_READING_H_
