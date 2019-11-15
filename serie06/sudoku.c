#include <stdio.h>
#include <assert.h>

int     checkSudoku    (int x[16]);
void    printSudoku    (int x[16]);
int     isValidSet     (int v[4]);


int main() {
    int debug = 1;  // set to 0 (false) or 1 (true)
    int x[16] = {1,3,4,2,4,2,1,3,2,4,3,1,3,1,2,4};  // VALID
    int i, j;

    // get input for each cell; skip if debug
    if(!debug) {
        for(i = 0; i < 4; ++i) {
            for(j = 0; j < 4; ++j) {
                printf("x[%d, %d]: ", i, j); 
                scanf("%d", &x[4*i + j]);
                assert(x[4*i + j] > 0 && x[4*i + j] <= 4);
            }
        }
    }

    // validate and output sudoku grid
    if(checkSudoku(x)) {
        printf("Sudoku is VALID.\n");
    }
    else {
        printf("Sudoku is NOT VALID.\n");
    }
    printSudoku(x);
}

/*
    Checks the solution of a 4x4 Sudoku. 
    It goes through rows, columns and 2x2 blocks.
*/
int checkSudoku(int x[16]) {
    int v[4];   // stores the 4 elements of each row, column and 2x2 block
    int i, j;

    // check rows
    for(i = 0; i < 4; ++i) {
        v[0] = x[4*i + 0];
        v[1] = x[4*i + 1];
        v[2] = x[4*i + 2];
        v[3] = x[4*i + 3];
        if(!isValidSet(v)) {
            return 0;
        }
    }

    // check columns
    for(i = 0; i < 4; ++i) {
        v[0] = x[4*0 + i];
        v[1] = x[4*1 + i];
        v[2] = x[4*2 + i];
        v[3] = x[4*3 + i];
        if(!isValidSet(v)) {
            return 0;
        }
    }

    // check 2x2 blocks
    for(i = 0; i < 2; ++i) {
        for(j = 0; j < 2; ++j) {
            v[0] = x[8*i + 2*j];
            v[1] = x[8*i + 2*j + 1];
            v[2] = x[8*i + 4 + 2*j];
            v[3] = x[8*i + 4 + 2*j + 1];
            if(!isValidSet(v)) {
                return 0;
            }
        }
    }

    return 1;
}

/*
    Checks if given vector contains values 1-4, without repetition
*/
int isValidSet(int v[4]) {
    int present[4] = {0, 0, 0, 0};  // helper array
    int i;

    for(i = 0; i < 4; ++i) {
        // check if not yet set in present array.
        if(present[v[i] - 1]) { // == 1 ; if already set, it is a duplicate
            return 0;           // and therefore return false
        }
        present[v[i] - 1] = 1;
    }
    return 1;
}

/*
    Prints out the given Sudoku grid.
*/
void printSudoku(int x[16]) {
    printf("╔═══╤═══╦═══╤═══╗\n");
    printf("║ %d │ %d ║ %d │ %d ║\n", x[0], x[1], x[2], x[3]);
    printf("╟───┼───╫───┼───╢\n");
    printf("║ %d │ %d ║ %d │ %d ║\n", x[4], x[5], x[6], x[7]);
    printf("╟═══╪═══╬═══╪═══╣\n");
    printf("║ %d │ %d ║ %d │ %d ║\n", x[8], x[9], x[10], x[11]);
    printf("╟───┼───╫───┼───╢\n");
    printf("║ %d │ %d ║ %d │ %d ║\n", x[12], x[13], x[14], x[15]);
    printf("╚═══╧═══╩═══╧═══╝\n");
}