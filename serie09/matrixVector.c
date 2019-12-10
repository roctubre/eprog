/* 
    HOW TO COMPILE and RUN:
    1. Compile matrix and vector object-code (create .o file)
        gcc -c vector.c
        gcc -c matrix.c
    2. Compile main + object file
        gcc matrixVector.c matrix.o vector.o -o matrixVector
    3. Execute (Windows)
        ./matrixVector.exe
*/

#include "matrix.h"
#include "vector.h"

void test_ex97_matrixVector();
Vector* matrixVector(Matrix* A, Vector* x);


int main() {
    test_ex97_matrixVector();
}


void test_ex97_matrixVector() {
    printf("\n### TEST MATRIX-VECTOR PRODUCT ###\n");
    int m = 2;
    int n = 3;

    Matrix* mat = newMatrix(m, n);
    Vector* vec = newVector(n);
    Vector* product = NULL;

    setMatrixEntry(mat, 0, 0, 1);
    setMatrixEntry(mat, 0, 1, 2);
    setMatrixEntry(mat, 0, 2, 3);
    setMatrixEntry(mat, 1, 0, 4);
    setMatrixEntry(mat, 1, 1, 5);
    setMatrixEntry(mat, 1, 2, 6);
    setVectorEntry(vec, 0, 1);
    setVectorEntry(vec, 1, 2);
    setVectorEntry(vec, 2, 3);
    product = matrixVector(mat, vec);

    printf("Matrix A:\n");
    printMatrix(mat);
    printf("Vector X:\n");
    printVector(vec);
    printf("Product Ax:\n");
    printVector(product);

    delMatrix(mat);
    delVector(vec);
    delVector(product);
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