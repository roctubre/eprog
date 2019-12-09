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

/*  
    EXERCISE 9.4
    Return the Frobeniusnorm 
    Complexity: O(m*n)
*/
double      frobeniusNorm   (Matrix* A);

/*  
    EXERCISE 9.5
    Create a shallow copy of a matrix. 
    A shallow copy only copies members of an object, but not the objects 
    pointed to by those members.
*/
Matrix*     shallowCopy     (Matrix* A);

/*  
    EXERCISE 9.5
    Create a complete copy of a matrix including data from dynamic allocated memory.
*/
Matrix*     deepCopy        (Matrix* A);

/*
    EXERCISE 9.6
    Return the matrix-matrix-product of two matrices.
*/
Matrix*     matrixMatrix    (Matrix* A, Matrix* B);


#endif