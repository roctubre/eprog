#include <stdio.h>
#include <math.h>
#include <assert.h>

#define PI 3.1419

double  sinNew      (double x, double epsilon);

int main() {
    double x = 0;
    double epsilon = 0;
    double result = 0;
    double reference = 0;

    // get input
    printf("x: "); scanf("%lf", &x);
    printf("epsilon: "); scanf("%lf", &epsilon);

    // get sin(x) approximation and reference
    result = sinNew(x, epsilon);
    reference = sin(x);

    // outputs
    printf("Approx.: %lf\n", result);
    printf("Reference: %lf\n", reference);
    printf("Absolute Error: %lf\n", fabs(result - reference));
    if (fabs(reference) > 0.00001) {
        printf("Relative Error: %lf\n", fabs(result - reference)/fabs(reference));
    }
}


/*
    Approximates the sine of a number x until it reaches a specific threshold (epsilon).
    Value x represents an angle expressed in radians.
*/
double sinNew(double x, double epsilon) {
    assert(epsilon > 0);

    // make 0 <= x < 2*PI
    while(x > 2*PI) {
        x -= 2*PI;
    }
    while(x <= 0) {
        x += 2*PI;
    }

    // initialize variables
    double sum_prev = x;                    // first partialsum when k = 0
    double sum = sum_prev + -pow(x, 3) / 6; // second partialsum when k = 1
    int k = 2;

    // loop variables
    double term = 1;
    int i;

    while(fabs(sum - sum_prev)/fabs(sum) > epsilon && fabs(sum) > epsilon) {
        // calculate term, avoid factorial by dividing manually
        term = pow(-1, k) * pow(x, 2*k + 1);
        for(i = (2*k + 1); i > 0; --i) {
            term /= i;
        }

        // update partial sums
        sum_prev = sum;
        sum += term;
        ++k;
    }

    return sum;
}