// fraction.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "fraction.hpp"

using namespace std;

void test_12_3_typecasting();
void test_12_4_arithmetics();
void test_12_5_sign();

int main()
{
	test_12_3_typecasting();
	test_12_4_arithmetics();
	test_12_5_sign();
}

void test_12_3_typecasting() {
	cout << endl << "### TEST 12.3 - Convert Double<>Fraction ###" << endl;

	Fraction a(3, 4);
	cout << "3/4 to double: " << (double)a << endl;

	Fraction b(1, 3);
	cout << "1/3 to double: " << (double)b << endl;

	Fraction f(3.14159265359);
	cout << "3.14159265359 to fraction: " << f << endl;

	Fraction g(0.263157894737);
	cout << "0.263157894737 to fraction: " << g << endl;

	Fraction h(0.606557377049);
	cout << "0.606557377049 to fraction: " << h << endl;
}

void test_12_4_arithmetics() {
	cout << endl << "### TEST 12.4 - Operator +,-,*,/ ###" << endl;

	Fraction a(2, 4);
	Fraction b(3, 2);
	cout << a << " + " << b << " = " << a + b << endl;

	Fraction c(1, 4);
	Fraction d(1, 2);
	cout << c << " - " << d << " = " << c - d << endl;

	Fraction e(3, 4);
	Fraction f(-4, 3);
	cout << e << " * " << f << " = " << e * f << endl;

	Fraction g(10, 5);
	Fraction h(5, 6);
	cout << g << " / " << h << " = " << g / h << endl;
}

void test_12_5_sign() {
	cout << endl << "### TEST 12.5 - SIGN & Operator<< ###" << endl;

	Fraction a(3, 4);
	cout << "From Positive: " << a << " to Negative: " << -a << endl;

	Fraction b(1, -2);
	cout << "From Negative: " << b << " to Positive: " << -b << endl;
}