/*
Description: 
Determine the n-th member of the sequence ((-1)^n)/(n+2)

Input:
- n ... natural number, n-th element

Output: 
- (-1)^n / (n+2)
*/

#include <stdio.h>

int main() {

    int n = 0;
    double a_n = 1.;

    // which element n to look for
    printf("Given n: ");
    scanf("%d", &n);
    
    // validate input
    if (n <= 0)
    {
        printf("Only positive numbers allowed.");
        return 0;
    }

    // determine sign by checking if n is odd or even
    a_n = n % 2 == 0 ? 1. : -1.;

    // output nth element in sequence
    printf("Element of sequence: %lf\n", (double)(a_n / (n + 2)));

    return 0;
}