//
// Created by pierre on 23.09.2021.
//

#include <malloc.h>

int inverse_matrix (int n, double **A, double **X) {
    /* inverses the matrix A and writes result to X
     * n is the size of the matrices
     * Errors:
     * -1 - matrix is singular
     */
    X = (double **) malloc (n * sizeof (double **));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                A[i][j] = 1;
            } else {
                A[i][j] = A[j][i] = 0;
            }
        }
    }
    // Gauss's method
    int *r = (int *) malloc (n * sizeof (int *)); // this is row renumeration by Gauss method
    for (int i = 0; i < n; ++i) {
        r[i] = i;
    }
    for (int k = 0; k < n; ++k) {
        // the iteration is a step of Gauss algorithm
        int t = -1;
        for (int j = 0; j < n; ++j) {
            if (A[k][j] != 0) {
                // swapping the renumeration
                t = r[k];
                r[k] = r[j];
                r[j] = t;
                break;
            }
        }
        if (t == -1) {
            free (X);
            free (r);
            return -1;
        }
        for (int i = 0; i < n; ++i) {
            A[i][r[k]] /= A[k][r[k]];
            X[i][r[k]] /= A[k][r[k]];
        }
        for (int j = k; j < n; ++j) {
            double head_row = A[k][j];
            for (int i = 0; i < n; ++i) {
                A[i][r[j]] -= A[i][r[j]] * head_row;
                X[i][r[j]] -= A[i][r[j]] * head_row;
            }
        }
    }
    // going backwards
    for (int k = n - 1; k >= 0; --k) {
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < n; ++i) {
                A[i][r[j]] -= A[i][r[k]];
                X[i][r[j]] -= A[i][r[k]];
            }
        }
    }
    free (r);
    return 0;
}
