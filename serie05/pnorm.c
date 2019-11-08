#include <stdio.h>
#include <math.h>

#define N_SIZE 3    // Vector dimension


/*
    Returns the p-norm of a vector.

    OBSERVATION:
    The larger p is, the closer it gets to the maximum 
    absolute value of the vector.
*/
double pnorm(double x[N_SIZE], double p) {
    double sum = 0;
    int i;

    for(i = 0; i < N_SIZE; ++i) {
        sum += pow(fabs(x[i]), p);
    }
    
    return pow(sum, 1./p);
}


int main() {
    double x[N_SIZE];
    double p = 0.;
    int i;

    // get input x
    for (i = 0; i < N_SIZE; ++i) {
        printf("x_%d: ", i);
        scanf("%lf", &x[i]);
    }
    // get input p
    printf("p: "); 
    scanf("%lf", &p);

    // function call and output
    printf("pnorm(x, p) = %lf\n", pnorm(x, p));
}

