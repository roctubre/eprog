/*
Description: 
Check if three given values form a pythagorean triple

Input: 
- a, b, c ... natural numbers

Output:
- Valid or invalid pythagorean triple
*/

#include <stdio.h>

int main() {
    
    // pythagorean triple
    unsigned long a = 0;
    unsigned long b = 0;
    unsigned long c = 0;

    // input values for triple
    printf("Side A: ");
    scanf("%ld", &a);
    printf("Side B: ");
    scanf("%ld", &b);
    printf("Side C: ");
    scanf("%ld", &c);
    
    // validate input
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Only positive numbers allowed.");
        return 0;
    }
    
    // swap values so c = max(a, b, c)
    if (a > c) {
        a = a + c;
        c = a - c;
        a = a - c;
    }
    if (b > c) {
        b = b + c;
        c = b - c;
        b = b - c;
    }

    // Output if a valid triple
    if(a * a + b * b == c * c) {
        printf("Valid pythagorean triple.\n");
    }
    else {
        printf("Not a pythagorean triple.\n");
    }

    return 0;
}