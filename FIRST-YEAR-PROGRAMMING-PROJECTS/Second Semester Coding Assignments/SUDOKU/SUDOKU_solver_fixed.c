#include <stdio.h>


#define SIZE 9

int board [SIZE][SIZE] = {  5, 3, 0,   0, 7, 0,   0, 0, 0,
                            6, 0, 0,   1, 9, 5,   0, 0, 0,
                            0, 9, 8,   0, 0, 0,   0, 6, 0,

                            8, 0, 0,   0, 6, 0,   0, 0, 3,
                            4, 0, 0,   8, 0, 3,   0, 0, 1,
                            7, 0, 0,   0, 2, 0,   0, 0, 6,

                            0, 6, 0,   0, 0, 0,   2, 8, 0,
                            0, 0, 0,   4, 1, 9,   0, 0, 5,
                            0, 0, 0,   0, 8, 0,   0, 7, 9
    }; 

/*                          0,0,0,  0,0,0,  0,0,0,
                            0,0,0,  0,0,0,  0,0,0,
                            0,0,0,  0,0,0,  0,0,0,
                            
                            0,0,0,  0,0,0,  0,0,0,
                            0,0,0,  0,0,0,  0,0,0,
                            0,0,0,  0,0,0,  0,0,0,

                            0,0,0,  0,0,0,  0,0,0,
                            0,0,0,  0,0,0,  0,0,0,
                            0,0,0,  0,0,0,  0,0,0
*/
void printBoard();
int solveSudoku(int x, int y);
int sameColumn(int x, int y, int num);
int sameRow(int x, int y, int num);
int sameSquare(int x, int y, int num);


int main(){
    int x = 0;
    int y = 0;

    printBoard();
    solveSudoku(x,y);
    printBoard();




    return 0;
}


void printBoard() {
    printf("\n-------------------------------\n");
    // Loop over every row and column of the board.
    for (int r = 0; r < SIZE; r++) {
        printf("|");
        // Print a horizontal line to separate the 3x3 boxes.
        for (int c = 0; c < SIZE; c++) {
            printf(" %d ",board[r][c]);

            if((c + 1) % 3 == 0){
                printf("|");
            }
        }
        printf("\n");
        if((r + 1) % 3 == 0){
            printf("-------------------------------\n");
        }
    }
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
    if(x < 3){
        x = 0;
    }
    else if(x < 6){
        x = 3;
    }
    else{
        x = 6;
    }

    if(y < 3){
        y = 0;
    }
    else if(y < 6){
        y = 3;
    }
    else{
        y = 6;
    }

    for (int i = x; i < x + 3; i++){
        for (int j = y; j < y + 3; j++){
            if(board[i][j] == num){
                return 1;
            }
        }
    }

    return 0;
}