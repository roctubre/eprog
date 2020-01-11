#include <iostream>
#include <cmath>
#include "polynomial.hpp"

using namespace std;

/*  Exercise 11.6.
    Compare two polynomials.
	Since the coeffiecents are stored as double, a toleranz must be used for comparison.
*/
void test_11_6_compare();
bool comparePolynomials(const Polynomial&, const Polynomial&);

int main()
{
    test_11_6_compare();
}

void test_11_6_compare() {
    Polynomial p(3);
    p.setCoefficient(0, 2);
    p.setCoefficient(1, 3);
    p.setCoefficient(2, 4);
    cout << p.degree() << " - "
        << p.getCoefficient(0) << ", "
        << p.getCoefficient(1) << ", "
        << p.getCoefficient(2) << endl;

    Polynomial q(3);
    q.setCoefficient(0, 2);
    q.setCoefficient(1, 3.000009);
    q.setCoefficient(2, 4);
    cout << q.degree() << " - "
        << q.getCoefficient(0) << ", "
        << q.getCoefficient(1) << ", "
        << q.getCoefficient(2) << endl;

    cout << (comparePolynomials(p, q) ? "EQUAL" : "NOT EQUAL") << endl;
}

bool comparePolynomials(const Polynomial& p, const Polynomial& q) {
    if (p.degree() != q.degree()) return false;

    for (int n = 0; n <= p.degree(); ++n) {
        if (fabs(p.getCoefficient(n) - q.getCoefficient(n)) > 1e-5) {
            return false;
        }
    }

    return true;
}