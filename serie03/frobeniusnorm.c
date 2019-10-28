#include <stdio.h>
#include <math.h>

#define DIMENSTION_M 2
#define DIMENSTION_N 3

/*
    Calculates the Frobenius norm of a matrix.
    It is the square root of the squared sum of all elements.
*/
double frobeniusnorm(double matrix[DIMENSTION_M][DIMENSTION_N]) {
    double sum = 0;     // sum of squared elements

    // iterate through matrix elements
    for (int j = 0; j < DIMENSTION_M; ++j) {
        for (int k = 0; k < DIMENSTION_N; ++k) {
            sum += pow(matrix[j][k], 2);
        }
    }

    // return square root of the sum
    return sqrt(sum);
}

int main() {
    double matrix[DIMENSTION_M][DIMENSTION_N];
    
    // initialize elements of matrix
    printf("MATRIX SIZE: %d x %d\nInput Elements:\n", DIMENSTION_M, DIMENSTION_N);
    for (int j = 0; j < DIMENSTION_M; ++j) {
        for (int k = 0; k < DIMENSTION_N; ++k) {
            printf("[%d,%d] = ", j, k); 
            scanf("%lf", &matrix[j][k]);
        }
    }

    // output frobenius norm
    printf("Frobenius norm: %lf\n", frobeniusnorm(matrix));
}