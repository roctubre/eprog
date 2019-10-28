#include <stdio.h>

/*
    Check if a 3 digit number sequence is present in a 10 digit number sequence.
    Input:
    x ... base sequence
    y ... searched sequence
    Output:
    1 ... found
    0 ... not found
*/
int check(int x[10], int y[3]) {
    // iterate through base sequence until len(x) - len(y)
    for (int i = 0; i <= 7; ++i) {
        // compare sequence from x[i] to x[i + 2] with y[0] to y[2]
        if (x[i] == y[0] && x[i + 1] == y[1] && x[i + 2] == y[2]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int x[10];      // 10 digit number sequence
    int y[3];       // 3 digit number sequence to look for
    
    // get input for x and y
    printf("Number sequence:\n");
    for (int i = 0; i < 10; ++i) {
        printf("#%d: ", i + 1); scanf("%d", &x[i]);
    }
    printf("\nSearch sequence:\n");
    for (int i = 0; i < 3; ++i) {
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