#include <stdio.h>
#include <math.h>
#include <assert.h>


/*
    Returns the smallest exponent (n) of a base (r) which 
    makes r^n larger then a given number (c)
*/
int power(double r, double c) {
    // validate variables
    assert(r > 1.);
    assert(c > 0.);

    int n = 0;  // exponent

    // increase exponent until r^n > c
    for(; pow(r, n) <= c; ++n);
    
    return n;
}


int main() {
    double r = 0;
    double c = 0;

    // get input
    printf("r: "); scanf("%lf", &r);
    printf("C: "); scanf("%lf", &c);

    // function call and output
    printf("Exponent: %d\n", power(r, c));
}

