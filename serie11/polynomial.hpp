#ifndef _POLYNOMIAL_CLASS_
#define _POLYNOMIAL_CLASS_

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <iostream>

class Polynomial {
private:
	// polynomial degree
	int pdegree;

	// coefficient vector
	double* coefficients;			

public:
	// Constructor; initializes a zero-polynomial of degree n
	Polynomial(int = 0);

	// Copy Constructor
	Polynomial(const Polynomial&);

	// Destructor; free up dynamic memory
	~Polynomial();

	// Assignment operator
	Polynomial& operator=(const Polynomial&);

	// Returns degree of this polynomial
	int degree() const;

	// get/set methods for coefficients
	void setCoefficient(int degree, double value);
	double getCoefficient(int degree) const;

	// Exercise 11.2.
	// Evaluates the polynomial for a given value
	double eval(double x) const;

	// Exercise 11.3.
	// Returns the k-th derivative of the polynomial
	const Polynomial diff(int k) const;

	// Exercise 11.7.
	// Computes the integral of the polynomial
	double computeIntegral(double alpha, double beta) const;

	// Exercise 11.8.
	// Compute a zero of the polynomial
	double computeZero(double x0, double tau) const;
};

#endif