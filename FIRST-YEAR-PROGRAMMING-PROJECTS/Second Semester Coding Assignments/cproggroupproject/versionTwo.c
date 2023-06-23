#include <stdio.h>

#define ROWS 3
#define COLS 3

void PrintArray(double numbers[][COLS]);
void SortArray (double numbers[][COLS]);

int main()
{
    double numbers[ROWS][COLS] = {{5.4, 4.2, 1.3},
                                  {1.5, 7.3, 5.1},
                                  {8.3, 3.1, 2.1}};

    PrintArray(numbers);

    printf("\nSORTED\n");

    SortArray(numbers);
    PrintArray(numbers);
}

void SortArray (double numbers[][COLS]){
    //BYPASSING THROUGH ARRAY
    for (int i = 0; i < ROWS * COLS; i++) 
        for (int j = 0; j < ROWS * COLS - 1; j++) 
            if (*(*(numbers) + j) > *(*(numbers) + j + 1)){
                double temp = *(*(numbers) + j);
                *(*(numbers) + j) = *(*(numbers) + j + 1);
                *(*(numbers) + j + 1) = temp;
            }

    //THROUGH ROW AND COLUMNS
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS - 1; j++) {
    //         for (int k = 0; k < COLS - j - 1; k++) {
    //             if (*(*(numbers + i) + k) > *(*(numbers + i) + k + 1)){
    //                 double temp = *(*(numbers + i) + k);
    //                 *(*(numbers + i) + k) = *(*(numbers + i) + k + 1);
    //                 *(*(numbers + i) + k + 1) = temp;
    //             }
    //         }
    //     }
    // }
}

void PrintArray(double numbers[][COLS]){
    //BYPASSING THROUGH ARRAY
    for(int i = 0; i < ROWS * COLS; i++)
        printf("NUMBER: %g\n", *(*(numbers) + i));

    //THROUGH ROW AND COLUMNS
    // for (int i = 0; i < ROWS; i++)
    //     for (int j = 0; j < COLS; j++)
    //         printf("NUMBER: %g\n", *(*(numbers) + i) + j);
}