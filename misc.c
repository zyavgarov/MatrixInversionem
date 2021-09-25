//
// Created by pierre on 25.09.2021.
//

#include "misc.h"

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

double norm (int n, double ***A) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += (*A)[i][j] * (*A)[i][j];
        }
    }
    return sqrt (sum);
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
            printf ("Time: %10.3lf\n", time);
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

int is_0 (double x) {
    // returns 1 if the diference between x and 0 is less than EPS
    // EPS defined in misc.h
    // otherwise returns 0
    if (x < EPS && x > -EPS) {
        return 1;
    } else {
        return 0;
    }
}