//
// Created by pierre on 23.09.2021.
//
#include "matrix_inversion.h"

int inverse_matrix (int n, double ***A, double ***X) {
    /* inverses the matrix A and writes result to X
     * n is the size of the matrices
     * Errors:
     * -1 - matrix is singular
     */
    *X = (double **) malloc (n * sizeof (double **));
    for (int i = 0; i < n; ++i) {
        (*X)[i] = (double *) malloc (n * (sizeof (double *)));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                (*X)[i][j] = 1;
            } else {
                (*X)[i][j] = (*X)[j][i] = 0;
            }
        }
    }
    double **B; // copy of matrix A for editing
    B = (double **) malloc (n * sizeof (double **));
    for (int i = 0; i < n; ++i) {
        B[i] = (double *) malloc (n * (sizeof (double *)));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            B[i][j] = (*A)[i][j];
        }
    }
    // Gauss's method
    int *r = (int *) malloc (n * sizeof (int *)); // this is row renumeration by Gauss method
    for (int i = 0; i < n; ++i) {
        r[i] = i;
    }
    for (int k = 0; k < n; ++k) {
        // this iteration is a step of Gauss algorithm
        int t = -1;
        for (int j = 0; j < n; ++j) {
            if (B[k][j] != 0) {
                // swapping the renumeration
                t = r[k];
                r[k] = r[j];
                r[j] = t;
                break;
            }
        }
        if (t == -1) {
            for (int i = 0; i < n; ++i) {
                free ((*X)[i]);
            }
            free (*X);
            free (r);
            return -1;
        }
        for (int i = 0; i < n; ++i) {
            B[i][r[k]] /= B[k][r[k]];
            (*X)[i][r[k]] /= B[k][r[k]];
        }
        for (int j = k; j < n; ++j) {
            double head_row = B[k][j];
            for (int i = 0; i < n; ++i) {
                B[i][r[j]] -= B[i][r[j]] * head_row;
                (*X)[i][r[j]] -= B[i][r[j]] * head_row;
            }
        }
    }
    
    // going backwards
    for (int k = n - 1; k >= 0; --k) {
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < n; ++i) {
                B[i][r[j]] -= B[i][r[k]];
                (*X)[i][r[j]] -= B[i][r[k]];
            }
        }
    }
    
    // cleaning
    for (int i = 0; i < n; ++i) {
        free (B[i]);
    }
    free (B);
    free (r);
    return 0;
}
