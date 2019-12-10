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


Vector* matrixVector(Matrix* A, Vector* x);
Vector* transposedMatrixVectorProduct(Matrix* A, Vector* x);
void test_ex97_matrixVector();
void test_ex98_transposed();


int main() {
    test_ex97_matrixVector();
    test_ex98_transposed();
}


void test_ex97_matrixVector() {
    printf("\n### TEST MATRIX-VECTOR PRODUCT ###\n");
    int m = 2;
    int n = 3;

    Matrix* mat = newMatrix(m, n);      // Dim: (2,3)
    Vector* vec = newVector(n);         // Dim: (3,)
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
    product = matrixVector(mat, vec);   // Dim: (2,3) x (3,) = (2,)

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

/*
    Return the matrix-vector product y = Ax.
    Complexity: O(mn)
*/
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


void test_ex98_transposed() {
    printf("\n### TEST TRANSPOSED MATRIX-VECTOR PRODUCT ###\n");
    int m = 3;
    int n = 2;

    Matrix* mat = newMatrix(m, n);      // Dim: (3,2)
    Vector* vec = newVector(m);         // Dim: (3,)
    Vector* product = NULL;

    setMatrixEntry(mat, 0, 0, 1);
    setMatrixEntry(mat, 1, 0, 2);
    setMatrixEntry(mat, 2, 0, 3);
    setMatrixEntry(mat, 0, 1, 4);
    setMatrixEntry(mat, 1, 1, 5);
    setMatrixEntry(mat, 2, 1, 6);
    setVectorEntry(vec, 0, 1);
    setVectorEntry(vec, 1, 2);
    setVectorEntry(vec, 2, 3);
    product = transposedMatrixVectorProduct(mat, vec);  // Dim: (3,2)^T x (3,) = (2,)

    printf("Matrix A:\n");
    printMatrix(mat);
    printf("Vector X:\n");
    printVector(vec);
    printf("Product (A^T)x:\n");
    printVector(product);

    delMatrix(mat);
    delVector(vec);
    delVector(product);
}


/*
    Return the transpoed matrix-vector product y = (A^T)x.
    Complexity: O(mn)
*/
Vector* transposedMatrixVectorProduct(Matrix* A, Vector* x) {
    assert(A != NULL && x != NULL);
    assert(A->m > 0 && A->n > 0);
    assert(x->n > 0);
    assert(A->m == x->n);
    printf("HERE I AM...\n");
    int m = A->m;
    int n = A->n;
    int j, k;
    Vector* product = newVector(n);
    
    for (k = 0; k < n; ++k) {
        for (j = 0; j < m; ++j) {
            setVectorEntry( product, k,
                            getVectorEntry(product, k) +
                            getMatrixEntry(A, j, k) * getVectorEntry(x, j));
        }
    }

    return product;
}