#include <stdio.h>

/*
    Returns a positive number given by the user. 
    It asks the user for an input until it is strictly positive.
*/
double scanfpositive() {
    double input = 0;
    while (input  <= 0) {
        printf("Enter positive number: ");
        scanf("%lf", &input);
    }
    return input;
}

int main() {
    printf("Your positive number: %lf\n", scanfpositive());
}

