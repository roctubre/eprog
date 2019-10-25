#include <stdio.h>

/*
    Calculates and returns the k-th fibonacci element using a for loop.
    Time complexity is O(n) compared to a recursive approach O(2^n).
*/
int fibonacci(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;

    int prev = 0;    // (n-1)-th fib element
    int curr = 1;    // (n)-th fib element

    // gets the elements (k) and (k-1)
    for (int n = 2; n <= k; ++n) {
        curr += prev;
        prev = curr - prev;
    }

    return curr;
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