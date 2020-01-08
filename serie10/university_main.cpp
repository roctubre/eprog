#include <iostream>
#include <string>
#include "university.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    University u("Wien", 3);
    cout << "Name: " << u.getCity() << ", Students: " << u.getNumStudents() << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.newStudent();
    cout << "New Student enrolled!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
}
