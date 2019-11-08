#include <stdio.h>
#include <assert.h>
#include <math.h>


/*
    Returns the whole number k with k <= sqrt(x) <= k+1
*/
int wurzelschranke(double x) {
    assert(x >= 0);
    return (int)pow(x, 1./2.);
}


int main() {
    double x = 0;

    // get input
    printf("x: "); scanf("%lf", &x);

    // function call and output
    printf("k: %d\n", wurzelschranke(x));
}

