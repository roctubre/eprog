#include <stdio.h>
#include <math.h>
#include <assert.h>

#define DBL_EPSILON 0.00001

int     cauchy      (int k);
int     almosteq    (double a, double b);

int main() {
    int k = 0;

    // get input
    printf("k: "); scanf("%d", &k);

    // function call and output
    printf("n: %d\n", cauchy(k));
}


/*
    Return the smallest number (n) so |b_n| <= 1/k.

    Definitions:
    b_n := (a_(n+1))/a_n - a_n/(a_(n-1))
    a_0 := 1
    a_1 := 1
    a_n := a_0 + a_1

    Testcases:
    k=1 => n=1
    k=2 => n=2
    k=6 => n=3  // 1.66 == 1.66 double comparison
    k=7 => n=4
    k=1870 => n=9
    k=1871 => n=10
*/
int cauchy(int k) {
    assert(k > 0);

    // initialize first three fibonacci elements
    double a_prev = 1;
    double a_n = 1;
    double a_next = a_prev + a_n;

    double b_n = a_next/a_n - a_n/a_prev;   // b_n = 1
    int n = 1;

    // loop until |b_n| <= 1/k
    while (fabs(b_n) > 1./k && !almosteq(b_n, 1./k)) {
        a_prev = a_n;
        a_n = a_next;
        a_next = a_prev + a_n;
        b_n = a_next/a_n - a_n/a_prev;
        ++n;
    }
    
    return n;
}


/*
    Determines whether two doubles are close enough to be considered equal.
    For example, 1.666667 == 1./6. gives FALSE and needs to be fixed.
    Returns True (1) or False (0).

    Implementation:
    Compares the difference of two numbers to a small enough epsilon with respect to their magnitude.
*/
int almosteq(double a, double b) {
    return (fabs(a - b) < (DBL_EPSILON * fabs(a + b)));
}
