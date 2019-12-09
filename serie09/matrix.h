#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// declaration of datatype Matrix
typedef struct matrix {
    double* data;
    int m;
    int n;
} Matrix;

// Create new zero'd MxN matrix
Matrix*     newMatrix       (int m, int n);

// free up memory; sets pointer to NULL
Matrix*     delMatrix       (Matrix* A);

// print out matrix to console
void        printMatrix     (Matrix* A);

// returns the row count
int         getMatrixM      (Matrix* A);

// return the column count
int         getMatrixN      (Matrix* A);

// return a matrix element
double      getMatrixEntry  (Matrix* A, int j, int k);

// sets a matrix element
void        setMatrixEntry  (Matrix* A, int j, int k, double x);

// returns the Frobeniusnorm (EXERCISE 9.4)
// Complexity: O(m*n)
double      frobeniusNorm   (Matrix* A);


#endif