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
char checkForWinner(char board[BOARD_HEIGHT][BOARD_WIDTH]);
// int checkForTie(char board[BOARD_HEIGHT][BOARD_WIDTH]);

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
    char winner;

    // RUN LOOP
    while (true) {

        // GAME LOOP
        game_over = false;
        initializeBoard(board);
        current_player = 1;
        winner = '0';

        while (!game_over) {
        turn_begin:
            system("clear");
            printBoard(board);

            // print winner 
            if (winner != '0') {
                switch (winner) {
                    case PLAYER_ONE || PLAYER_TWO:
                        printf("Player %c wins!\n", winner);
                        game_over = true;
                        break;
                    case '1':
                        printf("Its a Tie!\n");
                        game_over = true;
                        break;
                }
                printf("The Player with the Character %c won!\n", winner);
                game_over = true;
                break;
            }

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

            // check for win
            winner = checkForWinner(board);

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

char checkForWinner(char board[BOARD_HEIGHT][BOARD_WIDTH]) {

    // check for horizontal win
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // check for vertical win
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // check for diagonal win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return board[1][1];
    }

    // check for tie
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == (i * BOARD_WIDTH + j + '1')) {
                return '1';
            }
            
        }
    }


    return '0';
}
