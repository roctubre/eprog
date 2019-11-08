#include <stdio.h>
#include <assert.h>

int kgV(int a, int b);  // least common multiple
int gcd(int a, int b);  // greatest common divisor


int main() {
    int a = 0;
    int b = 0;

    // get input
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);

    // function call and output
    printf("kgV: %d\n", kgV(a, b));
}

/*
    Returns the least common multiple (lcm, dt. kgV) of two numbers.

    Implementation Notes:
    The least common multiple of two numbers is their product divided by 
    their greatest common divisor (gcd)
*/
int kgV(int a, int b) {
    assert(a > 0);
    assert(b > 0);

    return (a * b) / gcd(a, b);
}

/*
    Returns the greatest common divisor of two numbers.
    Uses a recursive implementation of the euclidean algorithm.
*/
int gcd(int a, int b) {
    if (b == 0) return a;

    if (a >= b) {
        gcd(b, a % b);
    }
    else {
        gcd(a, b % a);
    }
}
