#include "polynomial.hpp"

using namespace std;

double factorial(int k);

Polynomial::Polynomial(int degree) {
	assert(degree >= 0 && "Non-negative degree required");
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

double Polynomial::eval(double x) const
{
	double result = 0;
	for (int n = 0; n <= this->pdegree; ++n) {
		result += this->coefficients[n] * pow(x, n);
	}
	return result;
}

const Polynomial Polynomial::diff(int k) const
{
	assert(k >= 0 && "Non-negative degree required");
	if (this->pdegree < k) {
		Polynomial p(0);
		return p;
	}
	else if (this->pdegree == k) {
		Polynomial p(0);
		p.setCoefficient(0, this->getCoefficient(k)*factorial(k));
		return p;
	}
	else {
		Polynomial p(this->pdegree - k);
		for (int i = 0, n = k; i <= p.pdegree; ++i, ++n) {
			p.coefficients[i] = this->coefficients[n] * factorial(n);
		}
		return p;
	}
}

double Polynomial::computeIntegral(double alpha, double beta) const
{
	assert(alpha < beta && "alpha must be less than beta");

	double sum = 0;
	for (int n = 0; n <= this->pdegree; ++n) {
		sum += (this->coefficients[n] * (pow(beta, n + 1) - pow(alpha, n + 1))) / (n + 1);
	}
	return sum;
}


double factorial(int k) {
	double f = 1;
	for (; k > 0; --k) {
		f *= k;
	}
	return f;
}