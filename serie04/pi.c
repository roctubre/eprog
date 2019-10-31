#include <stdio.h>

double leibnitz(int n, int typ);
double leibnitz_loop(int n);
double leibnitz_recursive(int n);

int main() {
    int n;  

    // get input
    printf("n: "); scanf("%d", &n);

    // validate input
    if (n <= 0) {
        printf("n must be greater than 0\n");
        return 0;
    }

    // function calls for each type
    printf("Loop: %lf\n", leibnitz(n, 1));
    printf("Recursive: %lf\n", leibnitz(n, 2));
}


/*
    Returns the n-th partial sum of the leibnitz formula
    Implementation Types:
    1 ... loop
    2 ... recursion
*/
double leibnitz(int n, int type) {
    if(type == 1) {
        return leibnitz_loop(n);
    }
    else {
        return leibnitz_recursive(n);
    }
}

/*
    Implements the Leibnitz series with a loop.
    Returns the n-th partial sum.
*/
double leibnitz_loop(int n) {
    double sum = 0.;
    int sign = 1;
    for (int k = 0; k <= n; ++k) {
        sign = k % 2 == 0 ? 1 : -1;
        sum += sign * (4. / (2.*k + 1.));
    }
    return sum;
}

/*
    Implements the Leibnitz series with a recursive function.
    Returns the n-th partial sum.
*/
double leibnitz_recursive(int n) {
    if (n < 0) {
        return 0;
    }

    int sign = n % 2 == 0 ? 1 : -1;
    return sign * (4. / (2.*n + 1.)) + leibnitz_recursive(n - 1);
}