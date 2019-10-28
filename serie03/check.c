#include <stdio.h>

#define LEN_BASE   10
#define LEN_SEARCH 3

/*
    Check if a 3 digit number sequence is present in a 10 digit number sequence.
    Input:
    x ... base sequence
    y ... searched sequence
    Output:
    1 ... found
    0 ... not found
*/
int check(int x[LEN_BASE], int y[LEN_SEARCH]) {
    // iterate through base sequence until len(x) - len(y)
    for (int i = 0; i <= LEN_BASE - LEN_SEARCH; ++i) {
        // compare x and y starting from x[i]
        for (int j = 0; j < LEN_SEARCH; ++j) {
            // leave loop if digits are not equal
            if (x[i + j] != y[j]) {
                continue;
            }
            // if the last digits are equal return 1
            if (j == LEN_SEARCH - 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int x[LEN_BASE];      // 10 digit number sequence
    int y[LEN_SEARCH];       // 3 digit number sequence to look for
    
    // get input for x and y
    printf("Number sequence:\n");
    for (int i = 0; i < LEN_BASE; ++i) {
        printf("#%d: ", i + 1); scanf("%d", &x[i]);
    }
    printf("\nSearch sequence:\n");
    for (int i = 0; i < LEN_SEARCH; ++i) {
        printf("#%d: ", i + 1); scanf("%d", &y[i]);
    }

    // check sequence and output result
    if (check(x, y)) {
        printf("Sequence found!\n");
    }
    else {
        printf("Sequence not found.\n");
    }
}