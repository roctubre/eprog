#include "polynomial.hpp"

using namespace std;

Polynomial::Polynomial(int degree) {
	assert(degree > 0 && "Non-negative degree required");
	this->pdegree = degree;
	this->coefficients = (double*) malloc( (degree + 1)*sizeof(double) );

	assert(this->coefficients && "memory allocation failed");
	for (int d = 0; d <= degree; ++d) {
		this->coefficients[d] = 0;
	}
}

Polynomial::Polynomial(const Polynomial& src) {
	if (this->coefficients) {
		free(this->coefficients);
		this->coefficients = nullptr;
	}

	this->pdegree = src.pdegree;
	this->coefficients = (double*) malloc( (src.pdegree + 1) * sizeof(double) );

	assert(this->coefficients && "memory allocation failed");
	for (int d = 0; d <= src.pdegree; ++d) {
		this->coefficients[d] = src.coefficients[d];
	}
}

Polynomial::~Polynomial() {
	if (this->coefficients) {
		free(this->coefficients);
	}
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this != &rhs) {
		if (this->coefficients) {
			free(this->coefficients);
			this->coefficients = nullptr;

			this->pdegree = rhs.pdegree;
			this->coefficients = (double*) malloc( (rhs.pdegree + 1) * sizeof(double) );

			assert(this->coefficients && "memory allocation failed");
			for (int d = 0; d <= rhs.pdegree; ++d) {
				this->coefficients[d] = rhs.coefficients[d];
			}
		}
	}

	return *this;
}

int Polynomial::degree() const {
	return this->pdegree;
}

void Polynomial::setCoefficient(int degree, double value) {
	assert(degree >= 0 && degree <= this->pdegree && "degree out of range");
	this->coefficients[degree] = value;
}

double Polynomial::getCoefficient(int degree) const {
	assert(degree >= 0 && degree <= this->pdegree && "degree out of range");
	return this->coefficients[degree];
}