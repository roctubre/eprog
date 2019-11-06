#include <stdio.h>

void kreuz(int n);

int main() {
    int n;  

    // get input
    printf("n: "); scanf("%d", &n);

    // validate input
    if (n <= 0) {
        printf("n must be greater than 0\n");
        return 0;
    }

    // function call
    kreuz(n);
}

/*
    Prints out an X consisting of numbers between 1 to 9 which is 2n - 1 lines big.
    Valid inputs are n = 1 to 9
    Example: n = 4
    1     1
     2   2
      3 3
       4
      3 3
     2   2
    1     1
*/
void kreuz(int n) {
    // loop variables
    int i;
    int j;

    // iterate through 2n - 1 lines
    for (i = 0; i < 2*n - 1; ++i) {
        // iterate through characters (each line has 2n - 1 characters)
        for (j = 0; j < 2*n - 1; ++j) {
            // print out the number or an empty character
            if(j == i || j == (2*n-1) - 1*(i+1)) {
                if (i + 1 <= n) {   // first n lines
                    printf("%d", i + 1);
                }
                else {              // last n-1 lines
                    printf("%d", i - (2*(i - n) + 1));
                }
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
