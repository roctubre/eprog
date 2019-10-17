/*
Description: 
Sort three numbers and output them in descending order

Input: 
- a, b, c ... rational numbers; the three values to sort

Output:
- Output a, b, c in descending order
*/

#include <stdio.h>

int main() {

    double a = 0;
    double b = 0;
    double c = 0;

    // get values from input
    printf("### Input a, b, c ###\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    // swap values around so that the largest value is in a and smallest in c
    if (a < b)
    {
        b = b + a;
        a = b - a;
        b = b - a;
    }
    if (a < c)
    {
        c = c + a;
        a = c - a;
        c = c - a;
    }
    if (b < c)
    {
        c = c + b;
        b = c - b;
        c = c - b;
    }

    // print out in descending order
    printf ("Descending order:\n%lf\n%lf\n%lf\n", a, b, c);

    return 0;
}