
// Simple Tic-Tac-Toe Game where you can play against the computer

// INCLUDES
#include <stdio.h>
#include <stdbool.h>

// DEFINES
#define BOARD_HEIGHT 3
#define BOARD_WIDTH 3

// FUNCTIONS
void printInstructions();
// Board Functions
void printBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);

// Logic Functions
int checkForWinner(char board[BOARD_HEIGHT][BOARD_WIDTH]);
int checkForTie(char board[BOARD_HEIGHT][BOARD_WIDTH]);


// MAIN FUNCTUION
int main(int argc, char **argv){
    // printf("Welcome to Tic-Tac-Toe!\n");

    // VARIABLES
    bool game_over;
    char grid[BOARD_HEIGHT][BOARD_WIDTH];

    int current_player;
    char player1 = 'X';
    char player2 = 'O';



    printf("Welcome to Tic-Tac-Toe!\n");

    return 0;
}

void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (j+1 == BOARD_WIDTH) {
                printf("%c\n", board[i][j]);
            } else {
                printf("%c | ", board[i][j]);
            }
            // printf("%c", board[i][j]);
        }
        if (i+1 == BOARD_HEIGHT) {
            printf("\n");
        } else {
            printf("\n-----------\n");
        }
    }
}
