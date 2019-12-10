/* 
    HOW TO COMPILE and RUN:
    1. Compile matrix and vector object-code (create .o file)
        gcc -c matrix.c
    2. Compile main + object file
        gcc matrix_main.c matrix.o -o matrix
    3. Execute (Windows)
        ./matrix.exe
*/

#include "matrix.h"

void test_ex93();
void test_ex94_frobenius();
void test_ex95_copy();
void test_ex96_matrixMatrix();

int main() {
    test_ex93();
    test_ex94_frobenius();
    test_ex95_copy();
    test_ex96_matrixMatrix();
}

void test_ex93() {
    printf("### TEST BASIC MATRIX FUNCTIONALITY ###\n");
    int m = 3;
    int n = 5;

    Matrix* mat = newMatrix(m, n);
    setMatrixEntry(mat, 0, 0, 5);
    setMatrixEntry(mat, 1, 3, 3);
    setMatrixEntry(mat, 2, 0, 4);
    printMatrix(mat);

    delMatrix(mat);
    mat = NULL;
}

void test_ex94_frobenius() {
    printf("### TEST FROBENIUSNORM ###\n");
    int m = 3;
    int n = 5;

    Matrix* mat = newMatrix(m, n);
    setMatrixEntry(mat, 0, 0, 5);
    setMatrixEntry(mat, 1, 3, 3);
    setMatrixEntry(mat, 2, 0, 4);
    printMatrix(mat);

    printf("Frobeniusnorm: %lf\n", frobeniusNorm(mat));

    delMatrix(mat);
    mat = NULL;
}

void test_ex95_copy() {
    int m = 3;
    int n = 5;

    Matrix* mat = newMatrix(m, n);
    setMatrixEntry(mat, 0, 0, 5);
    setMatrixEntry(mat, 1, 3, 3);
    setMatrixEntry(mat, 2, 0, 4);

    printf("\n### TEST SHALLOW/DEPP COPY\n");
    
    Matrix* s_copy = shallowCopy(mat);
    Matrix* d_copy = deepCopy(mat);
    
    printf("Set shallow copy at [0,0] to 999\n");
    setMatrixEntry(s_copy, 0, 0, 999);
    printf("Shallow Copy:\n");
    printMatrix(s_copy);
    printf("Original:\n");
    printMatrix(mat);

    printf("\nSet deep copy at [0,0] to 555\n");
    setMatrixEntry(d_copy, 0, 0, 555);
    printf("Deep Copy:\n");
    printMatrix(d_copy);
    printf("Original:\n");
    printMatrix(mat);

    s_copy->data = NULL;
    delMatrix(mat);
    delMatrix(s_copy);
    delMatrix(d_copy);
}

void test_ex96_matrixMatrix() {
    printf("\n### TEST MATRIX-MATRIX PRODUCT ###\n");
    int m = 2;
    int n = 3;
    int p = 2;

    Matrix* mat1 = newMatrix(m, p);
    Matrix* mat2 = newMatrix(p, n);
    Matrix* product = NULL;

    setMatrixEntry(mat1, 0, 0, 1);
    setMatrixEntry(mat1, 0, 1, 2);
    setMatrixEntry(mat1, 1, 0, 3);
    setMatrixEntry(mat1, 1, 1, 4);
    setMatrixEntry(mat2, 0, 0, 1);
    setMatrixEntry(mat2, 0, 1, 1);
    setMatrixEntry(mat2, 0, 2, 1);
    setMatrixEntry(mat2, 1, 0, 2);
    setMatrixEntry(mat2, 1, 1, 2);
    setMatrixEntry(mat2, 1, 2, 2);
    product = matrixMatrix(mat1, mat2);

    printf("Matrix A:\n");
    printMatrix(mat1);
    printf("Matrix B:\n");
    printMatrix(mat2);
    printf("Product AB:\n");
    printMatrix(product);

    delMatrix(mat1);
    delMatrix(mat2);
    delMatrix(product);
}
