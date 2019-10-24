#include <stdio.h>

double 	skalarProdukt	(double u[3], double v[3]);
void 	vektorProdukt	(double u[3], double v[3], double w[3]);

int main() {
	double u[3] = {1,2,3};
	double v[3] = {4,5,6};
	double w[3] = {9,9,9};
	
	// input
	/*
	printf("a: "); scanf("%lf", &a);
	printf("b: "); scanf("%lf", &b);
	printf("c: "); scanf("%lf", &c);
	printf("x: "); scanf("%lf", &x);
	printf("y: "); scanf("%lf", &y);
	printf("z: "); scanf("%lf", &z);
	*/
	
	// output scalar product
	printf("Scalar product: %lf\n", skalarProdukt(u, v));

	// output vector product
	vektorProdukt(u, v, w);
	printf("Vector product: (%lf, %lf, %lf)\n", w[0], w[1], w[2]);	
}

double skalarProdukt(double u[3], double v[3]) {
	return u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
}

void vektorProdukt(double u[3], double v[3], double w[3]) {
	w[0] = u[1]*v[2] - u[2]*v[1];
	w[1] = u[2]*v[0] - u[0]*v[2];
	w[2] = u[0]*v[1] - u[1]*v[0];
}