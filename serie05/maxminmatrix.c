#include <stdio.h>

/*
    Find and fix the error. Maximum says 5 -> it should be 6.
    Additionaly, extend the program to find the minimum value.
*/
int main() {
    double A[2][3] = { {1,2,3},{6,-4,5} };
    double max = A[0][0];
    double min = A[0][0];   // Extension MIN

    int j=0, k=0;
    for(j=0; j<2; j=j+1) {
        
        //for(k=1; k<3; k=k+1) {    // BUG! Running index starts at 1 -> elements A[0][0] and A[1][0] are not processed.
        for(k=0; k<3; k=k+1) {      // Correct.
            if(A[j][k] > max) {
                max = A[j][k];
            }
            if(A[j][k] < min) {     // Extension MIN
                min = A[j][k];
            }
        }
    }

    printf("Maximum = %f\n", max);
    printf("Minimum = %f\n", min);  // Extension MIN
}

