#ifndef _KUNDE_CLASS_
#define _KUNDE_CLASS_

#include <string>
#include <iostream>
#include <assert.h>

#define m_assert(expr, msg) assert(( (void)(msg), (expr) ))

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Kunde
{
private:
	string name;
	int pin;
	double balance;

public:
	// Constructor
	Kunde(string name, int pin, double balance = 0);

	// get/set methods for datafields
	void setName(string);
	void setPin(int);
	void setBalance(double);
	string getName();
	double getBalance();

	// Print out current balance
	void printBalance();

	// Check if entered pin is equal to actual pin
	bool checkPin(int);

	// Decreases balance by specified amount. Requires pin for execution.
	void drawMoney(double amount = 0);
};

#endif