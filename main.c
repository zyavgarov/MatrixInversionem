#include "matrix_inversion.h"
#include <time.h>

int main (int argc, char **argv) {
    
    /* Errors:
     * -1 - Not enpugh arguments
     * -2 - Could not read filename
     * -3 - Extra or lack of arguments
     * -4 - File not found
     * -5 - Incorrect data in file
     * -6 - The matrix is singular
     * -7 - m is too small
     * -8 - n is too small
     */
    
    int n; // size of matrix
    int m; // number of output numbers of matrix
    int k; // number of formula for matrix initialisation
    char *filename = NULL; // name of file with matrix
    int err; // error indicator
    double **A = NULL; // matrix to inverse
    double **X = NULL; // result of inversion
    if (argc < 4) {
        printf ("Not enough arguments provided\n");
        return -1;
    }
    n = atoi (argv[1]);
    m = atoi (argv[2]);
    k = atoi (argv[3]);
    
    // Check whether arguments are appropriate
    if (k == 0) {
        if (argc == 5) {
            filename = argv[4];
        } else {
            printf ("Could not read filename\n");
            return -2;
        }
    }
    if (m < -1) {
        printf ("m is too small. It must be equal or greater than -1\n");
        return -7;
    }
    if (n < 1) {
        printf ("n is too small. It must be equal or greater than 1\n");
        return -8;
    }
    
    // Memory reserve
    A = (double **) malloc (n * sizeof (double *));
    for (int i = 0; i < n; ++i) {
        A[i] = (double *) malloc (n * sizeof (double));
    }
    X = (double **) malloc (n * sizeof (double **));
    for (int i = 0; i < n; ++i) {
        X[i] = (double *) malloc (n * (sizeof (double *)));
    }
    
    err = read_matrix (n, &A, k, filename);
    if (err == -1) {
        printf ("File not found\n");
        clean_memory (&A, &X, n);
        return -4;
    } else if (err == -2) {
        printf ("Incorrect data in file\n");
        clean_memory (&A, &X, n);
        return -5;
    } else if (err == -3) {
        printf ("Extra or lack of arguments\n");
        clean_memory (&A, &X, n);
    }
    
    clock_t begin = clock ();
    err = inverse_matrix (n, &A, &X);
    clock_t end = clock ();
    if (err == -1) {
        printf ("The matrix is singular\n");
        clean_memory (&A, &X, n);
        return -6;
    }
    show (n, m, k, filename, &A, &X, (double) (end - begin) / CLOCKS_PER_SEC);
    
    clean_memory (&A, &X, n);
    return 0;
}
