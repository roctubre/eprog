#include <stdio.h>

/*
	The tower of hanoi problem implemented with a recursive function. 
	It outputs the necessary moves to move n disks from post i to post j.
	For n disks, a total of 2^n-1 moves are taken.
*/
void hanoi(int m, int i, int j) {
	int k = 6 - (i + j);  //spare post

	if (m == 1) {
		printf("Move disk 1 from post #%d to post #%d\n", i, j);
		return;
	}
    
	// move from source to spare
	hanoi(m - 1, i, k);
    
	printf("Move disk %d from post #%d to post #%d\n", m, i, j);
    
	// move from spare to target
	hanoi(m - 1, k, j);
}

int main() {
	int n = 0;

	// input
	printf("n: "); scanf("%d", &n);

	// validate input
	if (n <= 0) {
		printf("Need disks to work with... n > 0");
		return 0;
	}

	// function call
	hanoi(n, 1, 3);
}