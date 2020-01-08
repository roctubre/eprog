#include <iostream>
#include <string>
#include "triangle.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	Triangle t;
	double a_x = 0;
	double a_y = 0;
	double b_x = 2;
	double b_y = 0;
	double c_x = 1;
	double c_y = sqrt(3);
	
	if (argc == 7) {
		a_x = std::stod(argv[1], NULL);
		a_y = std::stod(argv[2], NULL);
		b_x = std::stod(argv[3], NULL);
		b_y = std::stod(argv[4], NULL);
		c_x = std::stod(argv[5], NULL);
		c_y = std::stod(argv[6], NULL);
	}
	else {
		cout << "Usage: " << argv[0] << " <a_x> <a_y> <b_x> <b_y> <c_x> <c_y>" << endl;
		cout << "\nExecuting with default values..." << endl;
		cout << argv[0] << ' '<< a_x << ' ' << a_y << ' ' 
			 << b_x << ' ' << b_y << ' ' 
			 << c_x << ' ' << c_y << ' ' << endl;
	}
	
	t.setX(a_x, a_y);
    t.setY(b_x, b_y);
    t.setZ(c_x, c_y);
	
	cout << "Area: " << t.getArea() << endl;
    cout << "Perimeter: " << t.getPerimeter() << endl;
    cout << "isEquilateral: " << (t.isEquilateral() ? "Yes" : "No") << endl;
}
