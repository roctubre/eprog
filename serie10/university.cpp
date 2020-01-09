#include "university.hpp"

using std::string;

University::University(string city, int num_student)
{
	this->city = city;
	this->num_students = num_student;
}

void University::setCity(string city)
{
	this->city = city;
}

string University::getCity()
{
	return this->city;
}

void University::setNumStudents(int num_students)
{
	this->num_students = num_students;
}

int University::getNumStudents()
{
	return this->num_students;
}

void University::graduate()
{
	assert(this->num_students > 0 && "No students left...");
	this->num_students--;
}

void University::newStudent()
{
	this->num_students++;
}
