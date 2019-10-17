/*
Description: 
Output the circumference and area of a circle with a given radius

Input: 
- r ... radius

Output:
- circle circumference (2*r*pi)
- circle area (r*r*pi)
*/

#include <stdio.h>

#define true 1
#define false 0

double calc_pi()
{
    /* Using Leibniz's Formula to estimate Pi */

    double pi = 1;
    int sign = false;
    unsigned int precision = 1E6;
    unsigned int denominator = 0;

    for(unsigned int i = 0; i < precision; ++i)
    {
        denominator = 3 + i*2;
        pi += sign ? (double)1./denominator : (double)-1./denominator;
        sign = sign ? false : true;
    }
    
    return pi * 4.;
}

int main() {

    double r = 0;
    //double pi = 3.14;
    double pi = calc_pi();

    // ask for circle radius 
    printf("Enter radius: ");
    scanf("%lf", &r);

    // output circle radius and area
    printf("Circle Radius: %lf\n", 2*r*pi);
    printf("Circle Area: %lf\n", r*r*pi);

    return 0;
}