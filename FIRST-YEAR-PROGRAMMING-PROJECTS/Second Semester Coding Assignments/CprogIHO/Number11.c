#include <stdio.h>

void RightTriangle(int rows){
    int i, j;
    int num = 1;


    for(i = 1; i <= rows; i++){
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

    RightTriangle(rows);


    return 0;
}
