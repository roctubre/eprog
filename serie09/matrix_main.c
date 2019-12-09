/* 
    HOW TO COMPILE and RUN:
    1. Compile matrix object-code (create .o file)
        gcc -c matrix.c
    2. Compile main + object file
        gcc matrix_main.c matrix.o -o matrix
    3. Execute (Windows)
        ./matrix.exe
*/

#include "matrix.h"

int main() {
    int m = 3;
    int n = 5;

    Matrix* mat = newMatrix(m, n);
    setMatrixEntry(mat, 0, 0, 5);
    setMatrixEntry(mat, 1, 3, 3);
    setMatrixEntry(mat, 2, 0, 4);
    printMatrix(mat);

    printf("### Frobeniusnorm: %lf\n", frobeniusNorm(mat));

    // Shallow and deep copy
    printf("\n### TEST SHALLOW/DEPP COPY ###\n");
    
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


    // cleanup
    s_copy->data = NULL;
    delMatrix(mat);
    delMatrix(s_copy);
    delMatrix(d_copy);
}
