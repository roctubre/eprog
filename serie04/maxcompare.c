#include <stdio.h>

#define N_SIZE 3

double  max         (double x[N_SIZE]);
int     maxcompare  (double a[N_SIZE], double b[N_SIZE]);

int main() {
    double a[N_SIZE];
    double b[N_SIZE];
    int i;

    // get input a
    for (i = 0; i < N_SIZE; ++i) {
        printf("a_%d: ", i);
        scanf("%lf", &a[i]);
    }
    // get input b
    for (i = 0; i < N_SIZE; ++i) {
        printf("b_%d: ", i);
        scanf("%lf", &b[i]);
    }

    // function call and output
    printf("maxcompare(a, b) = %d\n", maxcompare(a, b));
}

/*
    Returns the maximum element of a vector
*/
double max(double x[N_SIZE]) {
    double max = x[0];
    int i;

    for(i = 1; i < N_SIZE; ++i) {
        if (x[i] > max) {
            max = x[i];
        }
    }

    return max;
}

/*
    Returns the number of occurences in which the maximum element of vector a and b occur
    in the same position. If the maximums of the vectors are different, zero occurences are returned.
*/
int maxcompare(double a[N_SIZE], double b[N_SIZE]) {
    double a_max = max(a);
    double b_max = max(b);
    int i;
    int count = 0;

    if(a_max != b_max) return 0;

    for(i = 0; i < N_SIZE; ++i) {
        if (a[i] == a_max && a[i] == b[i]) {
            count++;
        }
    }

    return count;
}