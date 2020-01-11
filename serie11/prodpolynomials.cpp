#include <iostream>
#include "polynomial.hpp"

using namespace std;

/*  Exercise 11.5.
    Calculate the product of two polynoms and also overload the function to allow scalar multiplication.

    ### Questions ###

    > Degree of a polynom pq with degrees n and m? 
    - Add degrees together: n + m

    > Formula for calculating coefficients?
    - For x^h the quotient is SUM_(n+m==h)(a_j * b_k)
    - See https://math.stackexchange.com/questions/1785572/coefficient-of-product-of-polynomials

    > Complexity of addPolynomials() with two polynomials of same degree? 
    - Same degrees -> O(n^2)
    - If different degrees -> O(n*m), where n is degree of polynomial p and m is degree of polynomial q
    
    > Given two polynomials p and q with degrees n = 10^2 and a Runtime of 1 second, what is Runtime of n = 10^3?
    - (10^3)^2 = 10^6, divided by 10^2 = 10^4 seconds ~ 166 minutes
*/
void test_11_5_prod();
const Polynomial prodPolynomials(const Polynomial&, const Polynomial&);
const Polynomial prodPolynomials(const Polynomial&, double);
const Polynomial prodPolynomials(double, const Polynomial&);

int main()
{
    test_11_5_prod();
}

void test_11_5_prod() {
    Polynomial p(3);
    p.setCoefficient(0, 2);
    p.setCoefficient(1, 3);
    p.setCoefficient(2, 4);
    cout << p.degree() << " - "
        << p.getCoefficient(0) << ", "
        << p.getCoefficient(1) << ", "
        << p.getCoefficient(2) << endl;

    Polynomial q(2);
    q.setCoefficient(0, 1);
    q.setCoefficient(1, 2);
    cout << q.degree() << " - "
        << q.getCoefficient(0) << ", "
        << q.getCoefficient(1) << endl;

    Polynomial r = prodPolynomials(p, q);
    cout << r.degree() << " - "
        << r.getCoefficient(0) << ", "
        << r.getCoefficient(1) << ", "
        << r.getCoefficient(2) << ", "
        << r.getCoefficient(3) << endl;

    Polynomial s = prodPolynomials(2, r);
    cout << s.degree() << " - "
        << s.getCoefficient(0) << ", "
        << s.getCoefficient(1) << ", "
        << s.getCoefficient(2) << ", "
        << s.getCoefficient(3) << endl;
}

const Polynomial prodPolynomials(const Polynomial& p, const Polynomial& q) {
    Polynomial newp(p.degree() + q.degree());

    for (int k = 0; k <= p.degree(); ++k) {
        for (int j = 0; j <= q.degree(); ++j) {
            newp.setCoefficient(k + j, newp.getCoefficient(k + j) + p.getCoefficient(k) * q.getCoefficient(j));
        }
    }

    return newp;
}

const Polynomial prodPolynomials(const Polynomial& p, double a) {
    Polynomial result = p;
    for (int n = 0; n <= result.degree(); ++n) {
        result.setCoefficient(n, result.getCoefficient(n)*a);
    }

    return result;
}

const Polynomial prodPolynomials(double a, const Polynomial& p) {
    return prodPolynomials(p, a);
}