#include <stdio.h>

#define N_SIZE 3    // Vector dimension


/*
    Returns the scalar produkt of two vectors
*/
double skalarprodukt(double x[N_SIZE], double y[N_SIZE]) {
    double sum = 0;
    int i;

    for (i = 0; i < N_SIZE; ++i) {
        sum += x[i]*y[i];
    }
    
    return sum;
}


int main() {
    double x[N_SIZE];
    double y[N_SIZE];
    int i;

    // get input x
    for (i = 0; i < N_SIZE; ++i) {
        printf("x_%d: ", i);
        scanf("%lf", &x[i]);
    }
    // get input y
    for (i = 0; i < N_SIZE; ++i) {
        printf("y_%d: ", i);
        scanf("%lf", &y[i]);
    }

    // function call and output
    printf("skalarprodukt(x, y) = %lf\n", skalarprodukt(x, y));
}

