#include "ellipse.hpp"

void Ellipse::setCenter(double x,  double y)
{
	center[0] = x;
	center[1] = y;
}

void Ellipse::setA(double value)
{
	a = value;
}

void Ellipse::setB(double value)
{
	b = value;
}

bool Ellipse::isInside(double x, double y)
{
	double diff = (pow(x - center[0], 2) / pow(a, 2) + pow(y - center[1], 2) / pow(b, 2)) - 1;
	if (diff < 1e-5) {
		if (fabs(diff) < 1e-5) {
			std::cout << "Point lies on the ellipse.\n";
		}
		return true;
	}
	return false;
}

bool Ellipse::isCircle()
{
	return a == b;
}

void Ellipse::printFocalPoints()
{
	if (a > b) {
		std::cout << "Focus 1: (" << center[0] - sqrt(a * a - b * b)
			<< ", " << center[1] << ")\n";
		std::cout << "Focus 2: (" << center[0] + sqrt(a * a - b * b)
			<< ", " << center[1] << ")\n";
	}
	else {
		std::cout << "Focus 1: (" << center[0]
			<< ", " << center[1] - sqrt(a * a - b * b) << ")\n";
		std::cout << "Focus 1: (" << center[0]
			<< ", " << center[1] + sqrt(a * a - b * b) << ")\n";
	}
}

double Ellipse::getEccentricity()
{
	return sqrt(1 - pow(min(a, b)/max(a, b), 2));
}
