#include <stdio.h>
#include <math.h>

#define DIMENSION_M 2
#define DIMENSION_N 3

/*
    Calculates the Frobenius norm of a matrix.
    It is the square root of the squared sum of all elements.
*/
double frobeniusnorm(double matrix[DIMENSION_M][DIMENSION_N]) {
    double sum = 0;     // sum of squared elements

    // iterate through matrix elements
    for (int j = 0; j < DIMENSION_M; ++j) {
        for (int k = 0; k < DIMENSION_N; ++k) {
            sum += pow(matrix[j][k], 2);
        }
    }

    // return square root of the sum
    return sqrt(sum);
}

int main() {
    double matrix[DIMENSION_M][DIMENSION_N];
    
    // initialize elements of matrix
    printf("MATRIX SIZE: %d x %d\nInput Elements:\n", DIMENSION_M, DIMENSION_N);
    for (int j = 0; j < DIMENSION_M; ++j) {
        for (int k = 0; k < DIMENSION_N; ++k) {
            printf("[%d,%d] = ", j, k); 
            scanf("%lf", &matrix[j][k]);
        }
    }

    // output frobenius norm
    printf("Frobenius norm: %lf\n", frobeniusnorm(matrix));
}