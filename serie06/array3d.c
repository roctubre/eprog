/*
    Task:
    Save a 3d-Array into a 1D array.

    Let M, N, P be the three dimensions of an array,
    Let i, j, k be the indeces in their respective dimension of a specific element in the 3d array.

    Formula for the index (l) in the 1D array:
    l = M*i + N*j + P*k
    
    Explanation:
    We declase a 1D array with the size of M*N*P. 
    Divide the 1D array into M blocks. Each M block contains N*P elements.
    Divide each M block into N blocks. Each N block contains P elements.
    Divide each N block into P blocks. Each P block is one element.
    To get a specific element, we muliply the dimensions with the elements indeces from the 3D array.
*/

#include <stdio.h>

#define M 3
#define N 3
#define P 3

/*
    Initializes the Levi-Civita symbol into a 1D array.
*/
int main() {
    double x[M*N*P];
    int i, j, k, l;

    for(i = 0; i < M; ++i) {
        for(j = 0; j < M; ++j) {
            for(k = 0; k < M; ++k) {
                l = M*i + N*j + P*k;
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
