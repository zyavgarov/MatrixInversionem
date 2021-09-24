#include <stdio.h>
#include "matrix_reading.h"
#include "matrix_inversion.h"
#include <time.h>
#include <math.h>
void show (int n, int m, double ***A, double ***X, double time);

void show_matrix (int m, int n, double ***A);

double norm (int n, double ***A);

int main (int argc, char **argv) {
    
    /* Errors:
     * -1 - Not enpugh arguments
     * -2 - Could not read filename
     * -3 - Extra or lack of arguments
     * -4 - File not found
     * -5 - Incorrect data in file
     * -6 - The matrix is singular
     */
    
    int n; // size of matrix
    int m; // number of output numbers of matrix
    int k; // number of formula for matrix initialisation
    char *filename = NULL; // name of file with matrix
    int err; // error indicator
    double **A = NULL; // matrix to inverse
    double **X = NULL; // result of inversion
    clock_t begin = clock ();
    if (argc < 4) {
        printf ("Not enough arguments provided\n");
        return -1;
    }
    n = atoi (argv[1]);
    m = atoi (argv[2]);
    k = atoi (argv[3]);
    if (k == 0) {
        if (argc == 5) {
            filename = argv[4];
        } else {
            printf ("Could not read filename\n");
            return -2;
        }
    }
    err = read_matrix (n, &A, k, filename);
    if (err == -1) {
        printf ("File not found\n");
        return -4;
    } else if (err == -2) {
        printf ("Incorrect data in file\n");
        return -5;
    } else if (err == -3) {
        printf ("Extra or lack of arguments\n");
    }
    err = inverse_matrix (n, &A, &X);
    if (err == -1) {
        printf ("The matrix is singular\n");
        return -6;
    }
    clock_t end = clock ();
    show (n, m, &A, &X, (double) (end - begin) / CLOCKS_PER_SEC);
    for (int i = 0; i < n; ++i) {
        free (A[i]);
    }
    free (A);
    return 0;
}

void show (int n, int m, double ***A, double ***X, double time) {
    /* shows first m strings of matrix X
     * if m == 0 shows time and index of false
     * if m == -1 only matrix X is shown
     */
    if (m == -1) {
        show_matrix (n, n, X);
    } else {
        double **S; // A*X - E
        S = (double **) malloc (n * sizeof (double **));
        for (int i = 0; i < n; ++i) {
            S[i] = (double *) malloc (n * sizeof (double *));
            // computing the line
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    S[i][j] = -1;
                } else {
                    S[i][j] = 0;
                }
                for (int k = 0; k < n; ++k) {
                    S[i][j] += (*A)[i][k] * (*X)[k][j];
                }
            }
        }
        if (m == 0) {
            printf ("Error: %lf\n", norm (0, &S));
            printf ("Time: %10.3e\n", time);
        } else {
            printf ("Time: %10.3lf\n", time);
            printf ("Matrix A:\n");
            show_matrix (m, n, A);
            printf ("Matrix A^(-1)\n");
            show_matrix (m, n, X);
            printf ("Error: %lf\n", norm (n, &S));
        }
        for (int i = 0; i < n; ++i) {
            free (S[i]);
        }
        free (S);
    }
}

double norm (int n, double ***A) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += (*A)[i][j] * (*A)[i][j];
        }
    }
    return sqrt (sum);
}

void show_matrix (int m, int n, double ***A) {
    int m_ = m;
    if (m > n) {
        m_ = n;
    }
    for (int i = 0; i < m_; ++i) {
        for (int j = 0; j < n; ++j) {
            printf ("  %10.3lf", (*A)[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}