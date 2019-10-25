#include <stdio.h>

double 	skalarProdukt	(double u[3], double v[3]);
void 	vektorProdukt	(double u[3], double v[3], double w[3]);

int main() {
	double u[3] = {1,2,3};
	double v[3] = {4,5,6};
	double w[3] = {9,9,9};
	
	// input
	/*
	printf("a: "); scanf("%lf", &u[0]);
	printf("b: "); scanf("%lf", &u[1]);
	printf("c: "); scanf("%lf", &u[2]);
	printf("x: "); scanf("%lf", &v[0]);
	printf("y: "); scanf("%lf", &v[1]);
	printf("z: "); scanf("%lf", &v[2]);
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