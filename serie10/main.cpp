#include <iostream>
#include <string>
#include "triangle.hpp"
#include "ellipse.hpp"
#include "university.hpp"
#include "name.hpp"
#include "kunde.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void task_10_1_triangle();
void task_10_2_ellipse();
void task_10_3_palindrom();
bool isPalindrome(string);
void task_10_4_university();
void task_10_5_name();
void task_10_6_Kunde();
void task_10_7_roman();
string int2roman(int n);
int roman2int(string s);
/* Task 10_8
    Output:
    5
    10
    10

    Explanation:
    A.getptrN() returns the address of the private member N, which can be used to directly
    manipulate the value.
    This is bad practice because the purpose of encapsulation is to hide senstive data from the user.
    Sensitive data must only be accessed and manipulated through class methods. The pointer allows to bypass this required behaviour.
*/

int main()
{
    //task_10_1_triangle();
    //task_10_2_ellipse();
    //task_10_3_palindrom();
    //task_10_4_university();
    //task_10_5_name();
    task_10_6_Kunde();
    //task_10_7_roman();
}


void task_10_1_triangle() {
    Triangle t;
    t.setX(0, 0);
    t.setY(2, 0);
    t.setZ(1, sqrt(3));

    cout << "Area: " << t.getArea() << endl;
    cout << "Perimeter: " << t.getPerimeter() << endl;
    cout << "isEquilateral: " << (t.isEquilateral() ? "Yes" : "No") << endl;
}

void task_10_2_ellipse() {
    Ellipse e;
    e.setCenter(0, 0);
    e.setA(3);
    e.setB(3);
    e.printFocalPoints();
    cout << "isInside: " << (e.isInside(3, 0) ? "Yes" : "No") << endl;
    cout << "isCircle: " << (e.isCircle() ? "Yes" : "No") << endl;
    cout << "Eccentricity: " << e.getEccentricity() << endl;
}

void task_10_3_palindrom() {
    string word;
    cout << "Enter word: ";
    cin >> word;
    if (isPalindrome(word)) {
        cout << "Is palindrome." << endl;
    }
    else {
        cout << "Is NOT palindrome." << endl;
    }
}

bool isPalindrome(string word) {
    for (int i = 0; i < (int)word.length() / 2; ++i) {
        if (word[i] != word[((int)word.length() - 1) - i]) {
            return false;
        }
    }
    return true;
}

void task_10_4_university() {
    University u("TU", 3);
    cout << "Name: " << u.getCity() << ", Students: " << u.getNumStudents() << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.newStudent();
    cout << "New Student enrolled!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
    u.graduate();
    cout << "Student graduated!" << endl;
}

void task_10_5_name() {
    Name n("Max Maxi Mustermann");
    Name m("Bob Baumeister");
    Name o("Adolph Blaine Charles David Earl Frederick Gerald Hubert Irvin John Kenneth Lloyd Martin Nero Oliver Paul Quincy Randolph Sherman Thomas Uncas Victor William Xerxes Yancy Zeus Wolfe");

    cout << n.getFirstName() << " " << n.getSurname() << endl;
    n.printName();

    cout << m.getFirstName() << " " << m.getSurname() << endl;
    m.printName();

    cout << o.getFirstName() << " " << o.getSurname() << endl;
    o.printName();
}

void task_10_6_Kunde() {
    Kunde kunde("Bobs", 1234, 100);
    kunde.printBalance();
    kunde.drawMoney(95);
    kunde.printBalance();
    kunde.drawMoney(10);
}

void task_10_7_roman() {
    int z = 494;
    cout << int2roman(z) << endl;
    cout << roman2int(int2roman(z)) << endl;
}

/*
    Converts a decimal number to its roman representation.
*/
string int2roman(int n) {
    string rom;

    string m[] = { "", "M", "MM", "MMM" };
    string c[] = { "", "C", "CC", "CCC", "CD", "D",
                        "DC", "DCC", "DCCC", "CM" };
    string x[] = { "", "X", "XX", "XXX", "XL", "L",
                        "LX", "LXX", "LXXX", "XC" };
    string i[] = { "", "I", "II", "III", "IV", "V",
                        "VI", "VII", "VIII", "IX" };

    string thousands = m[n / 1000];
    string hundereds = c[(n % 1000) / 100];
    string tens = x[(n % 100) / 10];
    string ones = i[n % 10];

    rom = thousands + hundereds + tens + ones;
    return rom;
}

/*
    Converts a roman number to its decimal representation.
*/
int roman2int(string s) {
    int total = 0;
    const char* letters = s.c_str();
    int len = strlen(letters);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'I') {
            if (i < len && letters[i + 1] == 'V') {
                total += 4;
                ++i;
            }
            else if (i < len && letters[i + 1] == 'X') {
                total += 9;
                ++i;
            }
            else {
                total += 1;
            }
        }
        else if (s[i] == 'V') {
            total += 5;
        }
        else if (s[i] == 'X') {
            if (i < len && letters[i + 1] == 'L') {
                total += 40;
                ++i;
            }
            else if (i < len && letters[i + 1] == 'C') {
                total += 90;
                ++i;
            }
            else {
                total += 10;
            }
        }
        else if (s[i] == 'L') {
            total += 50;
        }
        else if (s[i] == 'C') {
            if (i < len && letters[i + 1] == 'D') {
                total += 400;
                ++i;
            }
            else if (i < len && letters[i + 1] == 'M') {
                total += 900;
                ++i;
            }
            else {
                total += 100;
            }
        }
        else if (s[i] == 'D') {
            total += 500;
        }
        else if (s[i] == 'M') {
            total += 1000;
        }
    }

    return total;
}