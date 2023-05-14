#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>


#define SIZE 9
#define MAX_VALUE 9

int board [SIZE][SIZE]; 
int customBoard[SIZE][SIZE] = {0, 0, 0,     0, 5, 0,    8, 0, 0,
                               7, 0, 0,     0, 0, 0,    0, 0, 1,
                               6, 5, 3,     0, 0, 0,    9, 0, 0,

                               0, 2, 0,     5, 0, 0,    0, 0, 0,
                               0, 0, 8,     6, 3, 4,    7, 0, 0,
                               0, 0, 0,     0, 0, 9,    0, 6, 0,

                               0, 0, 1,     0, 0, 0,    2, 3, 5,
                               2, 0, 0,     0, 0, 0,    0, 0, 7,
                               0, 0, 4,     0, 7, 0,    0, 0, 0};
void printBoard();
int solveSudoku(int x, int y);
int sameColumn(int x, int y, int num);
int sameRow(int x, int y, int num);
int sameSquare(int x, int y, int num);
void generateBoard(int level);
void printOptions();
void cleanBoard();


int main(){
    int x = 0;
    int y = 0;
    int userResponse, show, again;
    printf("\nSUDOKU SOLVER 9x9");


do {
    printOptions();
    do {
        printf("\nResponse: ");
        scanf("%d", &userResponse);

        if(userResponse < 1 || userResponse > 5)
            printf("\nINVALID INPUT!");
        
    } while(userResponse < 1 || userResponse > 5);

    if(userResponse == 5)
        break;
        
    if(userResponse >= 1 && userResponse <= 4){
        generateBoard(userResponse);
        printf("\nShow Solved Board? [1] for YES and [2] for NO");

        do {
            printf("\nResponse: ");
            scanf("%d", &show);

            if(show != 1 && show != 2)
                printf("\nINVALID INPUT!");

        } while(show != 1 && show != 2);

        solveSudoku(x, y);
        printf("\nComplete Board:\n");
        printBoard();

        printf("\nTRY AGAIN? [1] for YES [2] for NO");
        printf("\nResponse: ");
        do {
            scanf("%d", &again);
            if(again != 1 && again != 2)
                printf("\nINVALID INPUT!");

        } while(again != 1 && again != 2);
        
        if(again == 1){
            cleanBoard();
        }
    }
} while(again == 1);

printf("\nThank you for using the program!");
getch();

return 0;

}


void cleanBoard(){

    // Clear the board
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = 0;
        }
    }
}

void printOptions(){

    printf("\nChoose from [1] to [5]");
    printf("\n[1] Easy");
    printf("\n[2] Medium");
    printf("\n[3] Hard");
    printf("\n[4] Custom");
    printf("\n[5] Exit");

}

void printBoard(){

    for (int i = 0; i < 9; i++){
        if (i % 3 == 0 && i != 0)
            printf("\t-------------   -------------   -------------\n");
        printf("\t-------------   -------------   -------------\n\t");
        for (int j = 0; j < 9; j++){
            if (j % 3 == 0 && j != 0)
                printf("   ");

            (board[i][j] != 0) ? printf("| %d ", board[i][j]) : printf("|   ");

            if ((j + 1) % 3 == 0)
                printf("|");
        }
        printf("\n");
    }
    printf("\t-------------   -------------   -------------\n");
}

int solveSudoku(int x, int y) {
    if (x == SIZE) {
        return 1; // solution found
    }
    if (board[x][y] != 0) {
        if (y == SIZE - 1) {
            return solveSudoku(x + 1, 0); // move to next row
        } else {
            return solveSudoku(x, y + 1); // move to next column
        }
    }
    for (int num = 1; num <= SIZE; num++) {
        if (!sameRow(x, y, num) && !sameColumn(x, y, num) && !sameSquare(x, y, num)) {
            board[x][y] = num;
            if (y == SIZE - 1) {
                if (solveSudoku(x + 1, 0)) {
                    return 1; // solution found
                }
            } else {
                if (solveSudoku(x, y + 1)) {
                    return 1; // solution found
                }
            }
            board[x][y] = 0; // backtrack
        }
    }
    return 0; // no solution found
}


int sameRow(int x, int y, int num){
    for(int i = 0; i < SIZE; i++){
        if(board[i][y] == num){
            return 1;
        }
    }
    return 0;
}

int sameColumn(int x, int y, int num){
    for(int i = 0; i < SIZE; i++){
        if(board[x][i] == num){
            return 1;
        }
    }
    return 0;
}

int sameSquare(int x, int y, int num){
    int rowStart = (x / 3) * 3;
    int colStart = (y / 3) * 3;

    for (int i = rowStart; i < rowStart + 3; i++){
        for (int j = colStart; j < colStart + 3; j++){
            if(board[i][j] == num){
                return 1;
            }
        }
    }

    return 0;
}

void generateBoard(int level){
    int i, j, num, row, col, count, cells_to_delete, custom;
    bool solvable;
    int nums_to_delete, nums_to_add;

    cleanBoard();

    if(level == 4){
        int count = 0;
        do{
            printf("\nLoad the custom board or input yourself? [1] for CUSTOM and [2] for INPUT");
            printf("\nResponse: ");
            scanf("%d", &custom);

            if(custom != 1 && custom != 2)
                printf("\nINVALID INPUT!!!");
        }while(custom != 1 && custom != 2);

        if(custom == 1){
            for(i  = 0; i < SIZE; i++){
                for(j = 0; j < SIZE; j++){
                    board[i][j] = customBoard[i][j];
                }
            }

        }
        
        else if(custom == 2){

            printf("\nEnter how many numbers that will be added: " );
            scanf("%d", &nums_to_add);
            
            // Fill in the remaining cells by asking the user for input.
            int row, col, num;
            while (count < nums_to_add) {
                printBoard();
                // Ask the user for input.
                printf("Enter row (1-9), column (1-9), and number (1-9) (separated by spaces): ");
                scanf("%d %d %d", &row, &col, &num);
                // Convert the input to zero-based indices.
                row--;
                col--;
                // If the input is valid...
                if (row >= 0 && row < SIZE && col >= 0 && col < SIZE &&
                    num >= 1 && num <= MAX_VALUE && board[row][col] == 0 &&
                    !sameSquare(row, col, num) && !sameRow(row, col, num) && !sameColumn(row, col, num)) {
                    // Fill in the cell with the number.
                    board[row][col] = num;
                    // Increment the count of filled cells.
                    count++;
                    // Print out the updated state of the board.
                } else {
                    // If the input is not valid, print an error message and try again.
                    printf("Invalid input, try again.\n");
                }
            }
        }
    }

    // Determine the number of clues to add based on the difficulty level
    else if(level != 4){

    
        switch(level){
            case 1: nums_to_delete = 45; break;
            case 2: nums_to_delete = 25; break;
            case 3: nums_to_delete = 15; break;
            default: nums_to_delete = 45; break;
        }
    

    cells_to_delete = (SIZE * SIZE) - nums_to_delete;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a complete, valid Sudoku solution
    solvable = false;
    while(!solvable){
        // Generate random numbers for the first row
        for(i = 0; i < SIZE; i++){
            num = rand() % SIZE + 1;
            while(sameRow(0, i, num) || sameColumn(0, i, num) || sameSquare(0, i, num)){
                num = rand() % SIZE + 1;
            }
            board[0][i] = num;
        }

        // Use backtracking to generate the rest of the solution
        solvable = solveSudoku(1, 0);
    }
    if (!solvable) {
        printf("Failed to generate a solvable Sudoku board after 1000 attempts.\n");
        return;
    }

    // Remove numbers from the solution to create the desired difficulty level
    count = 0;
    while(count < cells_to_delete){
        // Choose a random cell to remove a number from
        row = rand() % SIZE;
        col = rand() % SIZE;
        if(board[row][col] != 0){
            // Temporarily remove the number and check if the board is still solvable
            num = board[row][col];
            board[row][col] = 0;
            count++;
        }
    }
    }
    printBoard();
}