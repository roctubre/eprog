#include <stdio.h>
#include <math.h>

#define N_SIZE 3

/*
    Calculates the geometric mean of a vector
*/
double geometricMean(double x[]) {
    double mean = pow(x[0], 1./N_SIZE);
    int i;

    for (i = 1; i < N_SIZE; ++i) {
        mean *= pow(x[i], 1./N_SIZE);
    }

    return mean;
}

int main() {
    double x[N_SIZE];
    int i;

    // get input
    for (i = 0; i < N_SIZE; ++i) {
        printf("x_%d: ", i); scanf("%lf", &x[i]);
        // validate
        if (x[i] < 0) {
            printf("input must be >= 0");
            return;
        }
    }

    // function call and output
    printf("Geometric mean: %lf\n", geometricMean(x));
}
