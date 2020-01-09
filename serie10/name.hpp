#ifndef _NAME_CLASS_
#define _NAME_CLASS_

#include <string>
#include <iostream>

class Name
{
private:
	string first_name;
	string surname;

public:
	// Constructors
	Name(string full_name);
	Name(string first_name, string surname);

	// get/set methods for datafields
	void setFirstName(string);
	void setSurname(string);
	string getFirstName();
	string getSurname();

	// Extracts and sets the firstname and surname from a given string.
	void setFullName(string);

	// Ouputs fullname with secondary first names shortened
	void printName();
};

#endif