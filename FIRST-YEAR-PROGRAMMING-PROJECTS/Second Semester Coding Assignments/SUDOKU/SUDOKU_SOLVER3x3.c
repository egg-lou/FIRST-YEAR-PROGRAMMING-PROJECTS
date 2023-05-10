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
bool isValidInput(int row, int col, int num);
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
    int row, col; 
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            board[row][col] = 0;
        }
    }
}

void printBoard() {
    for (int r = 0; r < SIZE; r++) {
        printf("\n---------------------\n");
        for (int c = 0; c < SIZE; c++) {
            printf("%s  %c  %s ", c < SIZE ? "|" : "", board[r][c] == 0 ? ' ' : board[r][c] + '0', c == SIZE - 1 ? "|" : "");
        }
    }
    printf("\n---------------------\n");
}

bool isValid(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int boxRow = row - row % SIZE;
    int boxCol = col - col % SIZE;
    for (int i = boxRow; i < boxRow + SIZE; i++) {
        for (int j = boxCol; j < boxCol + SIZE; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

void loader(int getData){
    
    if (getData == 0)
        return;

    int count = 0;
    printBoard();
    int row, col, num;
    while (count < getData) {
        printf("Enter row (1-3), column (1-3), and number (1-9) (separated by spaces): ");
        scanf("%d %d %d", &row, &col, &num);
        row--;
        col--;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE &&
            num >= 1 && num <= MAX_VALUE && board[row][col] == 0 &&
            isValid(row, col, num)) {
            board[row][col] = num;
            count++;
            printBoard();
        } else {
            printf("Invalid input, try again.\n");
        }
    }
}

void solver() {
    int count = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == 0) {
                while (count < MAX_VALUE && SudokuElements[count] == 0) {
                    count++;
                }
                if (count >= MAX_VALUE) {
                    printf("Invalid board state\n");
                    return;
                }
                int num = SudokuElements[count];
                bool found = false;
                while (!found && count < MAX_VALUE) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        found = true;
                    } else {
                        count++;
                        if (count < MAX_VALUE) {
                            num = SudokuElements[count];
                        }
                    }
                }
                if (!found) {
                    printf("Invalid board state\n");
                    return;
                }
            }
        }
    }
    printBoard();
}
