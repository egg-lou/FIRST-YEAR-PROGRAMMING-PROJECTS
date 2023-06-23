#include <stdio.h>

#define ROWS 3
#define COLS 3

void PrintArray(double *p);
void SortArray (double *p);

int main()
{
    double numbers[ROWS][COLS] = {{5.4, 4.2, 1.3},
                                  {1.5, 7.3, 5.1},
                                  {8.3, 3.1, 2.1}};
    double *p;
    p = numbers[0];

    PrintArray(p);

    printf("\nSORTED\n");

    SortArray(p);
    PrintArray(p);
}

void SortArray (double *p){
    //BYPASSING THROUGH ARRAY
    for (int i = 0; i < ROWS * COLS; i++) 
        for (int j = 0; j < ROWS * COLS - 1; j++) 
            if (*(p + j) > *(p + j + 1)){
                double temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }

    //THROUGH ROW AND COLUMNS
    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS - 1; j++) {
    //         for (int k = 0; k < COLS - j - 1; k++) {
    //             if (*(p + i * COLS + k) > *(p + i * COLS + k + 1)){
    //                 double temp = *(p + i * COLS + k);
    //                 *(p + i * COLS + k) = *(p + i * COLS + k + 1);
    //                 *(p + i * COLS + k + 1) = temp;
    //             }
    //         }
    //     }
    // }
}

void PrintArray(double *p){
    //BYPASSING THROUGH ARRAY
    for(int i = 0; i < ROWS * COLS; i++)
        printf("NUMBER: %g\n", *(p + i));

    //THROUGH ROW AND COLUMNS
    // for (int i = 0; i < ROWS; i++)
    //     for (int j = 0; j < COLS; j++)
    //         printf("NUMBER: %g\n", *(p + i * COLS + j));
}