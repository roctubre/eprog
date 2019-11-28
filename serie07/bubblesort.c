#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector(int length);
void printVector(double* vector, int length);
void bubbleSort(double *x, int n);


int main() {
    double* v = NULL;
    int n = 0;

    // input vector size
    printf("n = "); 
    scanf("%d", &n);

    // create vector
    v = scanVector(n);

    // print and sort vector
    printVector(v, n);      // before
    bubbleSort(v, n);
    printVector(v, n);      // after

    // cleanup
    free(v);
    v = NULL;
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
    Sorts the given vector using the bubble sort algorithm.

    Complexity: O(n^2), full number of comparisons
    - Best case *WITH* break condition: O(n) if already sorted
        * compares once n-1 times => O(n)
        * no swaps
    - Worst case: O(n^2) if in decreasing order
        * accumulated comparisons (inner loop) = (n-1) + (n-2) + ... + 2 + 1 <=> n(n-1)/2 => O(n^2)
        * accumulated swaps = (n-1) + (n-2) + ... + 2 + 1 <=> n(n-1)/2 => O(n^2)
        * O(n^2) + O(n^2) => O(n^2) 
*/
void bubbleSort(double* x, int n) {
    int last_idx;
    int changes;
    int j;

    for (last_idx = n - 1; last_idx > 0; --last_idx) {
        changes = 0;
        for (j = 0; j < last_idx; ++j) {
            if (x[j] > x[j + 1]) {          // swap values
                x[j] = x[j] + x[j + 1];
                x[j+1] = x[j] - x[j+1];
                x[j] = x[j] - x[j+1];
                changes = 1;                // change occured
            }
        }

        if (!changes) break;                // break if no changes
    }
}