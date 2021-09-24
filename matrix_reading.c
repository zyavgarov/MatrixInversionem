//
// Created by pierre on 23.09.2021.
//

#include <malloc.h>
#include <stdlib.h>

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
    A = (double **) malloc (n * sizeof (double **));
    // MORE ACCURATE MEMORY CONSUMPTION AND CLEANING NEEDED
    // ALSO MALLOC FOR EVERY A[i] needs to be added
    if (k == 0) {
        // reading matrix from file
        FILE *input;
        int err;
        input = fopen (filename, "r");
        if (input == NULL) {
            free (A);
            return -1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (fscanf (input, "%lf", &A[i][j]) <= 0) {
                    fclose (input);
                    free (A);
                    return -2;
                };
            }
        }
        fclose (input);
    } else if (k == 1) {
        // that branch and three next are using formulae to fill the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = n - max (i, j) + 1;
            }
        }
    } else if (k == 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = max (i, j);
            }
        }
    } else if (k == 3) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = abs (i - j);
            }
        }
    } else if (k == 4) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = (double) 1 / abs (i + j - 1);
            }
        }
    } else {
        return 0; // WRONG K. EXIT ACTIONS TO BE DONE
    }
}