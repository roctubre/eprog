#include <stdio.h>

/*
	Check collinearity of three given points.
	This is determined by calulcating the triangle area, which must equal zero.
*/
void punkte(double x, double y, double u, double v, double a, double b) {
	double area = x * (v - b) + u * (b - y) + a * (y - v);
	if (area == 0) {
		printf("All points lie on a straight line.\n");
	}
	else {
		printf("The points do not lie on a straight line.\n");
	}
}

int main() {
	bool debug = true;
	double x = 1;
	double y = 1;
	double u = 1;
	double v = 2;
	double a = 2;
	double b = 5;

	// input
	if (!debug) {
		printf("x: "); scanf("%lf", &x);
		printf("y: "); scanf("%lf", &y);
		printf("u: "); scanf("%lf", &u);
		printf("v: "); scanf("%lf", &v);
		printf("a: "); scanf("%lf", &a);
		printf("b: "); scanf("%lf", &b);
	}

	// function call
	punkte(x, y, u, v, a, b);
}