#ifndef _FRACTIONVECTOR_
#define _FRACTIONVECTOR_

#include <cstdlib>
#include <cassert>
#include "fraction.hpp"


class FractionVector
{
private:
	// Size of vector
	int n;

	// Coefficient vector
	Fraction* coeff;

	// Sorts coefficient vector using quicksort algorithm
	void quickSort(Fraction*, int);
public:
	// Contructor
	FractionVector(int n = 0);

	// Contructor with initialized fractions
	FractionVector(int n, const Fraction* coeff);

	// Copy constructor
	FractionVector(const FractionVector&);

	// Assignment constructor
	FractionVector& operator=(const FractionVector&);

	// Destructor
	~FractionVector();

	// Returns size of vector
	int getSize() const;

	// Returns coefficient at given index
	Fraction getCoefficient(int) const;

	// Sets coefficient at given index
	void setCoefficient(int, const Fraction&);

	// Exercise 12.8. - Sort coefficient vector
	void sort();
};

std::ostream& operator<<(std::ostream&, const FractionVector&);

#endif