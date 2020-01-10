#include <iostream>
#include "polynomial.hpp"

using namespace std;

int main()
{
    cout << sizeof(double) << endl;

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
