#include <stdio.h>

/*
    Calculates and returns the k-th fibonacci element using a for loop.
    Time complexity is O(n) compared to a recursive approach O(2^n).
*/
int fibonacci(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;

    int n_1 = 0;
    int n_2 = 1;

    // gets the elements (k-1) and (k-2)
    for (int i = 2; i < k; ++i) {
        n_2 += n_1;
        n_1 = n_2 - n_1;
    }

    return n_1 + n_2;
}

int main() {
    int k = 0;
    
    // get input
    printf("k: "); scanf("%d", &k);
    
    // validate input
    if (k < 0) {
        printf("k must be greater than 0");
        return 0;
    }

    // OUTPUT RESULTS
    printf("Fibonacci k-th element: %d\n", fibonacci(k));

}