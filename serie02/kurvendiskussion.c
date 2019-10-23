#include <stdio.h>
#include <math.h>

/*
	Calculates and outputs the intersection points on the x-axis and 
	the extremum of a parabola.
*/
void kurvendiskussion(double a, double b, double c) {
	double discriminant = 0;
	double discr_root = 0;
	double x1 = 0;
	double x2 = 0;
	double extremum_x = 0;
	double extremum_y = 0;

	// Intersection calculation and output
	printf("\n#### Intersection\n");
	discriminant = b * b - 4 * a * c;
	if (c == 0) {			// check if function is not quadratic
		if (b == 0) {		// check if function is not linear
			if (a == 0) {	// check if function is ON the x-axis
				printf("Function lies on the x-axis -> infinite intersections.\n", b);
			}
			else {
				printf("No intersection.\n", b);
			}
		}
		else {
			printf("Intersection at:\nx = %.2lf\n", b);
		}
	}
	else if (discriminant >= 0)
	{
		discr_root = sqrt(discriminant);
		x1 = (-b + discr_root) / (2.*c);
		x2 = (-b - discr_root) / (2.*c);
		if (x1 == x2) {
			printf("Intersection at:\nx = %.2lf.\n", x1);
		}
		else {
			printf("Intersection at:\nx1 = %.2lf.\nx2 = %.2lf.\n", x1, x2);
		}
	}
	else {
		printf("Doesn't intersect with the x-axis.\n");
	}


	// Extremum calculation
	extremum_x = -b / (2.*c);

	// Extremum output
	printf("\n#### Extremum\n");
	if (c == 0) {
		printf("No Extremum.\n");
	}
	else {
		extremum_y = a + b * extremum_x + c * extremum_x * extremum_x;
		if (c > 0) {
			printf("Minimum at (%.2lf, %.2lf)\n", extremum_x, extremum_y);
		}
		else if (c < 0) {
			printf("Maximum at (%.2lf, %.2lf)\n", extremum_x, extremum_y);
		}
	}
}

int main() {
	double a = 0;
	double b = 0;
	double c = 0;

	// input
	printf("a: "); scanf("%lf", &a);
	printf("b: "); scanf("%lf", &b);
	printf("c: "); scanf("%lf", &c);

	// function call
	kurvendiskussion(a, b, c);

	return 0;
}