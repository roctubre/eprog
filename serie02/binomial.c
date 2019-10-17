#include <stdio.h>

/*
	A recursive function to determine the binomial coefficient given n and k.
*/
int binomial(int n, int k) {
	if (n == k || k == 0) {
		return 1;
	}
	return binomial(n - 1, k) + binomial(n - 1, k - 1);
}

int main()
{
	int n = 0;
	int k = 0;

	// input
	printf("n: "); scanf("%d", &n);
	printf("k: "); scanf("%d", &k);

	// validate input
	if (k > n) {
		printf("k can't be greater then n. (Result is 0)");
	}

	// function call and output
    printf("(n | k) = %d\n", binomial(n,k)); 
}
