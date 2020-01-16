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
	this->pdegree = src.degree();
	this->coefficients = (double*) malloc( (src.degree() + 1) * sizeof(double) );

	assert(this->coefficients && "memory allocation failed");
	for (int d = 0; d <= src.degree(); ++d) {
		this->coefficients[d] = src.getCoefficient(d);
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
			this->coefficients = NULL;
		}

		this->pdegree = rhs.degree();
		this->coefficients = (double*) malloc( (rhs.degree() + 1) * sizeof(double) );

		assert(this->coefficients && "memory allocation failed");
		for (int d = 0; d <= rhs.degree(); ++d) {
			this->coefficients[d] = rhs.getCoefficient(d);
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

double Polynomial::computeZero(double x0, double tau) const
{
	Polynomial diff = this->diff(1);
	double x = x0;
	double x_prev;
	int max_iter = 10000;	// in case of no zeroes

	do {
		x_prev = x;
		x = x_prev - eval(x_prev) / diff.eval(x_prev);

		if (--max_iter == 0) {	
			cout << "Might not have a solution" << endl;
			break;
		}
	} while (fabs(eval(x)) > tau || fabs(x - x_prev) > tau);
	


	return x;
}


double factorial(int k) {
	double f = 1;
	for (; k > 0; --k) {
		f *= k;
	}
	return f;
}