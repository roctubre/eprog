#include <stdio.h>

/*
	Recusive function to calculate the square root of a given value using binary search.
	Limited to 5 decimal points, since it might cause stack overflow on greater precision.
*/
double sqrt_routine(double value, double n1, double n2)
{
	double result = 0.;

	// compares the first 5 decimal points by first multiplying by 1E5, and typecasting to integer
	if ((int)(n2*n2*1E5) == (int)(value*1E5)) {					
		return n2;
	}

	// binary search
	if (n2*n2 < value) {
		result = sqrt_routine(value, n2, n2 + (n2 - n1));
	}
	if (n2*n2 > value)
	{
		result = sqrt_routine(value, n1, n1 + (n2 - n1) / 2);
	}

	return result;
}

/*
	Returns the square root of a given value.
	Wrapper function for the recursive call.
*/
double sqrt(double value) {
	return value == 0 ? 0 : sqrt_routine(value, 0., 1.);
}


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