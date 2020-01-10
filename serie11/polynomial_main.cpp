#include <iostream>
#include "polynomial.hpp"

using namespace std;

void test_10_1_class();
void test_10_2_eval();

int main()
{
    //test_10_1_class();
    test_10_2_eval();
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