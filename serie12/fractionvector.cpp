#include "fractionvector.hpp"

void FractionVector::quickSort(Fraction* x, int n)
{
	if (n <= 1) return;                     // only continue if element count > 1

	int j, k;
	for (j = 0, k = 1; k < n; ++k) {
		if (x[k] < x[0]) {                  // compare to pivot, swap values
			++j;
			if (k == j) continue;
			x[j] = x[j] + x[k];
			x[k] = x[j] - x[k];
			x[j] = x[j] - x[k];
		}
	}

	// swap pivot and last lesser element
	if (j > 0) {
		x[0] = x[0] + x[j];
		x[j] = x[0] - x[j];
		x[0] = x[0] - x[j];
	}

	quickSort(x, j++);          // sort lesser part
	quickSort(x + j, n - j);    // sort greater part
}

FractionVector::FractionVector(int n)
{
	assert(n > 0 && "Size must be positive");
	this->n = n;
	this->coeff = new Fraction[n];
}

FractionVector::FractionVector(int n, const Fraction* coeff)
{
	this->n = n;
	this->coeff = new Fraction[n];
	for (int i = 0; i < n; ++i) {
		this->coeff[i] = coeff[i];
	}
}

FractionVector::FractionVector(const FractionVector& x)
{
	this->n = x.n;
	this->coeff = new Fraction[x.n];

	for (int i = 0; i < x.n; ++i) {
		this->coeff[i] = x.coeff[i];
	}
}

FractionVector& FractionVector::operator=(const FractionVector& rhs)
{
	if (this != &rhs) {
		this->n = rhs.n;
		this->coeff = new Fraction[rhs.n];

		for (int i = 0; i < rhs.n; ++i) {
			this->coeff[i] = rhs.coeff[i];
		}
	}

	return *this;
}

FractionVector::~FractionVector()
{
	if (this->coeff) {
		delete[] this->coeff;
	}
}

int FractionVector::getSize() const
{
	return this->n;
}

Fraction FractionVector::getCoefficient(int idx) const
{
	assert(0 <= idx && idx < this->n && "Index out of range");
	return this->coeff[idx];
}

void FractionVector::setCoefficient(int idx, const Fraction& f)
{
	assert(0 <= idx && idx < this->n && "Index out of range");
	this->coeff[idx] = f;
}

void FractionVector::sort()
{
	quickSort(this->coeff, this->n);
}

std::ostream& operator<<(std::ostream& output, const FractionVector& f)
{
	output << "[(" << f.getCoefficient(0) << ")";
	for (int i = 1; i < f.getSize(); ++i) {
		output << ", (" << f.getCoefficient(i) << ")";
	}
	return output << "]";
}
