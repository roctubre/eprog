#include <iostream>
#include <string>
#include "kunde.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{
    Kunde kunde("Bobs", 1234, 100);
    kunde.printBalance();
	cout << "Withdrawing EUR 95.00..." << endl;
    kunde.drawMoney(95);
    kunde.printBalance();
	cout << "Withdrawing EUR 10.00..." << endl;
    kunde.drawMoney(10);
}
