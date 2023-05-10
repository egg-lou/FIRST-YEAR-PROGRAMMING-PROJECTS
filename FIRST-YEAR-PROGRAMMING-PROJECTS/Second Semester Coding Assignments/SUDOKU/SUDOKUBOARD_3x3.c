/*
PROGRAM: SIMPLE 3x3 SUDOKU
AUTHOR: GROUP 2
CREATION DATE: 04/05/2023
*/

#include <stdio.h> // For standard input and output
#include <conio.h> // For console input and output
#include <stdlib.h> // For general utilities
#include <time.h>  // For time functions
#include <stdbool.h> // For boolean data type
#include <string.h> // String Functions

// Define a constant value MAX_VALUE equal to 9 and another constant value SIZE equal to 3.
#define MAX_VALUE 9
#define SIZE 3

// Global Variables
// Declare a 2D array called board with dimensions SIZE by SIZE and an array of characters called name with a length of 80.
int board[SIZE][SIZE]; // Board that will be used for the sudoku
char name[80]; // For the name of the player
int first_game = 0; // Counter Variable
int game_counter = 1; // Counter Variable
int firstboard[SIZE][SIZE] = {{0,1,3},{2,5,0},{0,6,8}}; // Fixed 2D array for the first run

clock_t start, end;
double cpu_time_used;

// Function Prototypes
void cleanBoard();  // A function to reset the board to its initial state
bool isValid(int row, int col, int num);  // A function to check if a move is valid for the given row, column and number
void printBoard(); // A function to print the current state of the Sudoku board
void loadBoard(); // A function to load the initial state of the Sudoku board by generating random values or by asking the user for input.
// Note loadBoard at first run of the game loads a fixed 2D array 
void loading();
void display();

int main(){
    char start[10];
    char again[10];
    int startnum, againnum;
    // Welcome message and prompt to start the game
    printf("\nWelcome to the SUDOKU GAME");
    printf("\n\nEnter Player's Name: ");
    gets(name);
    //fgets(name, sizeof(name), stdin);
    printf("\nStart the GAME? [1] for YES and [2] for NO");

    // Do-while loop to validate input and start the game
    do{
        printf("\nResponse: ");
        scanf(" %c", start);
        startnum = atoi(start);
        if(startnum != 1 && startnum != 2)         
           printf("\nINVALID INPUT");
        }while(startnum != 1  && startnum != 2);

        // If the user chooses not to start, exit the loop
    if(startnum == 1){
        do{
        if(game_counter == 1)
            loading();
        printf("\nSUDOKU GAME");
        display();
        loadBoard();
        printf("\n");

        loading();
        system("cls");
        display();
        // Print congratulations message and separator
        printf("\nCongratulations %s! You've completed the SUDOKU BOARD in %.2f seconds!!!\n", name, cpu_time_used);
        printf("Here's the completed board:\n");
        printBoard();
        printf("\n---------------------------");

        do{
        // Prompt to play again
        printf("\nWANT TO PLAY AGAIN? [1] for YES [2] for NO");
        printf("\nResponse: ");
        scanf(" %c", again);
        againnum = atoi(again);
        if(againnum != 1 && againnum != 2)
            printf("\nINVALID INPUT!");
        }while(againnum != 1 && againnum != 2);

        if(againnum == 1){
            cleanBoard();
            first_game++;
            game_counter++;
            loading();
        }
    }while(againnum == 1);
    }

    // Thank you message before exiting the program
    printf("\nThank you for playing the game %s!", name);
    getch();

    // Return 0 to indicate successful program termination
    return 0;
}

void display(){
    printf("\nGames Played: %d", game_counter);
    printf("\nCurrently Playing: %s", name);
}
void loading() {
    int nd, ti;
    char message[] = "L O A D I N G....";
    int message_length = strlen(message);
    clock_t start_time, current_time;
    double elapsed_time;

    system("cls");
    start_time = clock(); // Get the current time
    for(nd = 0; nd < message_length; nd++) {
        printf("%c", message[nd]);
        for(ti = 0; ti <= 199000000; ti++);
    }
    system("cls");
}

// Cleans the board if the user decides to play again
// Sets the values of the board to 0
void cleanBoard() {
    int row, col; 
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            board[row][col] = 0;
        }
    }
}


// Check if a given number can be placed in a given position in the Sudoku board without violating the game rules.
bool isValid(int row, int col, int num) {
    // Check if the given number already exists in the same row or column as the given position.
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    // Calculate the position of the top-left corner of the 3x3 box containing the given position.
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    // Check if the given number already exists in the 3x3 box containing the given position.
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    // If the number can be placed in the given position without violating any game rules, return true.
    return true;
}


// This function prints the current state of the Sudoku board.
void printBoard() {
    // Loop over every row and column of the board.
    for (int r = 0; r < SIZE; r++) {
        // Print a horizontal line to separate the 3x3 boxes.
        printf("\n---------------------\n");
        for (int c = 0; c < SIZE; c++) {
            // Print the value of the current cell, along with vertical lines to separate the cells in the same row.
            printf("%s  %c  %s ", c < 3 ? "|" : "", board[r][c] == 0 ? ' ' : board[r][c] + '0', c == 2 ? "|" : "");
        }
    }
    // Print a final horizontal line to complete the board.
    printf("\n---------------------\n");
}


// This function loads the initial state of the Sudoku board, either by generating random values or by asking the user for input.
void loadBoard() {
    // Initialize a count of how many cells have been filled in so far.
    int count = 0;
    if(first_game == 0){
        // Copy the values from firstboard to board.
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                board[i][j] = firstboard[i][j];
                if(firstboard[i][j] != 0){
                    count++;
                }
            }
        }
        first_game++;
    }

    else if (first_game > 0){
        // Seed the random number generator with the current time.
        srand(time(NULL));
        // Fill in 6 random cells to start with.
        while (count < 6) {
            // Choose a random row and column.
            int r = rand() % SIZE;
            int c = rand() % SIZE;
            // If the cell is empty...
            if (board[r][c] == 0) {
                // Choose a random number between 1 and 9...
                int num = rand() % MAX_VALUE + 1;
                // If the number is valid in this cell...
                if (isValid(r, c, num)) {
                    // Fill in the cell with the number.
                    board[r][c] = num;
                    // Increment the count of filled cells.
                    count++;
                }
            }
        }
    }
        // Print out the initial state of the board.
        printBoard();

        // Fill in the remaining cells by asking the user for input.
        int pos, row, col, num;
        start = clock();
        while (count < SIZE * SIZE) {
            // Ask the user for input.
            printf("Enter row (1-3), column (1-3), and number (1-9) (separated by spaces): ");
            scanf("%d %d %d", &row, &col, &num);
            // Convert the input to zero-based indices.
            row--;
            col--;
            // If the input is valid...
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE &&
                num >= 1 && num <= MAX_VALUE && board[row][col] == 0 &&
                isValid(row, col, num)) {
                // Fill in the cell with the number.
                board[row][col] = num;
                // Increment the count of filled cells.
                count++;
                // Print out the updated state of the board.
                printBoard();
            } else {
                // If the input is not valid, print an error message and try again.
                printf("Invalid input, try again.\n");
            }
        }
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    }