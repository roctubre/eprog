#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double  diff        (double (*f)(double), double x, double h0, double tau);
double  diffaitken  (double (*fct)(double), double x, double h0, double tau);
double  f           (double x);


int main() {
    double x = 1;
    double h0 = 0.01;
    double tau = 10e-7;
    printf("With Aitken:\n");
    printf("Approximation: %lf\n\n", diffaitken(&f, x, h0, tau));
    printf("Without Aitken:\n");
    printf("Approximation: %lf\n", diff(&f, x, h0, tau));
}

/*
    Approximates the derivative of a function on a given x value in combination with
    Aitken's delta-squared process.
*/
double diffaitken(double (*fct)(double), double x, double h0, double tau) {
    assert(tau > 0 && h0 > 0);
    
    int n = 1;
    double h_n = pow(2, -n) * h0;               // h_(n)
    double h_m = pow(2, -(++n)) * h0;           // h_(n+1)
    double h_l = pow(2, -(++n)) * h0;           // h_(n+2)
    double phi_n = (f(x + h_n) - f(x)) / h_n;   // Phi(h_(n))
    double phi_m = (f(x + h_m) - f(x)) / h_m;   // Phi(h_(n+1))
    double phi_l = (f(x + h_l) - f(x)) / h_m;   // Phi(h_(n+2))
    double y_n = 0;
    double y_m = phi_n - pow(phi_m - phi_n, 2) / (phi_l - 2 * phi_m + phi_n);

    while (!(fabs(y_n - y_m) <= (fabs(y_m) <= tau ? tau : tau*fabs(y_m)))) {
        h_n = h_m;
        h_m = h_l;
        h_l = pow(2, -(++n)) * h0;
        phi_n = phi_m;
        phi_m = phi_l;
        phi_l = (f(x + h_m) - f(x)) / h_m;
        y_n = y_m;
        y_m = phi_n - pow(phi_m - phi_n, 2) / (phi_l - 2 * phi_m + phi_n);

        printf("h_(n+1): %lf, |y_(n) - y_(n+1)|: %0.12lf, y_(n+1): %lf\n", h_m, fabs(y_n - y_m), y_n);
    }
    
    return y_m;
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

    while (!(fabs(phi_n - phi_m) <= (fabs(phi_n <= tau ? tau : tau*fabs(phi_n))))) {
        h_n = h_m;
        h_m = pow(2, -(++n)) * h0;
        phi_n = phi_m;
        phi_m = (f(x + h_m) - f(x)) / h_m;
        printf("h_(n+1): %lf, |phi_(n) - phi_(n+1)|: %0.12lf, phi_(n+1): %lf\n", h_m, fabs(phi_n - phi_m), phi_n);
    }

    return phi_n;
}


/*
    An arbitrary differentiable, converging function
*/
double f(double x) {
    //return (3*pow(x, 2) + 3*x + 1);
    return exp(x);
    //return pow(1. + 1./x, x);
}
