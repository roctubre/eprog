#include "name.hpp"

Name::Name(string full_name)
{
	this->setFullName(full_name);
}

Name::Name(string first_name, string surname)
{
	this->first_name = first_name;
	this->surname = surname;
}

void Name::setFirstName(string first_name)
{
	this->first_name = first_name;
}

void Name::setSurname(string surname)
{
	this->surname = surname;
}

string Name::getFirstName()
{
	return this->first_name;
}

string Name::getSurname()
{
	return this->surname;
}

void Name::setFullName(string fullname)
{
	int idx_surname = fullname.find_last_of(' ');
	this->first_name = fullname.substr(0, idx_surname);
	this->surname = fullname.substr(idx_surname + 1, fullname.length() - 1);
}

void Name::printName()
{
	string fullname;

	// process firstname
	int idx = this->first_name.find(' ');
	if (idx < 0) {
		fullname += this->first_name;
	}
	else {
		fullname += this->first_name.substr(0, idx);
		do {
			fullname += ' ' + this->first_name.substr(idx + 1, 1) + '.';
			idx = this->first_name.find(' ', idx + 1);
		} while (idx != -1);
	}

	// lastname
	fullname += ' ' + this->surname;
	cout << fullname << endl;
}
