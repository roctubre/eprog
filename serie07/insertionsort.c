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
    Sorts the given vector by splitting it into a sorted and unsorted part.

    Implementation: 
    Uses an index variable to keep track of the start of the unsorted part.
*/
void insertionSort(double* x, int n) {
    assert(n > 1);
    
    int unsorted_idx;   // index of unsorted vector
    int k;              // loop-variable which goes through the sorted vector backwards
    
    // loop through the unsorted part
    for (unsorted_idx = 1; unsorted_idx < n; ++unsorted_idx) {
        // loop backwards the sorted part
        // keep swapping k-th and (k-1)-th elements until k > k-1 or k == 0
        for (k = unsorted_idx; k > 0; --k) {
            if (x[k] > x[k-1]) break;

            // swap elements
            x[k] = x[k] + x[k-1];
            x[k-1] = x[k] - x[k-1];
            x[k] = x[k] - x[k-1];
        }
    }
}