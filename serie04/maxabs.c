#include <stdio.h>

#define N_SIZE 3

double maxabs(double x[N_SIZE]);

int main() {
    double x[N_SIZE];
    int i;

    // get input
    for (i = 0; i < N_SIZE; ++i) {
        printf("x_%d: ", i);
        scanf("%lf", &x[i]);
    }

    // function call and output
    printf("maxabs(x) = %lf", maxabs(x));
}

/*
    Returns the first element with the maximum absolute value in a vector
*/
double maxabs(double x[N_SIZE]) {
    double max = x[0];
    int i;

    for(i = 1; i < N_SIZE; ++i) {
        if (x[i]*x[i] > max*max) {
            max = x[i];
        }
    }

    return max;
}

