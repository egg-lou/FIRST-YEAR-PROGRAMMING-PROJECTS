#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3
#define MAX_VALUE 9

int SudokuElements[] = {1,2,3,4,5,6,7,8,9};
int board [SIZE][SIZE];

void loader(int getData);
void printBoard();
void solver();
bool isValid(int row, int col, int num);
void cleanBoard();

int main() {
    int dataNums = 0;
    int counter = 1;
    int show = 0;
    int again = 0;

    do {
        if (counter > 1)
            system("cls");

        printf("\n3x3 Sudoku Solver");
        printf("\n===================");

        while (dataNums < 1 || dataNums > 6) {
            printf("\n\nMinimum of [1] Number and Maximum of [6] Numbers");
            printf("\nHow many numbers you want to input in the board?");
            printf("\nResponse: ");
            scanf("%d", &dataNums);

            if (dataNums < 1 || dataNums > 6)
                printf("\nINVALID INPUT!!!");
        }

        loader(dataNums);

        show = 0;
        while (show != 1) {
            printf("\nShow Solved Board? Press [1] to show");
            printf("\nResponse: ");
            scanf("%d", &show);
            if (show != 1)
                printf("\nINVALID INPUT!!!");
        }

        printf("\nCompleted 3x3 Board");
        solver();
        counter++;

        again = 0;
        while (again != 1 && again != 2) {
            printf("\nDo you want to try again? (1 = Yes, 2 = No)");
            printf("\nResponse: ");
            scanf("%d", &again);

            if (again != 1 && again != 2)
                printf("\nINVALID INPUT!!! Valid options are 1 and 2.");
        }

        if (again == 1) {
            cleanBoard();
            dataNums = 0;
        }

    } while (again == 1);

    printf("\nThank you for using the Program!!!");

    return 0;
}

void cleanBoard() {
    int row, col; // Declare row and column variables
    for (row = 0; row < SIZE; row++) { // Iterate through each row of the board
        for (col = 0; col < SIZE; col++) { // Iterate through each column of the row
            board[row][col] = 0; // Set the value of the cell to 0
        }
    }
}

void printBoard() {
    for (int r = 0; r < SIZE; r++) { // Iterate through each row of the board
        printf("\n---------------------\n"); // Print a horizontal line before each row
        for (int c = 0; c < SIZE; c++) { // Iterate through each column of the row
            printf("%s  %c  %s ", c < SIZE ? "|" : "", board[r][c] == 0 ? ' ' : board[r][c] + '0', c == SIZE - 1 ? "|" : "");
            // If the cell is empty, print a space; otherwise, print the number in the cell
            // If it is the last column of the row, print a vertical line after the number
        }
    }
    printf("\n---------------------\n"); // Print a horizontal line after the last row
}


bool isValid(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) { // Check the row and column of the cell for the input number
        if (board[row][i] == num || board[i][col] == num) {
            return false; // If the input number is already present in the row or column, return false
        }
    }
    int boxRow = row - row % SIZE; // Calculate the top row index of the 3x3 box containing the cell
    int boxCol = col - col % SIZE; // Calculate the left column index of the 3x3 box containing the cell
    for (int i = boxRow; i < boxRow + SIZE; i++) { // Check the 3x3 box containing the cell for the input number
        for (int j = boxCol; j < boxCol + SIZE; j++) {
            if (board[i][j] == num) {
                return false; // If the input number is already present in the 3x3 box, return false
            }
        }
    }
    return true; // If the input number is not already present in the row, column, or 3x3 box, return true
}


// Loader Function for user input
void loader(int getData){
    
    if (getData == 0) // If there is no data to load, exit the function
        return;

    int count = 0; // Initialize counter to 0
    printBoard(); // Print the empty board
    int row, col, num;
    while (count < getData) { // Loop until the specified number of cells have been loaded with valid values
        printf("Enter row (1-3), column (1-3), and number (1-9) (separated by spaces): ");
        scanf("%d %d %d", &row, &col, &num); // Read user input for row, column, and number
        row--; // Adjust input values to 0-based indexing
        col--;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && // Check if the input values are within valid range and the cell is empty
            num >= 1 && num <= MAX_VALUE && board[row][col] == 0 &&
            isValid(row, col, num)) { // Check if the input number is valid for the cell
            board[row][col] = num; // Assign the input number to the cell
            count++; // Increment the counter for loaded cells
            printBoard(); // Print the board after each valid input
        } else {
            printf("Invalid input, try again.\n"); // Prompt the user to enter valid input
        }
    }
}


// Solver Function to solve the Sudoku Board
void solver() {
    int count = 0; // Initialize counter to 0
    for (int row = 0; row < 3; row++) { // Loop through each row of the 3x3 board
        for (int col = 0; col < 3; col++) { // Loop through each column of the 3x3 board
            if (board[row][col] == 0) {  // Check if the cell is empty (value=0)
                while (count < MAX_VALUE && SudokuElements[count] == 0) { // Look for the next non-zero number in the list
                    count++;
                }
                if (count >= MAX_VALUE) { // If the list has been exhausted and no valid number was found, exit the function
                    printf("Invalid board state\n");
                    return;
                }
                int num = SudokuElements[count]; // Store the next valid number in the list
                bool found = false;
                while (!found && count < MAX_VALUE) { // Keep looking for a valid number until one is found or the list is exhausted
                    if (isValid(row, col, num)) { // Check if the number is valid in the current cell
                        board[row][col] = num; // Assign the number to the cell
                        found = true; // Indicate that a valid number was found and assigned
                    } else {
                        count++; // Look for the next number in the list
                        if (count < MAX_VALUE) {
                            num = SudokuElements[count]; // Store the next valid number in the list
                        }
                    }
                }
                if (!found) { // If no valid number was found, exit the function
                    printf("Invalid board state\n");
                    return;
                }
            }
        }
    }
    printBoard(); // If all cells have been assigned valid values, print the solved board
}

