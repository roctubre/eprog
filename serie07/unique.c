#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector(int length);
void printVector(double* vector, int length);
void unique(double* x, int* n);


int main() {
    double* v = NULL;
    int* n = malloc(sizeof(int));

    // input vector size
    printf("n = "); 
    scanf("%d", n);

    // create vector
    v = scanVector(*n);

    // print and sort vector
    printVector(v, *n);      // before
    unique(v, n);
    printVector(v, *n);      // after

    // cleanup
    free(v);
    free(n);
    v = NULL;
    n = NULL;
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
    Sorts a given vector using the mergesort algorithm.
    Implemented using a recursive approach.

    Complexity (Worst Case): O(n*log(n))
    - n = number of elements, l = level of recursion
    - vector is split on every call -> number of recursion levels (depth) = log2(n)
    - each recursion level has 2^l mergeSort calls, and each call has n/(2^l) merges
    - since on each level (2^l)*(n/(2^l)) = n merges occur and merging is linear => O(n) per level
    - recursion levels times O(n) = log2(n) * O(n) => O(n*log(n))
*/
void mergeSort(double* x, int start, int len) {
    if(len == 2) {
        if(x[start] > x[start + 1]) {
            //swap
            x[start] = x[start] + x[start + 1];
            x[start + 1] = x[start] - x[start + 1];
            x[start] = x[start] - x[start + 1];
        }
    }
    else if (len > 2){
        int left_start = start;                         // starting index of the left subvector
        int left_len = len / 2;                         // length of the left subvector
        int right_start = left_start + left_len;        // starting index of the right subvector
        int right_len = len - left_len;                 // length of the right subvector
        int l, r, i;                                    // loop variables

        double* sorted = malloc(len*sizeof(double));    // helper vector to sort left and right subvectors

        // split vector and left and right and apply mergeSort

        mergeSort(x, left_start, left_len);
        mergeSort(x, right_start, right_len);

        l = left_start;
        r = right_start;
        i = 0;

        // merge left and right into temporary vector
        while (l < left_start + left_len && r < right_start + right_len) {
            sorted[i++] = x[l] < x[r] ? x[l++] : x[r++];
        }

        // append remaining elements into temporary vector, if any
        while (l < left_start + left_len) {
            sorted[i++] = x[l++];
        }
        while (r < right_start + right_len) {
            sorted[i++] = x[r++];
        }

        // put sorted vector into original array
        for(i = 0; i < len; ++i) {
            x[start + i] = sorted[i];
        }

        // cleanup
        free(sorted);
        sorted = NULL;
    }
}

/* 
    Sorts and overwrites a vector with unique occuring elements.
*/
void unique(double* x, int* n) {
    // sort first before removing duplicates
    mergeSort(x, 0, *n);

    int i, j;
    for (i = 1, j = 1; i < *n && j < *n; ++i) {
        // replace duplicates with next largest elements
        for (; j < *n; ++j) {
            if (x[i-1] < x[j]) {
                x[i] = x[j];
                break;
            }
        }

        // break loop if no unique elements found
        if (x[i-1] == x[i]) {   
            break;
        }

        // adjust array size if traversing index (j) reached end
        if (j >= *n) --i;       
    }
    *n = i;
}