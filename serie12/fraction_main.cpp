// fraction.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "fraction.hpp"
#include "fractionvector.hpp"

using namespace std;

void test_12_3_typecasting();
void test_12_4_arithmetics();
void test_12_5_sign();
void test_12_6_comparison();
void test_12_7_fractionvector();
void test_12_8_sort_fractionvector();

int main()
{
	test_12_3_typecasting();
	test_12_4_arithmetics();
	test_12_5_sign();
	test_12_6_comparison();
	test_12_7_fractionvector();
	test_12_8_sort_fractionvector();
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

void test_12_6_comparison() {
	cout << endl << "### TEST 12.6 - Comparison Operators ###" << endl;

	Fraction a(1, 3);
	Fraction b(0, 1);
	cout << a << " == " << b << " is " << (a == b ? "TRUE" : "FALSE") << endl;
	cout << a << " != " << b << " is " << (a != b ? "TRUE" : "FALSE") << endl;
	cout << a << " < " << b << " is " << (a < b ? "TRUE" : "FALSE") << endl;
	cout << a << " > " << b << " is " << (a > b ? "TRUE" : "FALSE") << endl;

	Fraction x(5, 5);
	Fraction y(2, 2);
	cout << x << " == " << y << " is " << (x == y ? "TRUE" : "FALSE") << endl;
	cout << x << " != " << y << " is " << (x != y ? "TRUE" : "FALSE") << endl;
	cout << x << " <= " << y << " is " << (x <= y ? "TRUE" : "FALSE") << endl;
	cout << x << " >= " << y << " is " << (x >= y ? "TRUE" : "FALSE") << endl;
}

void test_12_7_fractionvector() {
	cout << endl << "### TEST 12.7 - FractionVector ###" << endl;

	FractionVector x(3);
	Fraction a(3, 4);
	Fraction b(2, 3);
	Fraction c(-1, 3);
	x.setCoefficient(0, a);
	x.setCoefficient(1, b);
	x.setCoefficient(2, c);
	cout << x << endl;

}

void test_12_8_sort_fractionvector() {
	cout << endl << "### TEST 12.8 - SORT FractionVector ###" << endl;

	Fraction coeff[] = { Fraction(-1, 2), Fraction(5, 7), Fraction(1, 3),
						 Fraction(0, 1), Fraction(11, 2), Fraction(-7, 8) };
	FractionVector x(6, coeff);
	cout << "Unsorted: " << x << endl;
	x.sort();
	cout << "Sorted: " << x << endl;
}