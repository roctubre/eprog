#ifndef _KUNDE_CLASS_
#define _KUNDE_CLASS_

#include <string>
#include <iostream>
#include <assert.h>

#define m_assert(expr, msg) assert(( (void)(msg), (expr) ))

class Kunde
{
private:
	std::string name;
	int pin;
	double balance;

public:
	// Constructor
	Kunde(std::string name, int pin, double balance = 0);

	// get/set methods for datafields
	void setName(std::string);
	void setPin(int);
	void setBalance(double);
	std::string getName();
	double getBalance();

	// Print out current balance
	void printBalance();

	// Check if entered pin is equal to actual pin
	bool checkPin(int);

	// Decreases balance by specified amount. Requires pin for execution.
	void drawMoney(double amount = 0);
};

#endif