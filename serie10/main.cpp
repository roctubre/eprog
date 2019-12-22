#include <iostream>
#include <string>
#include "triangle.hpp"
#include "ellipse.hpp"
#include "university.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void task_10_1_triangle();
void task_10_2_ellipse();
void task_10_3_palindrom();
bool isPalindrome(string);
void task_10_4_university();


int main()
{
    //task_10_1_triangle();
    //task_10_2_ellipse();
    //task_10_3_palindrom();
    task_10_4_university();
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