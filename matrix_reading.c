//
// Created by pierre on 23.09.2021.
//
#include "matrix_reading.h"

int max (int i, int j) {
    if (i > j) {
        return i;
    } else {
        return j;
    }
}

int read_matrix (int n, double **A, int k, char *filename) {
    /* the program generates matrix using parameter k as defined in manual
     * Errors:
     * -1 - No file
     * -2 - Wrong data
     * -3 - Wrong k
     */
    if (k == 0) {
        // reading matrix from file
        FILE *input;
        input = fopen (filename, "r");
        if (input == NULL) {
            return -1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fscanf (input, "%lf", &(A[i][j])) <= 0) {
                    fclose (input);
                    return -2;
                };
            }
        }
        fclose (input);
    } else if (k < 0 || k > 4) {
        return -3;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = f (k, n, i, j);
            }
        }
    }
    return 0;
}

double f (int k, int n, int i, int j) {
    // the function required by p.5
    if (k == 1) {
        return n - max (i + 1, j + 1) + 1;
    } else if (k == 2) {
        return max (i + 1, j + 1);
    } else if (k == 3) {
        return abs (i - j);
    } else if (k == 4) {
        return (double) 1 / abs (i + j + 1);
    }
    return 0;
}