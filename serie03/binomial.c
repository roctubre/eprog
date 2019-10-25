#include <stdio.h>

// primary function
int binomial            (int n, int k, int type);
// sub functions
int factorial           (int n);
int binomial_loop       (int n, int k);
int binomial_recursive  (int n, int k);


int main() {
    int n = 0;
    int k = 0;
    
    // get input
    printf("n: "); scanf("%d", &n);
    printf("k: "); scanf("%d", &k);
    
    // validate input
    if (k > n) {
        printf("k can't be greater then n. (Result is 0)");
        return 0;
    }
    else if(n > 12) {
        printf("WARNING: factorial will cause an integer overflow (keep n <= 12)");
    }

    // OUTPUT RESULTS
    // direct; factorial function; O(n)
    printf("Method: DIRECT | Result: %d\n", binomial(n, k, 1));
    
    // reduced form; loops; O(n)
    printf("Method: REDUCED | Result: %d\n", binomial(n, k, 2));

    // recursive; O(2^n)
    printf("Method: RECURSIVE | Result: %d\n", binomial(n, k, 3));
}


/*
    Calculates and returns the binomial coefficient by using 
    one of the following methods:
    1:  Direct approach; using factorial function
    2:  Reduced approach; using loops
    3:  Recursive approach
*/
int binomial(int n, int k, int type) {
    if (type == 1) {
        return factorial(n) / (factorial(k) * factorial(n-k));
    }
    else if(type == 2) {
        return binomial_loop(n, k);
    }
    else if(type == 3) {
        return binomial_recursive(n, k);
    }
    return -1;
}


/*
	A recursive function to determine the binomial coefficient given n and k.
*/
int binomial_recursive(int n, int k) {
	if (n == k || k == 0) {
		return 1;
	}
	return binomial_recursive(n - 1, k) + binomial_recursive(n - 1, k - 1);
}


/*
	Calculates the binomial coefficient in reduced form using loops given n and k.
*/
int binomial_loop(int n, int k) {
    int numerator = 1;
    int denominator = 1;

    for (int nn = n; nn >= (n - k + 1);--nn) {
        numerator *= nn;
    }

    for (int kk = k; kk >= 1;--kk) {
        denominator *= kk;
    }

    return numerator / denominator;
}


/*
    A recursive function which returns the factorial of a given integer n.
*/
int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}
