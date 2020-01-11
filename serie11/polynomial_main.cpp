#include <iostream>
#include "polynomial.hpp"

using namespace std;

void test_10_1_class();
void test_10_2_eval();
void test_10_3_diff();

// Exercise 11.4.
// Add two polynoms and also overload function to add constant values
void test_10_4_add();
const Polynomial addPolynomials(const Polynomial&, const Polynomial&);
const Polynomial addPolynomials(const Polynomial&, double);
const Polynomial addPolynomials(double, const Polynomial&);

int main()
{
    //test_10_1_class();
    //test_10_2_eval();
    //test_10_3_diff();
    test_10_4_add();
}

void test_10_1_class() {
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

void test_10_2_eval() {
    Polynomial p(2);
    p.setCoefficient(0, 2);
    p.setCoefficient(1, 3);
    p.setCoefficient(2, 4);
    cout << p.eval(2) << endl;  // 2*(2^0) + 3*(2^1) + 4*(2^2) = 24

    Polynomial q(0);
    q.setCoefficient(0, 3);
    cout << q.eval(9) << endl;  // 2*(9^0) = 3
}

void test_10_3_diff() {
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

void test_10_4_add() {
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

const Polynomial addPolynomials(const Polynomial& p, double c)
{
    Polynomial result = p;
    result.setCoefficient(0, result.getCoefficient(0) + c);
    return result;
}

const Polynomial addPolynomials(double a, const Polynomial& p)
{
    return addPolynomials(p, a);
}