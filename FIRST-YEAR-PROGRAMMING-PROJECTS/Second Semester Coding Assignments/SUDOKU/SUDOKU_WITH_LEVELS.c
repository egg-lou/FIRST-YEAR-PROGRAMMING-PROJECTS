#include <stdio.h>


#define SIZE 9

int board [SIZE][SIZE]; 
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


int solveSudoku(int x, int y){
    int num = 1;
    int temp_x = 0;
    int temp_y = 0;

    if(x == 9 && y == 9){
        return 1;
    }
    if(board[x][y] !=  0){
        if(x < 8){
            temp_x = x + 1; 
            temp_y = y;      
        }
        else{
           temp_x = 0;
            temp_y = y + 1;  
        }
    if(solveSudoku(temp_x, temp_y)){
        return 1;
    }else{
        return 0;
    }
}
    
    if(board [x][y] == 0){
        while(num < 10){
            if(!sameSquare(x, y, num) && !sameRow(x, y, num) && !sameColumn(x, y, num)){
                board[x][y] = num;
                if(x == 8 && y == 8){
                    return 1;
                }
                if(x < 8){
                    temp_x = x + 1;
                }
                else{
                    temp_x = 0;
                    temp_y = y + 1;
                }   

                if(solveSudoku(temp_x, temp_y)){
                    return 1;
                }
            }
            num++;
        }
        if(x == 0 && y == 0){
            printf("\nNO SOLUTION\n");
        }

        board[x][y] = 0;
        return 0;
    }
    return 0;
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
