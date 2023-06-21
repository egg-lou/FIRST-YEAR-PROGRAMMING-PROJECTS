#include <stdio.h>

void pyramid(int rows){

    int i, j, space, num = 1;


    for(i = 1; i <= rows; i++){

        for(space = 1; space <= rows - i; space++){
            printf(" ");
        }

        for(j = 1; j <= i; j++){
            printf("%d ", num);
            num++;
        }
    printf("\n");
    }
}

int main(){

    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    pyramid(rows);


    return 0;
}