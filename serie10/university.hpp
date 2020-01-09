#ifndef _UNIVERSITY_CLASS_
#define _UNIVERSITY_CLASS_

#include <string>
#include <assert.h>

class University
{
private:
	std::string city;
	int num_students;

public:
	// Constructor
	University(std::string, int);

	// get and set methods for city name
	void setCity(std::string);
	std::string getCity();

	// get and set methods for student number
	void setNumStudents(int);
	int getNumStudents();

	// decreases student count by 1
	void graduate();

	// increases student count by 1
	void newStudent();
};

#endif