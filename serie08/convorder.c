#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

void    convorder       (double* xn, int N, double x);
double* generateSeries  (double (*f)(double), int n);
double  f               (double x);


int main() {
    int n = 100;
    double *xn = generateSeries(&f, n);

    convorder(xn, n, xn[n-1]);

    // cleanup
    free(xn);
    xn = NULL;
}

/*
    Given a series xn and a limit x, the the convergence rate (p, c) is calculated.
    p ... exponential growth (e.g.: 1 = linear, 2 = quadratic, 3 = cubic, ...)
    c ... constant
*/
void convorder(double* xn, int N, double x) {
    int i;
    double p, c;

    for (i = 0; i < N-2; ++i) {
        p = log(fabs(xn[i + 2] - x)/fabs(xn[i + 1] - x)) / log(fabs(xn[i + 1] - x)/fabs(xn[i] - x));
        c = fabs(xn[i + 2] - x) / fabs(xn[i + 1] - x);
        printf("x[%d] = %lf | p = %lf | c = %lf\n", i, xn[i], p, c);
    }
}


/*
    Generates a series of a given function for test purpose.
*/
double* generateSeries(double (*f)(double), int n) {
    double* xn = malloc(n*sizeof(double));
    int i;
    for (i = 0; i < n; ++i) {
        xn[i] = f(i);
    }
    return xn;
}


/*
    An arbitrary converging function. Change as necessary.
*/
double f(double x) {
    //return pow(1. + 1./(x + 1), (x + 1));
    return 5*pow(1./(x+1), 2);
    //return pow()
}
