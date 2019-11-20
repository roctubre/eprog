#include <stdio.h>
#include <assert.h>

void     playTicTacToe    ();                           // start tic tac toe game
void     printTicTacToe   (int x[3][3], int isPlay);    // print out playfield
int      checkState       (int x[3][3]);                // winner, draw, ongoing,...


int main() {
    playTicTacToe();
}

/*
    Starts a TicTacToe game.
*/
void playTicTacToe() {
    // initialize variables
    int playfield[3][3] = {{0, 0, 0}, 
                           {0, 0, 0}, 
                           {0, 0, 0}};
    int info[3][3] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9}};
    int moves = 0;
    int choice = 0;                  // field chosen by player
    int result = 0;

    // show information at start
    printf("TIC TAC TOE\n");
    printf("Information:\n");
    printf("- Fields are represented by numbers\n");
    printf("- Player 1 (X) - Player 2 (O)\n\n");
    printTicTacToe(info, 0);

    // players take turns until there's a winner or draw
    while(checkState(playfield) == 0) {
        // get player's choice
        printf("\nPlayer %d - choose field: ", (moves%2 == 0 ? 1 : 2));
        scanf("%d", &choice);
        --choice;      // adjust to array index

        // validate choice and write to field
        if (choice >= 0 && choice < 9 && playfield[choice/3][choice%3] == 0) {
            playfield[choice/3][choice%3] = moves%2 == 0 ? 1 : 2;
            ++moves;

            // print out playfield
            printf("\n");
            printTicTacToe(playfield, 1);
        }
        else {
            printf("\nInvalid field!\n");
        }
    }
    
    // announce result
    result = checkState(playfield);
    printf("\nResult: ");
    if(result == 1) {
        printf("Player 1 wins.\n");
    }
    else if(result == 2) {
        printf("Player 2 wins.\n");
    }
    else {
        printf("Draw.\n");
    }
}

/*
    Check and return state of Tic Tac Toe playfield.
    0 ... no result (ongoing)
    1 ... Player 1 won
    2 ... Player 2 won
    3 ... draw
*/
int checkState(int x[3][3]) {
    // check player 1 win conditions
    if ((x[0][0] == 1 && x[0][1] == 1 && x[0][2] == 1) ||   // rows
        (x[1][0] == 1 && x[1][1] == 1 && x[1][2] == 1) || 
        (x[2][0] == 1 && x[2][1] == 1 && x[2][2] == 1) ||
        (x[0][0] == 1 && x[1][0] == 1 && x[2][0] == 1) ||   // columns
        (x[0][1] == 1 && x[1][1] == 1 && x[2][1] == 1) ||
        (x[0][2] == 1 && x[1][2] == 1 && x[2][2] == 1) ||
        (x[0][0] == 1 && x[1][1] == 1 && x[2][2] == 1) ||   // diagonals
        (x[0][2] == 1 && x[1][1] == 1 && x[2][0] == 1)) {
        return 1;
    }

    // check player 2 win conditions
    if ((x[0][0] == 2 && x[0][1] == 2 && x[0][2] == 2) ||   // rows
        (x[1][0] == 2 && x[1][1] == 2 && x[1][2] == 2) || 
        (x[2][0] == 2 && x[2][1] == 2 && x[2][2] == 2) ||
        (x[0][0] == 2 && x[1][0] == 2 && x[2][0] == 2) ||   // columns
        (x[0][1] == 2 && x[1][1] == 2 && x[2][1] == 2) ||
        (x[0][2] == 2 && x[1][2] == 2 && x[2][2] == 2) ||
        (x[0][0] == 2 && x[1][1] == 2 && x[2][2] == 2) ||   // diagonals
        (x[0][2] == 2 && x[1][1] == 2 && x[2][0] == 2)) {
        return 2;
    }

    // check if atleast one field is still open
    int i, j;
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j) {
            if(x[i][j] == 0) {
                return 0;
            }
        }
    }

    // draw condition reached
    return 3;   
}

/*
    Print out Tic Tac Toe playfield.
*/
void printTicTacToe(int x[3][3], int isPlay) {
    if(isPlay) {
        printf(" %c │ %c │ %c\n", x[0][0] == 1 ? 'X' : x[0][0] == 2 ? 'O' : ' ', 
                                  x[0][1] == 1 ? 'X' : x[0][1] == 2 ? 'O' : ' ', 
                                  x[0][2] == 1 ? 'X' : x[0][2] == 2 ? 'O' : ' ');
        printf("───┼───┼───\n");
        printf(" %c │ %c │ %c\n", x[1][0] == 1 ? 'X' : x[1][0] == 2 ? 'O' : ' ', 
                                  x[1][1] == 1 ? 'X' : x[1][1] == 2 ? 'O' : ' ', 
                                  x[1][2] == 1 ? 'X' : x[1][2] == 2 ? 'O' : ' ');
        printf("───┼───┼───\n");
        printf(" %c │ %c │ %c\n", x[2][0] == 1 ? 'X' : x[2][0] == 2 ? 'O' : ' ', 
                                  x[2][1] == 1 ? 'X' : x[2][1] == 2 ? 'O' : ' ', 
                                  x[2][2] == 1 ? 'X' : x[2][2] == 2 ? 'O' : ' ');
    }
    else {
        printf(" %d │ %d │ %d\n", x[0][0], x[0][1], x[0][2]);
        printf("───┼───┼───\n");
        printf(" %d │ %d │ %d\n", x[1][0], x[1][1], x[1][2]);
        printf("───┼───┼───\n");
        printf(" %d │ %d │ %d\n", x[2][0], x[2][1], x[2][2]);
    }
}

