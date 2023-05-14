#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

void maincontrols(int userChoice);


#define SIZE3x3 3
#define MAX_VALUE3x3 9
#define SIZE4x4 4
#define MAX_VALUE4x4 4
#define SIZE9x9 9
#define MAX_VALUE9x9 9



int SudokuElements3x3[] = {1,2,3,4,5,6,7,8,9};
int board3x3 [SIZE3x3][SIZE3x3];
int customBoard3x3 [SIZE3x3][SIZE3x3] = {  4, 0, 0,
                                           0, 0, 7,
                                           9, 0, 0
                                        };
void loader3x3(int level, int getData);
void printBoard3x3();
void solver3x3();
bool isValid3x3(int row, int col, int num);
void cleanBoard3x3();



int board4x4 [SIZE4x4][SIZE4x4]; 
int customBoard4x4 [SIZE4x4][SIZE4x4] = {   0,4,  0,0,     
                                            0,0,  0,4,  

                                            0,0,  2,3,
                                            2,3,  0,0,
                                        };
void printBoard4x4();
int solveSudoku4x4(int x, int y);
int sameColumn4x4(int x, int y, int num);
int sameRow4x4(int x, int y, int num);
int sameSquare4x4(int x, int y, int num);
void generateBoard4x4(int level);
void printOptions();
void cleanBoard4x4();



int board9x9 [SIZE9x9][SIZE9x9]; 
int customBoard9x9[SIZE9x9][SIZE9x9] = {0, 0, 0,     0, 5, 0,    8, 0, 0,
                                        7, 0, 0,     0, 0, 0,    0, 0, 1,
                                        6, 5, 3,     0, 0, 0,    9, 0, 0,

                                        0, 2, 0,     5, 0, 0,    0, 0, 0,
                                        0, 0, 8,     6, 3, 4,    7, 0, 0,
                                        0, 0, 0,     0, 0, 9,    0, 6, 0,

                                        0, 0, 1,     0, 0, 0,    2, 3, 5,
                                        2, 0, 0,     0, 0, 0,    0, 0, 7,
                                        0, 0, 4,     0, 7, 0,    0, 0, 0};
void printBoard9x9();
int solveSudoku9x9(int x, int y);
int sameColumn9x9(int x, int y, int num);
int sameRow9x9(int x, int y, int num);
int sameSquare9x9(int x, int y, int num);
void generateBoard9x9(int level);
void cleanBoard9x9();


int main(){
    int userChoice;

    do{
        printf("\nWELCOME TO THE SUDOKU SOLVER");
        printf("\nLooking for a 3x3 Solver? 4x4 Solver? or a 9x9 Solver?");
        printf("\nWe've got it here all for you!!!");

        do{
            printf("\n\nAVAILABLE SUDOKU BOARD SOLVERS:");
            printf("\n[1] 3x3 Sudoku Solver");
            printf("\n[2] 4x4 Sudoku Solver");
            printf("\n[3] 9x9 Sudoku Solver");
            printf("\n[4] EXIT");

            printf("\n===========");
            printf("\nResponse: ");
            scanf("%d", &userChoice);
            if(userChoice < 1 || userChoice > 4)
                printf("\nINVALID INPUT!!!");
        }while(userChoice < 1 || userChoice > 4);
        if(userChoice == 4)
            break;

        if(userChoice >= 1 && userChoice <= 3){
            maincontrols(userChoice);
            system("cls");
        }

    }while(userChoice >= 1 && userChoice <= 3);

    printf("\nThank you for using the SUDOKU SOLVER");
    getch();
    return 0;
}

void maincontrols(int userChoice){
switch(userChoice) {
    case 1: {
        system("cls");
        int dataNums = 0;
        int counter = 1;
        int show = 0;
        int again = 0;
        int level, custom;

        do {
            if (counter > 1) {
                system("cls");
            }

            printf("\n3x3 Sudoku Solver");
            printf("\n===================");

            printOptions();
            printf("\nResponse: ");
            scanf("%d", &level);

            if(level >=1 && level <= 3){
                loader3x3(level, 10);
            }

            else if(level == 4){
                do{
                    printf("\nLoad the custom board or input yourself? [1] for CUSTOM and [2] for INPUT");
                    printf("\nResponse: ");
                    scanf("%d", &custom);

                    if(custom != 1 && custom != 2)
                        printf("\nINVALID INPUT!!!");
                }while(custom != 1 && custom != 2);

                    if(custom == 1){
                        for(int i  = 0; i < SIZE3x3; i++){
                            for(int j = 0; j < SIZE3x3; j++){
                                board3x3[i][j] = customBoard3x3[i][j];
                            }   
                        }
                        printBoard3x3();
                    }
                    else if(custom == 2){
                        while (dataNums < 1 || dataNums > 6) {
                            printf("\n\nMinimum of [1] Number and Maximum of [6] Numbers");
                            printf("\nHow many numbers you want to input in the board?");
                            printf("\nResponse: ");
                            scanf("%d", &dataNums);

                            if (dataNums < 1 || dataNums > 6) {
                                printf("\nINVALID INPUT!!!");
                                }
                        }
                            loader3x3(level, dataNums);
                            printBoard3x3();
                }
            }

            show = 0;
            while (show != 1) {
                printf("\nShow Solved Board? Press [1] to show");
                printf("\nResponse: ");
                scanf("%d", &show);
                if (show != 1) {
                    printf("\nINVALID INPUT!!!");
                }
            }

            printf("\nCompleted 3x3 Board");
            solver3x3();
            counter++;

            again = 0;
            while (again != 1 && again != 2) {
                printf("\nDo you want to try again? (1 = Yes, 2 = No)");
                printf("\nResponse: ");
                scanf("%d", &again);

                if (again != 1 && again != 2) {
                    printf("\nINVALID INPUT!!! Valid options are 1 and 2.");
                }
            }

            if (again == 1) {
                cleanBoard3x3();
                dataNums = 0;
            }

        } while (again == 1);

        break;
    }


    case 2: {
    system("cls");
    int x = 0;
    int y = 0;
    int userResponse, show, again;
    printf("\n4x4 SUDOKU SOLVER");
    printf("\n===================");
    

    do {
        printOptions();
        do {
            printf("\nResponse: ");
            scanf("%d", &userResponse);

            if(userResponse < 1 || userResponse > 5) {
                printf("\nINVALID INPUT!");
            }
        
        } while(userResponse < 1 || userResponse > 5);

        if(userResponse == 5) {
            break;
        }
        if(userResponse >= 1 && userResponse <= 4) {
            generateBoard4x4(userResponse);
            printf("\nShow Solved Board? [1] for YES and [2] for NO");

            do {
                printf("\nResponse: ");
                scanf("%d", &show);

                if(show != 1 && show != 2) {
                    printf("\nINVALID INPUT!!! Valid options are 1 and 2.");
                }

            } while(show != 1 && show != 2);

            solveSudoku4x4(x, y);
            printf("\nCompleted 4x4 Board:\n");
            printBoard4x4();

            printf("\nDo you want to try again? (1 = Yes, 2 = No)");
            printf("\nResponse: ");
            do {
                scanf("%d", &again);
                if(again != 1 && again != 2) {
                    printf("\nINVALID INPUT!!! Valid options are 1 and 2.");
                }

            } while(again != 1 && again != 2);
            
            if(again == 1) {
                cleanBoard4x4();
                system("cls");
            }
        }
    } while(again == 1);
    break;
}

    case 3: {
        system("cls");
        int x = 0;
        int y = 0;
        int userResponse, show, again;
        printf("\n9x9 SUDOKU SOLVER");
        printf("\n===================");

        do {
            printOptions();
            do {
                printf("\nResponse: ");
                scanf("%d", &userResponse);

                if(userResponse < 1 || userResponse > 5)
                    printf("\nINVALID INPUT!!! Valid options are 1 to 2.");
                
            } while(userResponse < 1 || userResponse > 5);

            if(userResponse == 5)
                break;
                
            if(userResponse >= 1 && userResponse <= 4){
                generateBoard9x9(userResponse);
                printf("\nShow Solved Board? [1] for YES and [2] for NO");

                do {
                    printf("\nResponse: ");
                    scanf("%d", &show);

                    if(show != 1 && show != 2)
                        printf("\nINVALID INPUT!!! Valid options are 1 and 2.");

                } while(show != 1 && show != 2);

                solveSudoku9x9(x, y);
                printf("\nComplete Board:\n");
                printBoard9x9();

                printf("\nDo you want to try again? (1 = Yes, 2 = No)");
                printf("\nResponse: ");
                do {
                    scanf("%d", &again);
                    if(again != 1 && again != 2)
                        printf("\nINVALID INPUT!!! Valid options are 1 and 2.");

                } while(again != 1 && again != 2);
                
                if(again == 1){
                    cleanBoard9x9();
                    system("cls");
                }
            }
        } while(again == 1);

        break;
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

void cleanBoard3x3() {
    int row, col; // Declare row and column variables
    for (row = 0; row < SIZE3x3; row++) { // Iterate through each row of the board
        for (col = 0; col < SIZE3x3; col++) { // Iterate through each column of the row
            board3x3[row][col] = 0; // Set the value of the cell to 0
        }
    }
}

void printBoard3x3() {
    for (int r = 0; r < SIZE3x3; r++) { 
                printf("\n\t------------------------\n"); 
                for (int c = 0; c < SIZE3x3; c++) { 
                    printf("\t");
                    printf("%s  %c  %s ", c < SIZE3x3 ? "|" : "", board3x3[r][c] == 0 ? ' ' : board3x3[r][c] + '0', c == SIZE3x3 - 1 ? " |" : "");
                }
                printf("\t");
            }
            printf("\n\t------------------------\n");  // Print a horizontal line after the last row
}

bool isValid3x3(int row, int col, int num) {
    for (int i = 0; i < SIZE3x3; i++) { // Check the row and column of the cell for the input number
        if (board3x3[row][i] == num || board3x3[i][col] == num) {
            return false; // If the input number is already present in the row or column, return false
        }
    }
    int boxRow = row - row % SIZE3x3; // Calculate the top row index of the 3x3 box containing the cell
    int boxCol = col - col % SIZE3x3; // Calculate the left column index of the 3x3 box containing the cell
    for (int i = boxRow; i < boxRow + SIZE3x3; i++) { // Check the 3x3 box containing the cell for the input number
        for (int j = boxCol; j < boxCol + SIZE3x3; j++) {
            if (board3x3[i][j] == num) {
                return false; // If the input number is already present in the 3x3 box, return false
            }
        }
    }
    return true; // If the input number is not already present in the row, column, or 3x3 box, return true
}

void loader3x3(int level, int getData){
    
    if (getData == 0) // If there is no data to load, exit the function
        return;



    if(level == 4){
        int count = 0; // Initialize counter to 0
        printBoard3x3(); // Print the empty board
        int row, col, num;
        while (count < getData) { // Loop until the specified number of cells have been loaded with valid values
            printf("Enter row (1-3), column (1-3), and number (1-9) (separated by spaces): ");
            scanf("%d %d %d", &row, &col, &num); // Read user input for row, column, and number
            row--; // Adjust input values to 0-based indexing
            col--;
            if (row >= 0 && row < SIZE3x3 && col >= 0 && col < SIZE3x3 && // Check if the input values are within valid range and the cell is empty
                num >= 1 && num <= MAX_VALUE3x3 && board3x3[row][col] == 0 &&
                isValid3x3(row, col, num)) { // Check if the input number is valid for the cell
                board3x3[row][col] = num; // Assign the input number to the cell
                count++; // Increment the counter for loaded cells
                printBoard3x3(); // Print the board after each valid input
            } else {
                printf("Invalid input, try again.\n"); // Prompt the user to enter valid input
            }
        }
    }

    else if(level >= 1 && level <= 3 && getData == 10){
            int count = 0;
            int nums_to_add = 0;

            switch(level){
                case 1: {
                    nums_to_add = 6;
                    break;
                }
                case 2: {
                    nums_to_add = 4;
                    break;
                }
                case 3: {
                    nums_to_add = 2;
                    break;
                }
            }
            // Seed the random number generator with the current time.
            srand(time(NULL));
            // Fill in 6 random cells to start with.
            while (count < nums_to_add) {
                // Choose a random row and column.
                int r = rand() % SIZE3x3;
                int c = rand() % SIZE3x3;
                // If the cell is empty...
                if (board3x3[r][c] == 0) {
                    // Choose a random number between 1 and 9...
                    int num = rand() % MAX_VALUE3x3 + 1;
                    // If the number is valid in this cell...
                    if (isValid3x3(r, c, num)) {
                        // Fill in the cell with the number.
                        board3x3[r][c] = num;
                        // Increment the count of filled cells.
                        count++;
                    }
                }
            }
            printBoard3x3();
        }
}

void solver3x3() {
    int count = 0; // Initialize counter to 0
    for (int row = 0; row < 3; row++) { // Loop through each row of the 3x3 board
        for (int col = 0; col < 3; col++) { // Loop through each column of the 3x3 board
            if (board3x3[row][col] == 0) {  // Check if the cell is empty (value=0)
                while (count < MAX_VALUE3x3 && SudokuElements3x3[count] == 0) { // Look for the next non-zero number in the list
                    count++;
                }
                if (count >= MAX_VALUE3x3) { // If the list has been exhausted and no valid number was found, exit the function
                    printf("Invalid board state\n");
                    return;
                }
                int num = SudokuElements3x3[count]; // Store the next valid number in the list
                bool found = false;
                while (!found && count < MAX_VALUE3x3) { // Keep looking for a valid number until one is found or the list is exhausted
                    if (isValid3x3(row, col, num)) { // Check if the number is valid in the current cell
                        board3x3[row][col] = num; // Assign the number to the cell
                        found = true; // Indicate that a valid number was found and assigned
                    } else {
                        count++; // Look for the next number in the list
                        if (count < MAX_VALUE3x3) {
                            num = SudokuElements3x3[count]; // Store the next valid number in the list
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
    printBoard3x3(); // If all cells have been assigned valid values, print the solved board
}



void cleanBoard4x4(){

    // Clear the board
    for(int i = 0; i < SIZE4x4; i++){
        for(int j = 0; j < SIZE4x4; j++){
            board4x4[i][j] = 0;
        }
    }
}

void printBoard4x4() {
    for (int r = 0; r < SIZE4x4; r++) { 
                printf("\n\t+-------+-------+-------+------+\n"); 
                for (int c = 0; c < SIZE4x4; c++) {
                    printf("\t");
                    printf("%s  %c  %s ", c < SIZE4x4 ? "|" : "", board4x4[r][c] == 0 ? ' ' : board4x4[r][c] + '0', c == SIZE4x4 - 1 ? " |" : "");
                }
            }
            printf("\n\t+-------+-------+-------+------+\n"); 
}

int solveSudoku4x4(int x, int y) {
    if (x == SIZE4x4) {
        return 1; // solution found
    }
    if (board4x4[x][y] != 0) {
        if (y == SIZE4x4 - 1) {
            return solveSudoku4x4(x + 1, 0); // move to next row
        } else {
            return solveSudoku4x4(x, y + 1); // move to next column
        }
    }
    for (int num = 1; num <= SIZE4x4; num++) {
        if (!sameRow4x4(x, y, num) && !sameColumn4x4(x, y, num) && !sameSquare4x4(x, y, num)) {
            board4x4[x][y] = num;
            if (y == SIZE4x4 - 1) {
                if (solveSudoku4x4(x + 1, 0)) {
                    return 1; // solution found
                }
            } else {
                if (solveSudoku4x4(x, y + 1)) {
                    return 1; // solution found
                }
            }
            board4x4[x][y] = 0; // backtrack
        }
    }
    return 0; // no solution found
}

int sameRow4x4(int x, int y, int num){
    for(int i = 0; i < SIZE4x4; i++){
        if(board4x4[i][y] == num){
            return 1;
        }
    }
    return 0;
}

int sameColumn4x4(int x, int y, int num){
    for(int i = 0; i < SIZE4x4; i++){
        if(board4x4[x][i] == num){
            return 1;
        }
    }
    return 0;
}

int sameSquare4x4(int x, int y, int num){
    int rowStart = (x / 2) * 2;
    int colStart = (y / 2) * 2;

    for (int i = rowStart; i < rowStart + 2; i++){
        for (int j = colStart; j < colStart + 2; j++){
            if(board4x4[i][j] == num){
                return 1;
            }
        }
    }
    return 0;
}

void generateBoard4x4(int level){

    int i, j, num, row, col, count, cells_to_delete, custom;
    bool solvable;
    int nums_to_delete, nums_to_add;

    cleanBoard4x4();

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
            for(i  = 0; i < SIZE4x4; i++){
                for(j = 0; j < SIZE4x4; j++){
                    board4x4[i][j] = customBoard4x4[i][j];
                }
            }

        }
        
        else if(custom == 2){

            printf("\nEnter how many numbers that will be added: " );
            scanf("%d", &nums_to_add);
            
            // Fill in the remaining cells by asking the user for input.
            int row, col, num;
            while (count < nums_to_add) {
                printBoard4x4();
                // Ask the user for input.
                printf("Enter row (1-4), column (1-4), and number (1-4) (separated by spaces): ");
                scanf("%d %d %d", &row, &col, &num);
                // Convert the input to zero-based indices.
                row--;
                col--;
                // If the input is valid...
                if (row >= 0 && row < SIZE4x4 && col >= 0 && col < SIZE4x4 &&
                    num >= 1 && num <= MAX_VALUE4x4 && board4x4[row][col] == 0 &&
                    !sameSquare4x4(row, col, num) && !sameRow4x4(row, col, num) && !sameColumn4x4(row, col, num)) {
                    // Fill in the cell with the number.
                    board4x4[row][col] = num;
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
            case 1: nums_to_delete = 12; break;
            case 2: nums_to_delete = 8; break;
            case 3: nums_to_delete = 6; break;
        }
    

    cells_to_delete = (SIZE4x4 * SIZE4x4) - nums_to_delete;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a complete, valid Sudoku solution
    solvable = false;
    while(!solvable){
        // Generate random numbers for the first row
        for(i = 0; i < SIZE4x4; i++){
            num = rand() % SIZE4x4 + 1;
            while(sameRow4x4(0, i, num) || sameColumn4x4(0, i, num) || sameSquare4x4(0, i, num)){
                num = rand() % SIZE4x4 + 1;
            }
            board4x4[0][i] = num;
        }

        // Use backtracking to generate the rest of the solution
        solvable = solveSudoku4x4(1, 0);
    }
    if (!solvable) {
        printf("Failed to generate a solvable Sudoku board after 1000 attempts.\n");
        return;
    }

    // Remove numbers from the solution to create the desired difficulty level
    count = 0;
    while(count < cells_to_delete){
        // Choose a random cell to remove a number from
        row = rand() % SIZE4x4;
        col = rand() % SIZE4x4;
        if(board4x4[row][col] != 0){
            // Temporarily remove the number and check if the board is still solvable
            num = board4x4[row][col];
            board4x4[row][col] = 0;
            count++;
        }
    }
    }
    printBoard4x4();
}



void cleanBoard9x9(){

    // Clear the board
    for(int i = 0; i < SIZE9x9; i++){
        for(int j = 0; j < SIZE9x9; j++){
            board9x9[i][j] = 0;
        }
    }
}

void printBoard9x9(){

    for (int i = 0; i < 9; i++){
        if (i % 3 == 0 && i != 0)
            printf("\t-------------   -------------   -------------\n");
        printf("\t-------------   -------------   -------------\n\t");
        for (int j = 0; j < 9; j++){
            if (j % 3 == 0 && j != 0)
                printf("   ");

            (board9x9[i][j] != 0) ? printf("| %d ", board9x9[i][j]) : printf("|   ");

            if ((j + 1) % 3 == 0)
                printf("|");
        }
        printf("\n");
    }
    printf("\t-------------   -------------   -------------\n");
}

int solveSudoku9x9(int x, int y) {
    if (x == SIZE9x9) {
        return 1; // solution found
    }
    if (board9x9[x][y] != 0) {
        if (y == SIZE9x9 - 1) {
            return solveSudoku9x9(x + 1, 0); // move to next row
        } else {
            return solveSudoku9x9(x, y + 1); // move to next column
        }
    }
    for (int num = 1; num <= SIZE9x9; num++) {
        if (!sameRow9x9(x, y, num) && !sameColumn9x9(x, y, num) && !sameSquare9x9(x, y, num)) {
            board9x9[x][y] = num;
            if (y == SIZE9x9 - 1) {
                if (solveSudoku9x9(x + 1, 0)) {
                    return 1; // solution found
                }
            } else {
                if (solveSudoku9x9(x, y + 1)) {
                    return 1; // solution found
                }
            }
            board9x9[x][y] = 0; // backtrack
        }
    }
    return 0; // no solution found
}

int sameRow9x9(int x, int y, int num){
    for(int i = 0; i < SIZE9x9; i++){
        if(board9x9[i][y] == num){
            return 1;
        }
    }
    return 0;
}

int sameColumn9x9(int x, int y, int num){
    for(int i = 0; i < SIZE9x9; i++){
        if(board9x9[x][i] == num){
            return 1;
        }
    }
    return 0;
}

int sameSquare9x9(int x, int y, int num){
    int rowStart = (x / 3) * 3;
    int colStart = (y / 3) * 3;

    for (int i = rowStart; i < rowStart + 3; i++){
        for (int j = colStart; j < colStart + 3; j++){
            if(board9x9[i][j] == num){
                return 1;
            }
        }
    }

    return 0;
}

void generateBoard9x9(int level){
    int i, j, num, row, col, count, cells_to_delete, custom;
    bool solvable;
    int nums_to_delete, nums_to_add;

    cleanBoard9x9();

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
            for(i  = 0; i < SIZE9x9; i++){
                for(j = 0; j < SIZE9x9; j++){
                    board9x9[i][j] = customBoard9x9[i][j];
                }
            }

        }
        
        else if(custom == 2){

            printf("\nEnter how many numbers that will be added: " );
            scanf("%d", &nums_to_add);
            
            // Fill in the remaining cells by asking the user for input.
            int row, col, num;
            while (count < nums_to_add) {
                printBoard9x9();
                // Ask the user for input.
                printf("Enter row (1-9), column (1-9), and number (1-9) (separated by spaces): ");
                scanf("%d %d %d", &row, &col, &num);
                // Convert the input to zero-based indices.
                row--;
                col--;
                // If the input is valid...
                if (row >= 0 && row < SIZE9x9 && col >= 0 && col < SIZE9x9 &&
                    num >= 1 && num <= MAX_VALUE9x9 && board9x9[row][col] == 0 &&
                    !sameSquare9x9(row, col, num) && !sameRow9x9(row, col, num) && !sameColumn9x9(row, col, num)) {
                    // Fill in the cell with the number.
                    board9x9[row][col] = num;
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
    

    cells_to_delete = (SIZE9x9 * SIZE9x9) - nums_to_delete;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a complete, valid Sudoku solution
    solvable = false;
    while(!solvable){
        // Generate random numbers for the first row
        for(i = 0; i < SIZE9x9; i++){
            num = rand() % SIZE9x9 + 1;
            while(sameRow9x9(0, i, num) || sameColumn9x9(0, i, num) || sameSquare9x9(0, i, num)){
                num = rand() % SIZE9x9 + 1;
            }
            board9x9[0][i] = num;
        }

        // Use backtracking to generate the rest of the solution
        solvable = solveSudoku9x9(1, 0);
    }
    if (!solvable) {
        printf("Failed to generate a solvable Sudoku board after 1000 attempts.\n");
        return;
    }

    // Remove numbers from the solution to create the desired difficulty level
    count = 0;
    while(count < cells_to_delete){
        // Choose a random cell to remove a number from
        row = rand() % SIZE9x9;
        col = rand() % SIZE9x9;
        if(board9x9[row][col] != 0){
            // Temporarily remove the number and check if the board is still solvable
            num = board9x9[row][col];
            board9x9[row][col] = 0;
            count++;
        }
    }
    }
    printBoard9x9();
}
