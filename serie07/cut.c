#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector      (int length);
void    printVector     (double* vector, int length);
void    cut             (double* x, int* n, double cmin, double cmax);


int main() {
    double cmin = 0;
    double cmax = 0;
    double* v = NULL;
    int* n = malloc(sizeof(int));

    // input vector, min, max
    printf("n = "); scanf("%d", n);
    v = scanVector(*n);
    printf("cmin = "); scanf("%lf", &cmin);
    printf("cmax = "); scanf("%lf", &cmax);

    // print and sort vector
    printVector(v, *n);      // before
    cut(v, n, cmin, cmax);
    printVector(v, *n);      // after

    // cleanup
    free(v);
    free(n);
    v = NULL;
    n = NULL;
}

/*
    Creates a vector of given size. Values are provided by the user.
    Returns a pointer to the allocated memory.
*/
double* scanVector(int length) {
    double* vector = NULL;
    int i = 0;
    assert(length > 0);

    vector = malloc(length*sizeof(double));
    assert(vector != NULL);
    for (i = 0; i < length; ++i) {
        printf("vector[%d] = ", i);
        scanf("%lf", &vector[i]);
    }

    return vector;
}

/*
    Prints out the given vector.
*/
void printVector(double* vector, int length) {
    int i = 0;
    assert(length > 0);

    printf("Vector = {%lf", vector[0]);
    for (i = 1; i < length; ++i) {
        printf(", %lf", vector[i]);
    }
    printf("}\n");
}

/*
    Removes all elements from a vector which are outside of a given range.

    cmin ... lower bound
    cmax ... upper bound
*/
void cut(double* x, int* n, double cmin, double cmax) {
    assert(cmin <= cmax);

    int len = 0;
    int i;

    for (i = 0; i <= *n; ++i) {
        if (cmin <= x[i] & x[i] <= cmax) {
            x[len++] = x[i];
        }
    }

    *n = len;
}