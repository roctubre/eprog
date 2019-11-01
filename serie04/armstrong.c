#include <stdio.h>
#include <math.h>

void armstrong(int b, int c);

int main() {
    int b = 0;
    int c = 0;

    // get input
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);

    // validate input
    if (b > c) {
        printf("Requirement: b <= c\n");
        return 0;
    }

    // function call
    armstrong(b, c);
}

/*
    Prints out all armstrong numbers in the interval [b, c]
*/
void armstrong(int b, int c) {
    // first number in the interval
    int n = b;

    // loop variables
    int digits; // number of digits
    int nth;    // n-th digit
    int sum;    // sum of potentiated digits
    int i;      // counter inner loop (digits)

    // loop through interval
    for (;n <= c; ++n) {
        digits = (int)(log10(n) + 1);   
        sum = 0;
        for (i = 0; i <= digits; ++i) {
            nth = (int)(n / pow(10, i)) % 10;   
            sum += pow(nth, digits);
        }
        if (sum == n) {
            printf("%d\n", n);
        }
    }
}

