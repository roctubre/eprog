#ifndef _ELLIPSE_CLASS_
#define _ELLPISE_CLASS_

#include <iostream>
#include <cmath>
#include <assert.h>

#define max(x, y)	((x) >= (y) ? (x) : (y))
#define min(x, y)	((x) <= (y) ? (x) : (y))

class Ellipse
{
private:
	double center[2];
	double a;
	double b;
public:
	void setCenter(double, double);

	// ret radius parallel to the x-axis
	void setA(double);

	// ret radius parallel to the y-axis
	void setB(double);

	// check if point is inside or on the ellipse
	bool isInside(double, double);

	// check if circle
	bool isCircle();

	// output the focal points of the ellipse
	void printFocalPoints();

	// the eccentricity of an ellipse, which measures the circularity.
	double getEccentricity();
};

#endif