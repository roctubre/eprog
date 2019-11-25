#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector      (int length);
void    printVector     (double* vector, int length);
double* subVector       (double* x, int length, int cpystart, int cpylength);
void    merge           (double* a, int a_len, double* b, int b_len, double* x, int* x_len);
void    mergeSort       (double* x, int* len);
void    unique          (double* x, int* n);


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
     Copies a part of a given vector into another memory and returns a pointer to it.
*/
double* subVector(double* x, int length, int cpystart, int cpylength) {
    assert(cpystart + cpystart <= length);

    double* vector = malloc(cpylength*sizeof(double));
    int i;

    for (i = 0; i < cpylength; ++i) {
        vector[i] = x[cpystart + i];
    }

    return vector;
}

/*
    Merges two sorted vectors into one sorted vector with unique elements.
*/
void merge(double* a, int a_len, double* b, int b_len, double* x, int* x_len) {
    int l = 0;      // loop variable for left vector
    int r = 0;      // loop variable for right vector
    int i = 0;      // tracks length of vector with unique elements

    // merge left and right into sorted vector
    while (l < a_len && r < b_len) {
        x[i] = a[l] < b[r] ? a[l++] : b[r++]; 

        for (;a[l] <= x[i] && l < a_len; ++l);  // increase left index until unique element
        for (;b[r] <= x[i] && r < b_len; ++r);  // increase right index until unique element  

        i++;
    }

    // append remaining unique elements into temporary vector, if any
    for (; l < a_len; ++l) {
        if (x[i-1] < a[l]) {
            x[i++] = a[l];
        }
    }
    for (; r < b_len; ++r) {
        if (x[i-1] < b[r]) {
            x[i++] = b[r];
        }
    }

    *x_len = i;     // new length of vector with unique elements
}

/*
    Sorts a given vector using the mergesort algorithm.
    Implemented using a recursive approach.
*/
void mergeSort(double* x, int* len) {
    if(*len == 2) {
        if(x[0] > x[1]) {
            //swap
            x[0] = x[0] + x[1];
            x[1] = x[0] - x[1];
            x[0] = x[0] - x[1];
        }
    }
    else if (*len > 2){
        int left_start = 0;                             // starting index of the left subvector
        int* left_len = malloc(sizeof(int)); 
        *left_len = *len / 2;                            // length of the left subvector
        int right_start = left_start + *left_len;        // starting index of the right subvector
        int* right_len = malloc(sizeof(int)); 
        *right_len = *len - *left_len;                   // length of the right subvector

        // create sub vectors
        double* left = subVector(x, *len, left_start, *left_len);
        double* right = subVector(x, *len, right_start, *right_len);

        // split vector and left and right and apply mergeSort
        mergeSort(left, left_len);
        mergeSort(right, right_len);

        // merge and sort sub vectors into original vector
        merge(left, *left_len, right, *right_len, x, len);

        // cleanup
        free(left);
        free(right);
        free(left_len);
        free(right_len);
        left = NULL;
        right = NULL;
        left_len = NULL;
        right_len = NULL;
    }
}

/* 
    Sorts and overwrites a vector with unique occuring elements.
    Complexity: O(n*log(n))
*/
void unique(double* x, int* n) {
    // modified mergeSort to only merge unique elements
    mergeSort(x, n);
}