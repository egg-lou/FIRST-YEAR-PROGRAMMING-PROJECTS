#include <stdio.h>
void main()
{
    int rows, number = 0;

    printf("ROWS: ");
    scanf("%d", &rows);

    int spacing = rows - 1;

    for (int i = 1; i <= rows; i++){
        for (int appendSpace = spacing--; appendSpace >= 1; appendSpace--)
            printf(" ");
        
        for (int numbers = 1; numbers <= i; numbers++)
            printf("%d ", ++number);

        printf("\n");
    }
}