#include <iostream>
#include <string>
#include "ellipse.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	Ellipse e;
	double center_x = 0;
	double center_y = 0;
	double len_a = 3;
	double len_b = 3;
	double check_x = 3;
	double check_y = 0;
	
	if (argc == 7) {
		center_x = std::stod(argv[1], NULL);
		center_y = std::stod(argv[2], NULL);
		len_a = std::stod(argv[3], NULL);
		len_b = std::stod(argv[4], NULL);
		check_x = std::stod(argv[5], NULL);
		check_y = std::stod(argv[6], NULL);
	}
	else {
		cout << "Usage: " << argv[0] << " <center_x> <center_y> <len_a len_b> <check_x> <check_y>" << endl;
		cout << "\nExecuting with default values..." << endl;
		cout << argv[0] << ' '<< center_x << ' ' << center_y << ' ' 
			 << len_a << ' ' << len_b << ' ' 
			 << check_x << ' ' << check_y << ' ' << endl;
	}
	
	e.setCenter(center_x, center_y);
    e.setA(len_a);
    e.setB(len_b);
	
	e.printFocalPoints();
    cout << "isInside: " << (e.isInside(check_x, check_y) ? "Yes" : "No") << endl;
    cout << "isCircle: " << (e.isCircle() ? "Yes" : "No") << endl;
    cout << "Eccentricity: " << e.getEccentricity() << endl;
}

