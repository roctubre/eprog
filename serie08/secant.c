#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double  secant  (double (*f)(double), double x0, double x1, double tau);    // calculate an x-intercept
double  f       (double x);                                                 // arbitrary differentiable function


int main() {
    double x0 = -3;
    double x1 = -2;
    double tau = 0.0001;

    double result = secant(&f, x0, x1, tau);
    printf("Approximation: %lf\n", result);
}


/*
    Calculates a x-intercept of a function using the secant method.
*/
double secant(double (*f)(double), double x0, double x1, double tau) {
    assert(tau > 0);

    double xn = x1 - f(x1)*((x0-x1)/(f(x0) - f(x1)));       // x_2

    while (!(fabs(f(xn)-f(x1)) <= tau ||                                                           // first or
          (fabs(f(xn)) <= tau && (fabs(xn - x1) <= (fabs(xn) <= tau ? tau : tau*fabs(xn)))))) {    // second condition
        x0 = x1;                                    // x_(n-2)
        x1 = xn;                                    // x_(n-1)
        xn = x1 - f(x1)*((x0-x1)/(f(x0) - f(x1)));  // x_(n)
    }

    if (fabs(f(xn)-f(x1)) <= tau) {
        printf("Warning: Numerical result might be wrong.\n");
    }

    return xn;
}


/*
    An arbitrary differentiable function to test the secant method.
*/
double f(double x) {
    return pow(x, 2) + 3*x + 1;      // triggers second condition of secant method
    //return pow(x, 2) + 3*x + 2;      // triggers first condition of secant method
}