#include <iostream>
#include "polynomial.hpp"

using namespace std;

// Exercise 11.4.
// Add two polynoms and also overload function to add constant values
void test_10_4_add();
const Polynomial addPolynomials(const Polynomial&, const Polynomial&);
const Polynomial addPolynomials(const Polynomial&, double);
const Polynomial addPolynomials(double, const Polynomial&);

int main()
{
    test_10_4_add();
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