#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector(int length);
void printVector(double* vector, int length);
void mergeSort(double *x, int len);


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
    mergeSort(v, n);
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
    Prints out a given vector.
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
    Sorts a given vector using the mergesort algorithm.
    Implemented using a recursive approach.

    Complexity: O(n*log(n))
    - n = number of elements, l = level of recursion
    - vector is split on every call -> number of recursion levels (depth) = log2(n)
    - each recursion level has 2^l mergeSort calls, and each call has n/(2^l) merges
    - since on each level (2^l)*(n/(2^l)) = n merges occur and merging is linear => O(n) per level
    - recursion levels times O(n) = log2(n) * O(n) => O(n*log(n))
*/
void mergeSort(double* x, int len) {
    if(len == 2) {
        if(x[0] > x[1]) {
            //swap
            x[0] = x[0] + x[1];
            x[1] = x[0] - x[1];
            x[0] = x[0] - x[1];
        }
    }
    else if (len > 2){
        double *left_ptr = x;                           // pointer to left subvector
        int left_len = len / 2;                         // length of the left subvector
        double *right_ptr = x + left_len;               // pointer to right subvector
        int right_len = len - left_len;                 // length of the right subvector
        int l, r, i;                                    // loop variables

        double* sorted = malloc(len*sizeof(double));    // helper vector to merge left and right subvectors

        // split vector and left and right and apply mergeSort
        mergeSort(left_ptr, left_len);
        mergeSort(right_ptr, right_len);

        l = 0;
        r = 0;
        i = 0;

        // merge left and right into temporary vector
        while (l < left_len && r < right_len) {
            sorted[i++] = left_ptr[l] < right_ptr[r] ? left_ptr[l++] : right_ptr[r++];
        }

        // append remaining elements into temporary vector, if any
        while (l < left_len) {
            sorted[i++] = left_ptr[l++];
        }
        while (r < right_len) {
            sorted[i++] = right_ptr[r++];
        }

        // put sorted vector into original array
        for(i = 0; i < len; ++i) {
            x[i] = sorted[i];
        }

        // cleanup
        free(sorted);
        sorted = NULL;
    }
}