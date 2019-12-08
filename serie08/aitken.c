#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double* aitken      (double* x, int length); // generates a faster converging sequence
double* sequence    (int length);            // sequence generator
double  f           ();                      // arbitrary differentiable function; edit for testing


int main() {
    int seqlen = 100;
    int i;

    // generate some sequence
    double* x = sequence(seqlen);

    // generate a faster converging sequence
    double* y = aitken(x, seqlen); // len(y) = len(x) - 2

    // output x and y for comparison;
    for (i = 0; i < seqlen - 2; ++i) {
        printf("x[%d] = %lf | y[%d] = %lf\n", i, x[i], i, y[i]);
    }
}

/*
    Generates a sequence (y_n) which converges faster to x than (x_n).
    In case of a series x_n = q^n, where q is 0 < q < 1, the series y_n converges instantly to 0.
*/
double* aitken(double* x, int length) {
    assert(length >= 3);

    double* y = malloc((length - 2)*sizeof(double));
    int n;

    for (n = 0; n < length - 2; ++n) {
        y[n] = x[n] - pow(x[n + 1] - x[n], 2) / (x[n + 2] - 2*(x[n+1]) + x[n]);
    }

    return y;
}


/*
    Generates a converging sequence to test Aitken's delta-squared process.
*/
double* sequence(int length) {
    double* seq = malloc(length * sizeof(double));
    int x;
    for (x = 0; x <= length; ++x) {
        seq[x] = f(x);
    }
    return seq;
}


/*
    An arbitrary differentiable, converging function
*/
double f(int x) {
    //return (3*pow(x, 2)) / (pow(x, 2) + 1);   // converges to 3
    return pow(0.9, x);                       // q^n; if q < 1 then series converges to 0
    //return pow(1. + 1./x, x);                   // converges to Euler's number
}
