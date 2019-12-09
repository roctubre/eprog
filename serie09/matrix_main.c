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

    printf("Frobeniusnorm: %lf", frobeniusNorm(mat));
    
    // cleanup
    delMatrix(mat);
}
