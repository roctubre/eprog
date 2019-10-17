#include <stdio.h>

/*
	A recursive function which performs a division without remainder on whole numbers.
	Given m and the divider n, the function keeps subtracting n from m until m > n.
*/
int division(int m, int n) {
	if (m - n >= 0) {
		return 1 + division(m - n, n);
	}
	return 0;
}

int main()
{
	int m = 0;
	int n = 0;

	// input
	printf("m: "); scanf("%d", &m);
	printf("n: "); scanf("%d", &n);

	// validate input
	if (m < 0 || n <= 0) {
		printf("Invalid values. (m >= 0, n > 0)\n");
		return 0;
	}

	// function call and output
	printf("%d // %d = %d\n", m, n, division(m, n));
}