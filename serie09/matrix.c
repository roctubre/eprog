#include "matrix.h"


Matrix* newMatrix(int m, int n) {
    assert(m > 0 && n > 0);

    Matrix* mat = malloc(sizeof(Matrix));
    mat->data = malloc((m*n)*sizeof(double));
    mat->m = m;
    mat->n = n;

    // initialize matrix elements to zero
    int i;
    for (i = 0; i < m*n; ++i) {
        mat->data[i] = 0;
    }

    return mat;
}


Matrix* delMatrix(Matrix* A) {
    free(A->data);
    A->data = NULL;
    free(A);
    A = NULL;
    return A;
}


void printMatrix(Matrix* A) {
    int j, k;
    printf("{");
    for (j = 0; j < A->m; ++j) {
        printf(j == 0 ? "{" : ",\n{");
        for (k = 0; k < A->n; ++k) {
            printf(k == 0 ? "%lf" : ", %lf", A->data[j + k*A->m]);
        }
        printf("}");
    }
    printf("}\n");
}


int getMatrixM(Matrix* A) {
    return A->m;
}


int getMatrixN(Matrix* A) {
    return A->n;
}


double getMatrixEntry(Matrix* A, int j, int k) {
    assert(0 <= j && j < A->m);
    assert(0 <= k && k < A->n);
    return A->data[j + k*A->m];
}


void setMatrixEntry(Matrix* A, int j, int k, double x) {
    assert(0 <= j && j < A->m);
    assert(0 <= k && k < A->n);
    A->data[j + k*A->m] = x;
}


double frobeniusNorm(Matrix* A) {
    double sum = 0;
    int idx = (A->m)*(A->n) - 1;    // start from last element
    for (; idx >= 0; --idx) {       // get squared sum over all elements
        sum += A->data[idx] * A->data[idx];
    }
    return sqrt(sum);
}