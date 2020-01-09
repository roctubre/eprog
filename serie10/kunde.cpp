#include "kunde.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

Kunde::Kunde(string name, int pin, double balance)
{
	this->setName(name);
	this->setPin(pin);
	this->setBalance(balance);
}

void Kunde::setName(string name)
{
	assert(!name.empty() && "Name required.");
	this->name = name;
}

void Kunde::setPin(int pin)
{
	this->pin = pin;
}

void Kunde::setBalance(double balance)
{
	this->balance = balance;
}

string Kunde::getName()
{
	return this->name;
}

double Kunde::getBalance()
{
	return this->balance;
}

void Kunde::printBalance()
{
	cout << "Current balance: " << this->balance << endl;
}

bool Kunde::checkPin(int pin)
{
	return this->pin == pin;
}

void Kunde::drawMoney(double amount)
{
	int pin = 0;
	assert(amount >= 0 && "Can't withdraw negative amount.");
	if (amount == 0) {
		cout << "Enter amount to withdraw: ";
		cin >> amount;
		assert(amount > 0 && "Amount must be greater then 0.");
	}

	cout << "Enter pincode: ";
	cin >> pin;
	assert(this->checkPin(pin) && "Wrong pincode!");
	assert(this->getBalance() >= amount && "Balance insufficient!");

	this->setBalance(this->getBalance() - amount);
	if (this->getBalance() < 10) {
		cout << "Warning! Remaining Balance is below EUR 10.00" << endl;
	}
}
