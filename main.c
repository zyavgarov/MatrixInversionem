#include "matrix_reading.h"
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
