// rechteck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <cassert>

int area(double a, double b) 
{
	return a * b;
}

int main(int argc, char *argv[])
{
	double a = 0;
	double b = 0;

	// check if atleast two arguments are provided and process them
	if (argc > 2)
	{
		std::istringstream sa(argv[1]);
		std::istringstream sb(argv[2]);

		// exit if either of them are invalid numbers
		if (!(sa >> a) || !sa.eof())
		{
			std::cerr << "Invalid number: " << argv[1] << std::endl;
			return 1;
		}
		if (!(sb >> b) || !sa.eof())
		{
			std::cerr << "Invalid number: " << argv[2] << std::endl;
			return 1;
		}
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " [num] [num]" << std::endl;
        return 0;
	}
	
	// output size of area (a*b)
    std::cout << "Area: " << area(a, b) << std::endl;

	return 0;
}
