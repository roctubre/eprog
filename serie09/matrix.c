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
    assert(A != NULL);
    if (A->data != NULL) {
        free(A->data);
    }
    free(A);
    return NULL;
}


void printMatrix(Matrix* A) {
    assert(A != NULL);

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
    assert(A != NULL);
    return A->m;
}


int getMatrixN(Matrix* A) {
    assert(A != NULL);
    return A->n;
}


double getMatrixEntry(Matrix* A, int j, int k) {
    assert(A != NULL);
    assert(0 <= j && j < A->m);
    assert(0 <= k && k < A->n);
    return A->data[j + k*A->m];
}


void setMatrixEntry(Matrix* A, int j, int k, double x) {
    assert(A != NULL);
    assert(0 <= j && j < A->m);
    assert(0 <= k && k < A->n);
    A->data[j + k*A->m] = x;
}


double frobeniusNorm(Matrix* A) {
    assert(A != NULL);

    double sum = 0;
    int idx = (A->m)*(A->n) - 1;    // start from last element
    for (; idx >= 0; --idx) {       // get squared sum over all elements
        sum += A->data[idx] * A->data[idx];
    }
    return sqrt(sum);
}


Matrix* shallowCopy(Matrix* A) {
    assert(A != NULL);

    Matrix* copy = malloc(sizeof(Matrix));
    copy->data = A->data;
    copy->m = A->m;
    copy->n = A->n;

    return copy;
}


Matrix* deepCopy(Matrix* A) {
    assert(A != NULL);

    Matrix* copy = newMatrix(A->m, A->n);

    if (A->data != NULL) {
        int i;
        for (i = 0; i < (A->m*A->n); ++i) {
            copy->data[i] = A->data[i];
        }
    }
    else {
        free(copy->data);
        copy->data = NULL;
    }

    return copy;
}


Matrix* matrixMatrix(Matrix* A, Matrix* B) {
    assert(A != NULL && B != NULL);
    assert(A->m > 0 && A->n > 0);
    assert(B->m > 0 && B->n > 0);
    assert(A->n == B->m);

    int m = A->m;
    int n = B->n;
    int p = A->n;
    int j, k, x;
    Matrix* product = newMatrix(m, n);

    for (j = 0; j < m; ++j) {
        for (k = 0; k < n; ++k) {
            for (x = 0; x < p; ++x) {
                setMatrixEntry( product, j, k, 
                                getMatrixEntry(product, j, k) + 
                                getMatrixEntry(A, j, x) * getMatrixEntry(B, x, k));
            }
        }
    }

    return product;
}


Vector* matrixVector(Matrix* A, Vector* x) {
    assert(A != NULL && x != NULL);
    assert(A->m > 0 && A->n > 0);
    assert(x->n > 0);
    assert(A->n == x->n);

    int m = A->m;
    int n = A->n;
    int j, k;
    Vector* product = newVector(m);
    
    for (j = 0; j < m; ++j) {
        for (k = 0; k < n; ++k) {
            setVectorEntry( product, j,
                            getVectorEntry(product, j) +
                            getMatrixEntry(A, j, k) * getVectorEntry(x, k));
        }
    }

    return product;
}