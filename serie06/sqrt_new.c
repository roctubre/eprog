#include <stdio.h>
#include <math.h>
#include <assert.h>

/*
    Approximates the root of a positive number until it is below a specifix threshold (tau).
*/
double sqrtNew(double x, double tau) {
    assert(x > 0);
    assert(tau > 0);

    // initialize first and second elements of the sequence
    double x_current = (1 + x) / 2;
    double x_next = (x_current + x/x_current) / 2;

    // calculate next element of the sequence until below threshold
    while ((fabs(x_current - x_next) / fabs(x_current) > tau) && fabs(x_current) > tau) {
        x_current = x_next;
        x_next = (x_current + x/x_current) / 2;
    }

    return x_current;
}

int main() {
    double x = 0;
    double tau = 0;
    double result = 0;
    double reference = 0;

    // get input
    printf("x: "); scanf("%lf", &x);
    printf("tau: "); scanf("%lf", &tau);

    // get root approximation and reference
    result = sqrtNew(x, tau);
    reference = sqrt(x);

    // outputs
    printf("Approx.: %lf\n", result);
    printf("Reference: %lf\n", reference);
    printf("Error: %lf\n", fabs(result - reference));
}