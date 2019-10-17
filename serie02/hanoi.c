#include <stdio.h>

/*
	The tower of hanoi problem implemented with a recursive function. 
	It outputs the necessary moves to move n disks from post i to post j.
	For n disks, a total 2^n-1 moves are taken.
*/
void hanoi(int m, int i, int j) {
	int spare = 0;

	if (m == 1) {
		printf("Move disk 1 from post #%d to post #%d\n", i, j);
		return;
	}

	// get index of spare post
	if ((i == 1 && j == 2) || (i == 2 && j == 1)) {
		spare = 3;
	}
	else if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
		spare = 1;
	}
	else {
		spare = 2;
	}

	hanoi(m - 1, i, spare);
	printf("Move disk %d from post #%d to post #%d\n", m, i, j);
	hanoi(m - 1, spare, j);
}

int main()
{
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