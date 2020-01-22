#include "fraction.hpp"

using namespace std;

Fraction::Fraction()
{
	this->p = 0;
	this->q = 1;
}

Fraction::Fraction(int p, int q)
{
	assert(q != 0 && "Denominator must not equal zero");
	this->p = q < 0 ? -p : p;
	this->q = abs(q);
}

Fraction::Fraction(const Fraction& f)
{
	this->p = f.p;
	this->q = f.q;
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
	if (this != &rhs) {
		this->p = rhs.p;
		this->q = rhs.q;
	}
	return *this;
}

int Fraction::getNumerator() const
{
	return this->p;
}

int Fraction::getDenominator() const
{
	return this->q;
}

void Fraction::reduce()
{
	int g = gcd(p, q);
	this->p /= g;
	this->q /= g;
}

Fraction::operator double() const
{
	return (double)p / (double)q;
}

Fraction::Fraction(double x)
{
	int sign = x < 0 ? 0 : 1;
	x = fabs(x);

	int p = 0;
	int q = 1;
	double error = 1e-9;
	int n = (int)x;
	x -= (double)n;

	if (x < error || 1 - x < error) {
		p = n;
		q = 1;
	}
	else {
		int lower_n = 0;
		int lower_d = 1;
		int upper_n = 1;
		int upper_d = 1;
		int middle_n;
		int middle_d;

		while (true) {
			middle_n = lower_n + upper_n;
			middle_d = lower_d + upper_d;
			if (middle_d * (x + error) < middle_n) {
				upper_n = middle_n;
				upper_d = middle_d;
			}
			else if (middle_n < (x - error) * middle_d) {
				lower_n = middle_n;
				lower_d = middle_d;
			}
			else {
				p = n * middle_d + middle_n;
				q = middle_d;
				break;
			}
		}
	}

	this->p = p * (sign ? 1 : -1);
	this->q = q;
}

const Fraction Fraction::operator-() const
{
	Fraction f(-(this->p), this->q);
	return f;
}

int gcd(int a, int b)
{
	int h;
	a = abs(a);
	b = abs(b);
	while (b != 0) {
		h = a % b;
		a = b;
		b = h;
	}
	return a;
}

int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);
}

const Fraction operator+(const Fraction& x, const Fraction& y)
{
	int q = lcm(x.getDenominator(), y.getDenominator());
	int xl = q / x.getDenominator();
	int yl = q / y.getDenominator();
	int p = x.getNumerator() * xl + y.getNumerator() * yl;
	Fraction f(p, q);
	f.reduce();
	return f;
}

const Fraction operator-(const Fraction& x, const Fraction& y)
{
	int q = lcm(x.getDenominator(), y.getDenominator());
	int xl = q / x.getDenominator();
	int yl = q / y.getDenominator();
	int p = x.getNumerator() * xl - y.getNumerator() * yl;
	Fraction f(p, q);
	f.reduce();
	return f;
}

const Fraction operator*(const Fraction& x, const Fraction& y)
{
	int p = x.getNumerator() * y.getNumerator();
	int q = x.getDenominator() * y.getDenominator();
	Fraction f(p, q);
	f.reduce();
	return f;
}

const Fraction operator/(const Fraction& x, const Fraction& y)
{
	int p = x.getNumerator() * y.getDenominator();
	int q = x.getDenominator() * y.getNumerator();
	Fraction f(p, q);
	f.reduce();
	return f;
}

std::ostream& operator<<(std::ostream& output, const Fraction& x)
{
	return output << x.getNumerator() << "/" << x.getDenominator();
}

bool operator==(const Fraction& x, const Fraction& y)
{
	return x.getNumerator() * y.getDenominator() == y.getNumerator() * x.getDenominator();
}

bool operator!=(const Fraction& x, const Fraction& y)
{
	return !(x == y);
}

bool operator>(const Fraction& x, const Fraction& y)
{
	return x.getNumerator() * y.getDenominator() > y.getNumerator()* x.getDenominator();
}

bool operator<(const Fraction& x, const Fraction& y)
{
	return x.getNumerator() * y.getDenominator() < y.getNumerator()* x.getDenominator();
}

bool operator>=(const Fraction& x, const Fraction& y)
{
	return x > y || x == y;
}

bool operator<=(const Fraction& x, const Fraction& y)
{
	return x < y || x == y;
}
