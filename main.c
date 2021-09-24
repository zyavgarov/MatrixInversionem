#include <stdio.h>
#include "matrix_reading.c"
#include "matrix_inversion.c"
void show_matrix (int n, int m, double **X);

int main () {
    int n; // size of matrix
    int m; // number of output numbers of matrix
    int k; // number of formula for matrix initialisation
    char *filename; // name of file with matrix
    int err; // error indicator
    double **A = NULL; // matrix to inverse
    double **X = NULL; // result of inversion
    err = read_matrix (n, A, k, filename);
    // ERROR HADLER TO BE DONE
    err = inverse_matrix (n, A, X);
    // ERROR HADLER TO BE DONE
    show_matrix (n, m, X);
    free (A);
    return 0;
}

void show_matrix (int n, int m, double **X) {
    /* shows first m strings of matrix X
     * if m == 0 shows time and index of false
     * if m == -1 only matrix X is shown
     */
}