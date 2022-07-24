
// Simple Tic-Tac-Toe Game where you can play against the computer

// INCLUDES
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

    // check for help flag
    if(argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)){
        printInstructions();
        return 0;
    }

    // VARIABLES
    bool game_over;
    char grid[BOARD_HEIGHT][BOARD_WIDTH];
    char answer;

    int current_player;
    char player1 = 'X';
    char player2 = 'O';


    // RUN LOOP
    while (true) {

        // GAME LOOP
        game_over = false;
        initializeBoard(grid);

        // while (!game_over) {
        //
        // }

        // Ask user if they want to play again
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &answer);
        if (answer == 'n') {
            break;
        }
    }

    return 0;
}

void printInstructions() {
    printf("Welcome to Tic-Tac-Toe!\n\n");
    printf("The goal of the game is to get three in a row.\n");
    printf("You can play against the computer.\n");
    printf("The squares are numbered 1-9.\n");
    printf("The first player to get three in a row wins.\n");
}

void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = i * BOARD_WIDTH + j + '1';
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
