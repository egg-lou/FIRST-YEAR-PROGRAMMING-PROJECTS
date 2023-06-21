#include <stdio.h>

int main()
{
    int rows, number = 0;
    printf("ROWS: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++){
        number = (i % 2 == 0) ? 1 : 0;

        for (int j = i; j >= 1; j--){
            number = (number % 2 == 0) ? 1 : 0;
            printf("%d", number);
        }
        printf("\n");
    }
}

