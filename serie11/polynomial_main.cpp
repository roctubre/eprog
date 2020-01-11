#include <iostream>
#include <cmath>
#include "polynomial.hpp"

using namespace std;

void test_11_1_class();
void test_11_2_eval();
void test_11_3_diff();

/*  Exercise 11.4.
    Add two polynoms and also overload function to add constant values
*/
void test_11_4_add();
const Polynomial addPolynomials(const Polynomial&, const Polynomial&);
const Polynomial addPolynomials(const Polynomial&, double);
const Polynomial addPolynomials(double, const Polynomial&);

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

/*  Exercise 11.6.
    Compare two polynomials.
*/
void test_11_6_compare();
bool comparePolynomials(const Polynomial&, const Polynomial&);

int main()
{
    //test_11_1_class();
    //test_11_2_eval();
    //test_11_3_diff();
    //test_11_4_add();
    //test_11_5_prod();
    test_11_6_compare();
}

void test_11_1_class() {
    Polynomial p(2);

    p.setCoefficient(0, 2);
    p.setCoefficient(1, 3);
    p.setCoefficient(2, 4);
    cout << p.degree() << endl;
    cout << p.getCoefficient(0) << endl;
    cout << p.getCoefficient(1) << endl;
    cout << p.getCoefficient(2) << endl << endl;


    Polynomial c = p;
    cout << c.degree() << endl;
    cout << c.getCoefficient(0) << endl;
    cout << c.getCoefficient(1) << endl;
    cout << c.getCoefficient(2) << endl << endl;

    c.setCoefficient(0, 5);
    p = c;
    cout << c.degree() << endl;
    cout << p.getCoefficient(0) << endl;
    cout << p.getCoefficient(1) << endl;
    cout << p.getCoefficient(2) << endl << endl;
}

void test_11_2_eval() {
    Polynomial p(2);
    p.setCoefficient(0, 2);
    p.setCoefficient(1, 3);
    p.setCoefficient(2, 4);
    cout << p.eval(2) << endl;  // 2*(2^0) + 3*(2^1) + 4*(2^2) = 24

    Polynomial q(0);
    q.setCoefficient(0, 3);
    cout << q.eval(9) << endl;  // 2*(9^0) = 3
}

void test_11_3_diff() {
    Polynomial p(3);
    p.setCoefficient(0, 2);
    p.setCoefficient(1, 3);
    p.setCoefficient(2, 4);
    p.setCoefficient(3, 5);

    Polynomial q = p.diff(3);
    cout << q.getCoefficient(0) << endl;  // 3rd derivative, constant => 30

    Polynomial r = p.diff(1);
    cout << r.getCoefficient(0) << endl;  // 1st derivative, constant => 3
    cout << r.getCoefficient(1) << endl;  // 1st derivative, 1st degree => 8
    cout << r.getCoefficient(2) << endl;  // 1st derivative, 2nd degree => 30
}

void test_11_4_add() {
    Polynomial p(3);
    p.setCoefficient(0, 2);
    p.setCoefficient(1, 3);
    p.setCoefficient(2, 4);
    cout << p.getCoefficient(0) << ", "
         << p.getCoefficient(1) << ", "
         << p.getCoefficient(2) << endl;

    Polynomial q(2);
    q.setCoefficient(0, 1);
    q.setCoefficient(1, 2);
    cout << q.getCoefficient(0) << ", "
         << q.getCoefficient(1) << endl;

    Polynomial r = addPolynomials(p, q);
    cout << r.getCoefficient(0) << ", " 
         << r.getCoefficient(1) << ", " 
         << r.getCoefficient(2) << endl;


    Polynomial a = addPolynomials(r, 2);
    cout << a.getCoefficient(0) << ", "
        << a.getCoefficient(1) << ", "
        << a.getCoefficient(2) << endl;

    Polynomial b = addPolynomials(3, a);
    cout << b.getCoefficient(0) << ", "
        << b.getCoefficient(1) << ", "
        << b.getCoefficient(2) << endl;
}

const Polynomial addPolynomials(const Polynomial& p, const Polynomial& q)
{
    int maxdegree = p.degree() > q.degree() ? p.degree() : q.degree();
    Polynomial newp(maxdegree);

    for (int n = 0; n <= maxdegree; ++n) {
        if (n <= p.degree()) {
            newp.setCoefficient(n, newp.getCoefficient(n) + p.getCoefficient(n));
        }
        if (n <= q.degree()) {
            newp.setCoefficient(n, newp.getCoefficient(n) + q.getCoefficient(n));
        }
    }
    return newp;
}

const Polynomial addPolynomials(const Polynomial& p, double a)
{
    Polynomial result = p;
    result.setCoefficient(0, result.getCoefficient(0) + a);
    return result;
}

const Polynomial addPolynomials(double a, const Polynomial& p)
{
    return addPolynomials(p, a);
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