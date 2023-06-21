#include <stdio.h>

void printFloydTriangle(int rows){
    int i, j, num = 1;

    for(i = 1; i <= rows; i++){
        for(j = 1; j <= i; j++){
            printf("%d", num);
            num = 1 - num;
        }
        printf("\n");
    }
}

int main(){

    int row;

    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printFloydTriangle(row);

    return 0;
}
