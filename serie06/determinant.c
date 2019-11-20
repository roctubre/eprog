#include <stdio.h>

#define N 3

void initLeviCivita(double x[]);
double determinant(double a[N*N]);
double delta(double a[N*N]);


int main() {
    double a[9] = {1,2,3,4,5,6,7,2,1};
    
    printf("Determinant: %lf\n", determinant(a));
    printf("Delta: %lf\n", delta(a));
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


/*
    Calculates and returns the determinant of a 3x3 matrix using the Rule of Sarrus
*/
double determinant(double a[N*N]) {
    return a[0 + 0*N]*a[1 + 1*N]*a[2 + 2*N] +
           a[1 + 0*N]*a[2 + 1*N]*a[0 + 2*N] +
           a[2 + 0*N]*a[0 + 1*N]*a[1 + 2*N] -
           a[0 + 2*N]*a[1 + 1*N]*a[2 + 0*N] -
           a[1 + 2*N]*a[2 + 1*N]*a[0 + 0*N] -
           a[2 + 2*N]*a[0 + 1*N]*a[1 + 0*N];
}


/*
    Calculates and returns some delta with the levi-civita symbol

    What can you observe?
    - It also calculates the determinant of the 3x3 matrix
*/
double delta(double a[N*N]) {
    int i, j, k;
    double delta = 0;
    double levi[N*N*N];
    initLeviCivita(levi);

    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            for(k = 0; k < N; ++k) {
                delta += levi[i + j*N + k*N*N] * a[i*N] * a[1 + j*N] * a[2 + k*N];
            }
        }
    }

    return delta;
}
