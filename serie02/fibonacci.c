#include <stdio.h>

/*
	Gets the n-th fibbonacci element by using recursive calls.
	CAUTION! Very ressource intensive. Not recommended for large n-ths.
	Can be improved with memoization, but we didn't learn about arrays yet...
*/
long fibonacci(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fibonacci(n - 2) + fibonacci(n-1);
}

int main()
{
	double n = 0;

	// input
	printf("n: "); scanf("%lf", &n);

	// validate input
	if (n < 0) {
		printf("Only non-negative values allowed!\n");
	}

	// function call and output
	printf("Fibbonacci n-th element: %ld", fibonacci(n));
}