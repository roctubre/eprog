#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector(int length);
void printVector(double* vector, int length);
void selectionSort(double* x, int n);


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
    selectionSort(v, n);
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
    Sorts a given vector using the Minsort-Algorithm from the lecture (page 77).

    Complexity:
    - O(n^2) for all cases
    - Best case:
        * scans vector n-times (outer loop) => O(n)
        * accumulated comparisons (inner loop) = (n-1) + (n-2) + ... + 2 + 1 <=> n(n-1)/2 => O(n^2)
        * no swaps
        * O(n) + O(n^2) => O(n^2)
    - Worst case:
        * scans vector n-times (outer loop) = O(n)
        * accumulated comparisons (inner loop) = (n-1) + (n-2) + ... + 2 + 1 <=> n(n-1)/2 => O(n^2)
        * O(n) + O(n^2) = O(n^2)
*/
void selectionSort(double* x, int n) {
    int i, j, min_idx;
    assert(n > 0);
    
    for (i = 0; i < n; ++i) {
        min_idx = i;

        // find minimum from x[i+1] to x[n-1]
        for (j = i + 1; j < n; ++j) {
            if (x[j] < x[min_idx]) {
                min_idx = j;
            }
        }

        // swap elements
        if (min_idx != i) {
            x[i] = x[i] + x[min_idx];
            x[min_idx] = x[i] - x[min_idx];
            x[i] = x[i] - x[min_idx];
        }
    }
}