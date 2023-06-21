#include <stdio.h>

int main()
{
    int rows, number = 0, i, j;
    printf("ROWS: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++){
        for (j = i; j >= 1; j--)
            printf("%-2d", ++number);
        printf("\n");
    }
}
