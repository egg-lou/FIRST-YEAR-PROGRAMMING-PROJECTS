#include <stdio.h>

int main()
{
    int rows;
    printf("ROWS: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++){
        for (int j = i; j >= 1; j--)
            printf("%-2d", i);
        printf("\n");
    }
}