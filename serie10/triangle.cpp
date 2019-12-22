#include "triangle.hpp"

void Triangle::setX(double x0, double x1) {
	x[0] = x0;
	x[1] = x1;
}

void Triangle::setY(double y0, double y1) {
	y[0] = y0;
	y[1] = y1;
}

void Triangle::setZ(double z0, double z1) {
	z[0] = z0;
	z[1] = z1;
}

double Triangle::getArea() {
	return 0.5 * fabs((y[0] - x[0]) * (z[1] - x[1]) - (z[0] - x[0]) * (y[1] - x[1]));
}

double Triangle::getPerimeter() {
	return	sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2)) + 
			sqrt(pow(x[0] - z[0], 2) + pow(x[1] - z[1], 2)) + 
			sqrt(pow(z[0] - y[0], 2) + pow(z[1] - y[1], 2));
}

bool Triangle::isEquilateral()
{
	double a = sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2));
	double b = sqrt(pow(y[0] - z[0], 2) + pow(y[1] - z[1], 2));
	double c = sqrt(pow(z[0] - x[0], 2) + pow(z[1] - x[1], 2));

	if (fabs(a - b) < 1e-5 && fabs(b - c) < 1e-5) {
		return true;
	}
	return false;
}
