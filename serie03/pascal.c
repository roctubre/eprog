#include <stdio.h>

void    pascal      (int n);
int     binomial    (int n, int k);


int main() {
    int n = 0;
    
    // get input
    printf("n: "); scanf("%d", &n);
    
    // validate input
    if (n <= 0) {
        printf("n must be greater than 0");
        return 0;
    }

    // function call
    pascals_triangle(n);
}


/*
    Prints out Pascal's triangle down to the n-th line.
    Example: n = 5
    1
    1   1
    1   2   1
    1   3   3   1
    1   4   6   4   1
*/
void pascals_triangle(int n) {
    // iterate through all lines from top to n-th line
    for (int line = 0; line < n; ++line) {
        // print out binomial coefficient of every element
        // n = line, k = element index
        for (int k = 0; k <= line; ++k) {
            printf("%d ", binomial(line, k));
        }
        printf("\n");
    }
}


/*
	Calculates the binomial coefficient in reduced form using loops given n and k.
*/
int binomial(int n, int k) {
    int numerator = 1;
    int denominator = 1;

    for (int nn = n; nn >= (n - k + 1); --nn) {
        numerator *= nn;
    }

    for (int kk = k; kk >= 1; --kk) {
        denominator *= kk;
    }

    return numerator / denominator;
}