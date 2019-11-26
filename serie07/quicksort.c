#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector      (int length);
void    printVector     (double* vector, int length);
void    quickSort       (double* x, int n);


int main() {
    double* v = NULL;
    int n = 0;

    // input vector
    printf("n = "); scanf("%d", &n);
    v = scanVector(n);

    // print and sort vector
    printVector(v, n);      // before
    quickSort(v, n);
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
    Sorts a given vector using the quicksort algorithm (recursive function).
    https://www.youtube.com/watch?v=cnzIChso3cc

    Complexity:
    - Wort case: O(n^2)
        * if pivot is always smallest or greatest element (already sorted asc/desc)
        * n-1 recursion calls => O(n)
        * n comparisons each recursion level => O(n)
        * O(n) * O(n) => O(n^2)
    - Best case: O(n*log(n))
        * if pivot is always middle element
        * log_2(n) recursion calls => O(log(n))
        * n comparisons/swaps each recursion level => O(n)
        * O(log(n)) * O(n) => O(n*log(n))
    - Average case: O(n*log(n))
        * ToDo
*/
void quickSort(double* x, int n) {
    if (n <= 1) return;                     // only continue if element count > 1

    int j, k;
    for (j = 0, k = 1; k < n; ++k) {
        if (x[k] < x[0]) {                  // compare to pivot, swap values
            ++j;
            if (k == j) continue;
            x[j] = x[j] + x[k];
            x[k] = x[j] - x[k];
            x[j] = x[j] - x[k];
        }
    }

    // swap pivot and last lesser element
    if (j > 0) {
        x[0] = x[0] + x[j];
        x[j] = x[0] - x[j];
        x[0] = x[0] - x[j];
    }

    quickSort(x, j++);          // sort lesser part
    quickSort(x + j, n - j);    // sort greater part; x + j is a pointer to the first greater element
}