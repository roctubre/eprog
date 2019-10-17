#include "pch.h"
#include <stdio.h>

using namespace std;

/*
	Determines the location of a given point.
	Locations:
	- x-axis (abscissa)
	- y-axis (ordinate)
	- Quadrant 1, 2, 3, 4
*/
void quadrant(double &x, double &y) {
	if (x == 0 || y == 0) {
		if (x == 0) {
			printf("Point is on the ordinate.\n");
		}
		if (y == 0) {
			printf("Point is on the abscissa.\n");
		}
	}
	else {
		if (x > 0 && y > 0) {
			printf("Point is in Quadrant 1.\n");
		}
		else if (x < 0 && y > 0) {
			printf("Point is in Quadrant 2.\n");
		}
		else if (x < 0 && y < 0) {
			printf("Point is in Quadrant 3.\n");
		}
		else {
			printf("Point is in Quadrant 4.\n");
		}
	}
}

int main()
{
	double x = 1;
	double y = 1;

	// input
	printf("x: "); scanf("%lf", &x);
	printf("y: "); scanf("%lf", &y);

	// function call
	quadrant(x, y);
}