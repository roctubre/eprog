#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector(int length);
void printVector(double* vector, int length);
void insertionSort(double *x, int n);


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
    insertionSort(v, n);
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
    Sorts the given vector using the insertion sort algorithm.

    Complexity:
    - Best case: O(n) if already sorted
        * scans through unsorted part n-1 times => O(n)
        * no swaps necessary
    - Worst case: O(n^2) if in decreasing order
        * accumulated swaps = (n-1) + (n-2) + ... + 2 + 1 <=> n(n-1)/2 => O(n^2)
*/
void insertionSort(double* x, int n) {
    assert(n > 1);
    
    double s;           // holds first element in sorted part
    int unsorted_idx;   // index of unsorted vector
    int k;              // loop-variable which goes through the sorted vector backwards
    
    // loop through the unsorted part
    for (unsorted_idx = 1; unsorted_idx < n; ++unsorted_idx) {
        s = x[unsorted_idx];    // hold first element of unsorted part

        // starting from the last element in the sorted part, 
        // shift to the right until condition is reached
        for (k = unsorted_idx - 1; k >= 0 && x[k] > s; --k) {
            x[k + 1] = x[k];
        }
        x[k + 1] = s;
    }
}