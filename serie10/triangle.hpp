#ifndef _TRIANGLE_CLASS_
#define _TRIANGLE_CLASS_

#include <cmath>

class Triangle {
private:
	double x[2];
	double y[2];
	double z[2];

public:
	void setX(double, double);
	void setY(double, double);
	void setZ(double, double);
	double getArea();
	double getPerimeter();
	bool isEquilateral();
};

#endif
