#include <stdio.h>

int main()
{
    int rows, number = 0;

    printf("ROWS: ");
    scanf("%d", &rows);

    int spacing = rows - 1;

    for (int i = 1; i <= rows; i++){
        for (int appendSpace = spacing--; appendSpace >= 1; appendSpace--)
            printf("  ");
        
        for (int numbers = 1; numbers <= i; numbers++)
            printf("%-3d ", ++number);

        printf("\n");
    }
}