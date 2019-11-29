#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double  newton  (double (*f)(double), double (*fprime)(double), double x0, double tau);  // calculate an x-intercept
double  f       (double x);                                                              // arbitrary differentiable function
double  fprime  (double x);                                                              // derivative of func


int main() {
    double x0 = -3;
    double tau = 0.01;

    double result = newton(&f, &fprime, x0, tau);
    printf("Approximation: %lf\n", result);
}


/*
    Calculates a x-intercept of a function using the newton method.
*/
double newton(double (*f)(double), double (*fprime)(double), double x0, double tau) {
    assert(tau > 0);

    double xn = x0 - f(x0) / fprime(x0);

    while (!(fabs(fprime(xn)) <= tau ||                                                            // first or
          (fabs(f(xn)) <= tau && (fabs(xn - x0) <= (fabs(xn) <= tau ? tau : tau*fabs(xn)))))) {    // second condition
        x0 = xn;
        xn = x0 - f(x0) / fprime(x0);
    }

    if (fabs(f(xn)-f(x0)) <= tau) {
        printf("Warning: Numerical result might be wrong.\n");
    }

    return xn;
}


/*
    An arbitrary differentiable function to test the newton method.
*/
double f(double x) {
    return pow(x, 2) + 3*x + 1;
    //return pow(x, 3) + 2*x + 2;
}

/*
    Returns the derivative of the func() function to test the newton method.
*/
double fprime(double x) {
    return 2*x + 3;
    //return 3*pow(x, 2) + 3;
}
