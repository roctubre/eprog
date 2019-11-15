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
    int playfield[3][3] = {{-1, -1, -1}, 
                           {-1, -1, -1}, 
                           {-1, -1, -1}};
    int info[3][3] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9}};
    int moves = 0;                  // move counter; max. 9 moves
    int choice = 0;                  // field chosen by player
    int result = 0;

    // show information at start
    printf("TIC TAC TOE\n");
    printf("Information:\n");
    printf("- Fields are represented by numbers\n");
    printf("- Player 1 (X) - Player 2 (O)\n\n");
    printTicTacToe(info, 0);

    // players take turns
    while(moves < 9) {
        // get player's choice
        printf("\nPlayer %d - choose field: ", moves%2 == 0 ? 1 : 2);
        scanf("%d", &choice);
        --choice;      // adjust to array index

        // validate choice and write to field
        if (choice >= 0 && choice < 9 && playfield[choice/3][choice%3] == -1) {
            playfield[choice/3][choice%3] = moves%2 == 0 ? 0 : 1;
            ++moves;

            // print out playfield
            printf("\n");
            printTicTacToe(playfield, 1);

            // stop game if there's a winner or draw
            if (checkState(playfield) != 0) break;
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
    if ((x[0][0] == 0 && x[0][1] == 0 && x[0][2] == 0) ||   // rows
        (x[1][0] == 0 && x[1][1] == 0 && x[1][2] == 0) || 
        (x[2][0] == 0 && x[2][1] == 0 && x[2][2] == 0) ||
        (x[0][0] == 0 && x[1][0] == 0 && x[2][0] == 0) ||   // columns
        (x[0][1] == 0 && x[1][1] == 0 && x[2][1] == 0) ||
        (x[0][2] == 0 && x[1][2] == 0 && x[2][2] == 0) ||
        (x[0][0] == 0 && x[1][1] == 0 && x[2][2] == 0) ||   // diagonals
        (x[0][2] == 0 && x[1][1] == 0 && x[2][0] == 0)) {
        return 1;
    }

    // check player 2 win conditions
    if ((x[0][0] == 1 && x[0][1] == 1 && x[0][2] == 1) ||   // rows
        (x[1][0] == 1 && x[1][1] == 1 && x[1][2] == 1) || 
        (x[2][0] == 1 && x[2][1] == 1 && x[2][2] == 1) ||
        (x[0][0] == 1 && x[1][0] == 1 && x[2][0] == 1) ||   // columns
        (x[0][1] == 1 && x[1][1] == 1 && x[2][1] == 1) ||
        (x[0][2] == 1 && x[1][2] == 1 && x[2][2] == 1) ||
        (x[0][0] == 1 && x[1][1] == 1 && x[2][2] == 1) ||   // diagonals
        (x[0][2] == 1 && x[1][1] == 1 && x[2][0] == 1)) {
        return 2;
    }

    // check if atleast field is still open
    int i, j;
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j) {
            if(x[i][j] == -1) {
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
        printf(" %c │ %c │ %c\n", x[0][0] == 0 ? 'X' : x[0][0] == 1 ? 'O' : ' ', 
                                  x[0][1] == 0 ? 'X' : x[0][1] == 1 ? 'O' : ' ', 
                                  x[0][2] == 0 ? 'X' : x[0][2] == 1 ? 'O' : ' ');
        printf("───┼───┼───\n");
        printf(" %c │ %c │ %c\n", x[1][0] == 0 ? 'X' : x[1][0] == 1 ? 'O' : ' ', 
                                  x[1][1] == 0 ? 'X' : x[1][1] == 1 ? 'O' : ' ', 
                                  x[1][2] == 0 ? 'X' : x[1][2] == 1 ? 'O' : ' ');
        printf("───┼───┼───\n");
        printf(" %c │ %c │ %c\n", x[2][0] == 0 ? 'X' : x[2][0] == 1 ? 'O' : ' ', 
                                  x[2][1] == 0 ? 'X' : x[2][1] == 1 ? 'O' : ' ', 
                                  x[2][2] == 0 ? 'X' : x[2][2] == 1 ? 'O' : ' ');
    }
    else {
        printf(" %d │ %d │ %d\n", x[0][0], x[0][1], x[0][2]);
        printf("───┼───┼───\n");
        printf(" %d │ %d │ %d\n", x[1][0], x[1][1], x[1][2]);
        printf("───┼───┼───\n");
        printf(" %d │ %d │ %d\n", x[2][0], x[2][1], x[2][2]);
    }
}

