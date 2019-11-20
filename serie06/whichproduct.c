#include <stdio.h>

#define N 3

void initLeviCivita(double x[]);
void whichProduct(double a[N], double b[N], double c[N]);


int main() {
    double a[3] = {1,2,3};      // vector A
    double b[3] = {-1,-2,-3};   // vector B
    double c[3] = {0,0,0};      // result vector C
    
    whichProduct(a, b, c);
    printf("Result: {%lf, %lf, %lf}\n", c[0], c[1], c[2]);
}

/*
    Given vectors a and b, the a product is calculated using the Levi-Civita Symbols
    and returned by reference with vector c.

    Which product is being calculated?
    - Cross product of two vectors
*/
void whichProduct(double a[N], double b[N], double c[N]) {
    int i, j, k;
    double levi[N*N*N];
    initLeviCivita(levi);

    // set result vector to 0
    for(i = 0; i < N; ++i) {
        c[i] = 0;
    }

    // Calculates a summed product with Levi-Civity symbol
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            for(k = 0; k < N; ++k) {
                printf("%lf += %lf * %lf * %lf\n", c[i], levi[i + j*N + k*N*N], a[j], b[k]);
                c[i] += levi[i + j*N + k*N*N] * a[j] * b[k];
            }
        }
    }
}

/*
    Initialize Levi-Civita Symbols by reference
*/
void initLeviCivita(double x[N*N*N]) {
    int i, j, k, l;

    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            for(k = 0; k < N; ++k) {
                l = i + j*N + k*N*N;
                if((i == 0 && j == 1 && k == 2) ||
                   (i == 1 && j == 2 && k == 0) ||
                   (i == 2 && j == 0 && k == 1)) {
                    x[l] = 1;
                }
                else if((i == 2 && j == 1 && k == 0) ||
                        (i == 0 && j == 2 && k == 1) ||
                        (i == 1 && j == 0 && k == 2)) {
                    x[l] = -1;
                }
                else
                {
                    x[l] = 0;
                }
            }
        }
    }
}