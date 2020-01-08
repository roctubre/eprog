#include <iostream>
#include <string>
#include "name.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char *argv[])
{
	if (argc == 2) {
		Name n(argv[1]);
		cout << "Fullname: " << n.getFirstName() << " " << n.getSurname() << endl << "Shortened: ";
		n.printName();
	}
	else {
		cout << "Usage: " << argv[0] << " <name>" << endl;
		
		cout << "\nExamples:" << endl;
		Name n("Max Maxi Mustermann");
		Name m("Bob Baumeister");
		Name o("Adolph Blaine Charles David Earl Frederick Gerald Hubert Irvin John Kenneth Lloyd Martin Nero Oliver Paul Quincy Randolph Sherman Thomas Uncas Victor William Xerxes Yancy Zeus Wolfe");
		
		cout << "Fullname: " << n.getFirstName() << " " << n.getSurname() << endl << "Shortened: ";
		n.printName();
		cout << "Fullname: " << m.getFirstName() << " " << m.getSurname() << endl << "Shortened: ";
		m.printName();
		cout << "Fullname: " << o.getFirstName() << " " << o.getSurname() << endl << "Shortened: ";
		o.printName();
	}
}