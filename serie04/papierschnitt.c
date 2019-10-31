#include <stdio.h>

int addElementToArray(int arr[], int arrlen, int e, int newarr[]);
void papierschnitt_rec(int n, int r, int seq[], int seqlen);
void papierschnitt(int n);

int main() {
    int n;

    // get input
    printf("n: "); scanf("%d", &n);

    // validate input
    if (n <= 0) {
        printf("n must be greater than 0");
        return 0;
    }

    // check sequence and output result
    papierschnitt(n);
}


/*
    Adds an element to an array by first copying a source array A to a larger
    target array B and then adding e to the last index of B.
    
*/
int addElementToArray(int arr[], int arrlen, int e, int newarr[]) {
    for (int i = 0; i < arrlen; ++i) {
        newarr[i] = arr[i];
    }
    newarr[arrlen] = e;
    return arrlen + 1;
}

/*
    Wrapper function for the papierschnitt recursive call
*/
void papierschnitt(int n) {
    int arr[0];
    papierschnitt_rec(n, n, arr, 0);
}

/*
    A recursive function which prints all possible sequences of 2 and 1 so 
    the sum of them results to n.
*/
void papierschnitt_rec(int n, int r, int seq[], int seqlen) {
    if(r == 1 || r == 2) {
        printf("%d = ", n);
        for (int i = 0; i < seqlen; ++i) {
            printf("%d + ", seq[i]);
        }
        printf("%d\n", r);

        // case 2
        if(r == 2) {
            int newarr[seqlen+1];
            addElementToArray(seq, seqlen, 1, newarr);
            papierschnitt_rec(n, 1, newarr, seqlen + 1);
        }
    }
    else {
        int newarr[seqlen+1];
        // case 2
        addElementToArray(seq, seqlen, 2, newarr);
        papierschnitt_rec(n, r-2, newarr, seqlen + 1);
        // case 1
        addElementToArray(seq, seqlen, 1, newarr);
        papierschnitt_rec(n, r-1, newarr, seqlen + 1);
    }
}
