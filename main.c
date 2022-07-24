
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
