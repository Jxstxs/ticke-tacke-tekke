// Simple Tic-Tac-Toe Game where you can play against the computer

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

// DEFINES
#define BOARD_HEIGHT 3
#define BOARD_WIDTH 3
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'
#define CAST(x) (int)x-48

// FUNCTIONS
// Help Function
void printInstructions();

// Board Functions
void printBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void initializeBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
bool checkBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], int field);
void setBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], int field, char player);

// Logic Functions
int checkForWinner(char board[BOARD_HEIGHT][BOARD_WIDTH]);
int checkForTie(char board[BOARD_HEIGHT][BOARD_WIDTH]);

// FUNCTIONS

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
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    char answer;
    int field;
    int current_player;

    // RUN LOOP
    while (true) {

        // GAME LOOP
        game_over = false;
        initializeBoard(board);
        current_player = 1;

        while (!game_over) {
        turn_begin:
            system("clear");
            printBoard(board);

            printf("Player %d's turn: ", current_player);
            scanf("%d", &field);

            // check if input is valid
            if (field < 1 || field > 9) {
                printf("Invalid input.\n");
                sleep(2);
                goto turn_begin;
            }

            // check if field is already taken
            if (!checkBoard(board, field)) {
                printf("Field is already taken.\n");
                sleep(2);
                goto turn_begin;
            }

            // set field to current player
            setBoard(board, field, (current_player == 1) ? PLAYER_ONE : PLAYER_TWO);

            // switch players
            current_player = current_player == 1 ? 2 : 1;
        }

        // Ask user if they want to play again
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &answer);
        if (answer == 'n') {
            break;
        }
    }

    return 0;
}

// MAIN FUNCTION

void printInstructions() {
    printf("Welcome to Tic-Tac-Toe!\n\n");
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
                printf("%c", board[i][j]);
            } else {
                printf("%c | ", board[i][j]);
            }
        }
        if (i+1 == BOARD_HEIGHT) {
            printf("\n");
        } else {
            printf("\n----------\n");
        }
    }
}

bool checkBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], int field) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (CAST(board[i][j]) == field) {
                return true;
            }
        }
    }
    return false;
}

void setBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], int field, char player) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (CAST(board[i][j]) == field) {
                board[i][j] = player;
            }
        }
    }
}
