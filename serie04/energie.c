#include <stdio.h>

#define N_SIZE 3

double energie(double x[N_SIZE]);

int main() {
    double x[N_SIZE];
    int i;

    // get input
    for (i = 0; i < N_SIZE; ++i) {
        printf("x_%d: ", i);
        scanf("%lf", &x[i]);
    }

    // function call and output
    printf("e = %lf", energie(x));
}

/*
    Returns the sum of the squared vector elements
*/
double energie(double x[N_SIZE]) {
    double sum = 0;
    int i;

    for(i = 0; i < N_SIZE; ++i) {
        sum += x[i] * x[i];
    }

    return sum;
}

