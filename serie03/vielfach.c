#include <stdio.h>

/*
    Outputs the multiples of a number k until the maximum number n
*/
void vielfache(int k, int nmax) {
    for (int i = 0; k * i <= nmax; ++i) {
        printf("%d x %d = %d\n", i, k, i*k);
    }
}

int main() {
    int k = 0;  // base number to print out the multiples of
    int n = 0;  // maximum number
    
    // get input
    printf("k: "); scanf("%d", &k);
    printf("n: "); scanf("%d", &n);
    
    // validate input
    if (k < 0 || k > n) {
        printf("Required: 0 < k <= n");
        return 0;
    }

    // function call
    vielfache(k, n);
}