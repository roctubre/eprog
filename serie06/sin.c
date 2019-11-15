#include <stdio.h>
#include <math.h>
#include <assert.h>

int     factorial   (int n);
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
    printf("Error: %lf\n", fabs(result - reference));
    if (reference != 0) {
        printf("Relative Error: %lf\n", fabs(result - reference)/fabs(reference));
    }
}


/*
    Returns the factorial of a given number with a recursive approach.
*/
int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}


/*
    Approximates the sine of a number x until it reaches a specific threshold (epsilon).
    Value x represents an angle expressed in radians.
*/
double sinNew(double x, double epsilon) {
    assert(epsilon > 0);

    int k = 2;
    double sum_prev = x;                    // first partialsum when k = 0
    double sum = sum_prev + -pow(x, 3) / 6; // second partialsum when k = 1
    
    while(fabs(sum - sum_prev)/fabs(sum) > epsilon && fabs(sum) > epsilon) {
        sum_prev = sum;
        sum += pow(-1, k) * pow(x, 2*k + 1) / factorial(2*k + 1);
        ++k;
    }

    return sum;
}