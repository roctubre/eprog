#ifndef _FRACTIONVECTOR_
#define _FRACTIONVECTOR_

#include <cstdlib>
#include <cassert>
#include "fraction.hpp"


class FractionVector
{
private:
	int n;
	Fraction* coeff;
public:
	FractionVector(int n = 1);
	FractionVector(int n, const Fraction* coeff);
	FractionVector(const FractionVector&);
	FractionVector& operator=(const FractionVector&);
	~FractionVector();

	int getSize() const;
	Fraction getCoefficient(int) const;
	void setCoefficient(int, const Fraction&);

	// Exercise 12.8. - Sort coefficient vector
	void sort();
};

std::ostream& operator<<(std::ostream&, const FractionVector&);

#endif