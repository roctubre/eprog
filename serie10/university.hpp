#ifndef _UNIVERSITY_CLASS_
#define _UNIVERSITY_CLASS_

#include <string>
#include <assert.h>

using std::string;

class University
{
private:
	string city;
	int num_students;

public:
	// Constructor
	University(string, int);

	// get and set methods for city name
	void setCity(string);
	string getCity();

	// get and set methods for student number
	void setNumStudents(int);
	int getNumStudents();

	// decreases student count by 1
	void graduate();

	// increases student count by 1
	void newStudent();
};

#endif