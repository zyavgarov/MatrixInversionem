//
// Created by pierre on 23.09.2021.
//
#include "matrix_inversion.h"
#include "misc.h"

int inverse_matrix (int n, double **A, double **X) {
    /* inverses the matrix A and writes result to X
     * n is the size of the matrices
     * Errors:
     * -1 - matrix is singular
     */
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                X[i][j] = 1;
            } else {
                X[i][j] = X[j][i] = 0;
            }
        }
    }
    
    // Gauss's method
    for (int k = 0; k < n; ++k) {
        // this iteration is a step of Gauss algorithm
        for (int j = k; j < n; ++j) {
            if (fabs (A[k][j]) >= fabs (A[k][k])) {
                // swapping the renumeration
                for (int i = 0; i < n; ++i) {
                    double d = A[i][k];
                    A[i][k] = A[i][j];
                    A[i][j] = d;
                    d = X[i][k];
                    X[i][k] = X[i][j];
                    X[i][j] = d;
                }
            }
        }
        if (is_0 (A[k][k])) {
            return -1;
        }
        double head_row = A[k][k];
        for (int i = 0; i < n; ++i) {
            A[i][k] /= head_row;
            X[i][k] /= head_row;
        }
        for (int j = k + 1; j < n; ++j) {
            double head_row_in = A[k][j];
            for (int i = 0; i < n; ++i) {
                A[i][j] -= A[i][k] * head_row_in;
                X[i][j] -= X[i][k] * head_row_in;
            }
        }
    }
    
    // going backwards
    for (int k = n - 1; k >= 0; --k) {
        for (int j = 0; j < k; ++j) {
            double head_row = A[k][j];
            for (int i = 0; i < n; ++i) {
                A[i][j] -= A[i][k] * head_row;
                X[i][j] -= X[i][k] * head_row;
            }
        }
    }
    return 0;
}