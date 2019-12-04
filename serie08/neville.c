#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double  neville (double* x, double* y, int n, double t);


int main(){
    int n=4;
    double x[4] = {-3, -1, 0, 2};    // f(x) = x^2 + 2x + 1
    double y[4] = {4, 0, 1, 9};
    double t = -5;

    printf("p(t)= %f", neville(x, y, n, t));    // evaluate f(-5) = 16
}


/*
    Neville's method evaluates a polynomial that passes through a given set of x and y points 
    for a particular value (t). It does not require to explicitly find the polynomial interpolation.
*/
double neville(double* x, double* y, int n, double t) {
    double *mat = malloc((n*n) * sizeof(double));
    int j=0;    // row
    int m=0;    // column
    double result = 0;
    
    // copy y-values to first column of matrix
    for (j = 0; j < n; ++j) {
        mat[j] = y[j];
    }

    // complete matrix according to Neville's method
    for (m = 1; m < n; ++m) {
        for (j = 0; j < (n - m); ++j) {
            mat[j + m*n] =  ((t - x[j])*mat[(j + 1) + (m - 1)*n] - (t - x[j + m])*mat[j + (m - 1)*n]) /
                            (x[j + m] - x[j]);
        }
    }

    // p(t) = last element of first row
    result = mat[(n-1)*n];

    // cleanup
    free(mat);
    mat = NULL;

    return result;
}
