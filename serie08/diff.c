#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double  diff    (double (*f)(double), double x, double h0, double tau);  // calculates f'(x)
double  f       (double x);                                              // arbitrary differentiable function
double  fprime  (double x);                                              // reference for derivative approximation
double  test    (double x, double h0, double tau);                       // tester function


int main() {
    double x = 0;
    double h0 = 0.1;
    double tau = 0.0001;
    test(x, h0, tau);

    //double result = diff(&f, x, h0, tau);
    //printf("Approximation: %lf\n", result);
}


/*
    Output the derivatives (slopes) from x-3 to x+3 for test purpose.
*/
double test(double x, double h0, double tau) {
    double k;

    for (k = x - 3; k <= x + 3; k += 0.1) {
        printf("x = %.02lf, Slope Approx.: %lf, Slope Ref.: %lf\n", k, diff(&f, k, h0, tau), fprime(k));
    }
}


/*
    Approximates the derivative of a function on a given x value.
*/
double diff(double (*f)(double), double x, double h0, double tau) {
    assert(tau > 0 && h0 > 0);

    int n = 1;
    double h_n = pow(2, -n) * h0;               // h_(n)
    double h_m = pow(2, -(++n)) * h0;           // h_(n+1)
    double phi_n = (f(x + h_n) - f(x)) / h_n;   // Phi(h_(n))
    double phi_m = (f(x + h_m) - f(x)) / h_m;   // Phi(h_(n+1))

    while (!(fabs(phi_n - phi_m) <= (fabs(phi_n) <= tau ? tau : tau*fabs(phi_n)))) {
        h_n = h_m;
        h_m = pow(2, -(++n)) * h0;
        phi_n = phi_m;
        phi_m = (f(x + h_m) - f(x)) / h_m;
    }

    return phi_n;
}


/*
    An arbitrary differentiable function f(x) to approximate the derivative for.
*/
double f(double x) {
    //return pow(x, 2) + 3*x + 1; // x^2 + 3*x + 1
    return pow(x, 3) + 3*pow(x, 2) + 1; // x^3 + 3*x^2 + 1
}


/*
    Calculates the real derivative f'(x) as reference.
*/
double fprime(double x) {
    //return 2*x + 3;           // derivative of x^2 + 3*x + 1 => 2*x + 3
    return 3*pow(x, 2) + 6*x;   // derivative of x^3 + 3*x^2 + 1 => 3*x^2 + 6
}

