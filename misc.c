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
        for (int j = 0; j < m_; ++j) {
            printf (" %10.3e", (*A)[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
}

void show (int n, int m, int k, char *filename, double ***A, double ***X, double time) {
    /* shows first m strings of matrix X
     * if m == 0 shows time and index of false
     * if m == -1 only matrix X is shown
     */
    if (m == -1) {
        show_matrix (n, n, X);
    } else {
        // Initializing A
        read_matrix (n, A, k, filename);
        
        // Error measure
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double cell;
                if (i == j) {
                    cell = -1;
                } else {
                    cell = 0;
                }
                for (int l = 0; l < n; ++l) {
                    cell += (*A)[i][l] * (*X)[l][j];
                }
                sum += pow (cell, 2);
            }
        }
        double norm = sqrt (sum);
        
        if (m == 0) {
            printf ("%10.3e\n", norm);
            printf ("%10.3e\n", time);
        } else {
            printf ("%10.3e\n", time);
            printf ("Matrix A:\n");
            show_matrix (m, n, A);
            printf ("Matrix A^(-1)\n");
            show_matrix (m, n, X);
            printf ("%10.3e\n", norm);
        }
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

void clean_memory (double ***A, double ***X, int n) {
    for (int i = 0; i < n; ++i) {
        free ((*A)[i]);
    }
    free (*A);
    for (int i = 0; i < n; ++i) {
        free ((*X)[i]);
    }
    free (*X);
}