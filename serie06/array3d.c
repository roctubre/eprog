/*
    Task:
    Save a 3d-Array columnwise into a 1D array.

    Let M, N, P be the three dimensions of an array,
    Let i, j, k be the indeces in their respective dimension of a specific element in the 3d array.

    Formula for the index (l) in the 1D array:
    l = i + j*M + k*M*N = i + M*(j + N*k)
    
    Explanation:
    Elements are saved depths-wise, then column wise in the 1D vector.
*/

#include <stdio.h>

#define M 3
#define N 3
#define P 3

double frobeniusNorm(double x[], int m, int n, int p);

/*
    Initializes the Levi-Civita symbol into a 1D array.
*/
int main() {
    double x[M*N*P];
    int i, j, k, l;

    for(i = 0; i < M; ++i) {
        for(j = 0; j < N; ++j) {
            for(k = 0; k < P; ++k) {
                l = i + j*M + k*M*N;
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
                printf("x[%d][%d][%d] = [%.0lf]\n", i, j, k, x[l]);
            }
        }
    }
}

/*
    Calculates the frobenius norm of an array with dimensions M*N*P.
    The array is given as a 1D vector array. Time complexity is O(M*N*P).

    Complexity assumption: 
    Given an N^3 array, with N = 10^2 and a resulting runtime of 1 second, 
    calculate the runtime with N = 10^3.
    
    With N = 10^3, one must divide (10^3)^3 by (10^2)^3 = 10^3.
    The resulting runtime is 1000 seconds (16 min 40 s).
*/
double frobeniusNorm(double x[], int m, int n, int p) {
    double sum = 0;
    int i;

    for (i = 0; i < m*n*p; ++i) {
        sum += x[i] * x[i];
    }
    
    return sqrt(sum);
}