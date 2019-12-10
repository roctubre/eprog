/* 
    HOW TO COMPILE and RUN:
    1. Compile matrix object-code (create .o file)
        gcc -c matrix.c
    2. Compile main + object file
        gcc matrixMatrix.c matrix.o -o matrixMatrix
    3. Execute (Windows)
        ./matrixMatrix.exe
*/

#include "matrix.h"

void test_ex96_matrixMatrix();

int main() {
    test_ex96_matrixMatrix();
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
    printf("Product:\n");
    printMatrix(product);

    delMatrix(mat1);
    delMatrix(mat2);
    delMatrix(product);
}
