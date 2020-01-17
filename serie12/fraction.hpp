#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <cassert>
#include <cmath>

class Fraction
{
private:
	// Numerator
	int p;
	// Denominator
	int q;

public:
	// Default constructor
	Fraction();

	// Parameterized constructor
	Fraction(int, int);

	// Copy constructor
	Fraction(const Fraction&);

	// Assignment operator
	Fraction& operator=(const Fraction&);

	// Get methods
	int getNumerator() const;
	int getDenominator() const;

	// Shortens to the smallest possible fraction
	void reduce();

	// Exercise 12.3.
	// Convert between double and fraction
	// double to fraction: approximation using Stern-Brocot tree
	// see https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree
	// also https://stackoverflow.com/questions/5124743/algorithm-for-simplifying-decimal-to-fractions
	// other (Continued Fraction): https://begriffs.com/pdf/dec2frac.pdf
	operator double() const;
	Fraction(double);

	// Exercise 12.5.
	const Fraction operator-() const;

};

// Returns greatest common divisor using euclidean algorithm
int gcd(int, int);

// Returns least common multiple
int lcm(int, int);

// Exercise 12.4.
const Fraction operator+(const Fraction&, const Fraction&);
const Fraction operator-(const Fraction&, const Fraction&);
const Fraction operator*(const Fraction&, const Fraction&);
const Fraction operator/(const Fraction&, const Fraction&);

// Exercise 12.5.
std::ostream& operator<<(std::ostream&, const Fraction&);

// Exercise 12.6.
bool operator==(const Fraction&, const Fraction&);
bool operator!=(const Fraction&, const Fraction&);
bool operator>(const Fraction&, const Fraction&);
bool operator<(const Fraction&, const Fraction&);
bool operator>=(const Fraction&, const Fraction&);
bool operator<=(const Fraction&, const Fraction&);

#endif