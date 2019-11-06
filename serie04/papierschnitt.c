#include <stdio.h>

#define MAXLEN 100

void papierschnitt_rec(int r, int seqlen);
void papierschnitt(int n);

// global variables
int sequence[MAXLEN];
int n;

int main() {
    // get input
    printf("n: "); scanf("%d", &n);

    // validate input
    if (n <= 0 || n > MAXLEN) {
        printf("n must be between 1 and %d", MAXLEN);
        return 0;
    }

    // function call
    papierschnitt(n);
}

/*
    Wrapper function for the papierschnitt recursive call
*/
void papierschnitt(int n) {
    papierschnitt_rec(n, 0);
}

/*
    A recursive function which prints out all possible sequences of 2 and 1 so 
    their sum equals n.
    Uses global variables n and sequence(MAXLEN).
*/
void papierschnitt_rec(int r, int seqlen) {
    if (r == 0) {
        // print out sequence
        int i;
        printf("%d = %d", n, sequence[0]);
        for (i = 1; i < seqlen; ++i) {
            printf(" + %d", sequence[i]);
        }
        printf("\n");

        return;
    }

    // case: substract 2
    if (r >= 2) {
        sequence[seqlen] = 2;
        papierschnitt_rec(r - 2, seqlen + 1);
    }

    // case: substract 1
    sequence[seqlen] = 1;
    papierschnitt_rec(r - 1, seqlen + 1);
}