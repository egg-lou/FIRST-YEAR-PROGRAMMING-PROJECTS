#include <stdio.h>
#include <malloc.h>

#define ROWS 3
#define COLS 3

void BubbleSort(double **numbers, int ifAscend);
void GetArray(double **numbers);
void PrintArray(double **numbers);

int main()
{
    double **numbers = (double**)malloc(ROWS * sizeof(double*));
    int ifAscend;

    for (int i = 0; i < ROWS; i++)
        *(numbers + i) = (double*)malloc(COLS * sizeof(double));

    GetArray(numbers);

    printf("============================================================\n");

    printf("\nENTER [1] FOR ASCENDING OR [2] FOR DESCENDING: ");
    scanf("%d", &ifAscend);

    printf("\n<== BEFORE SORTING ==>\n\n");
    PrintArray(numbers);

    printf("============================================================\n\n");

    BubbleSort(numbers, ifAscend);

    printf("<== AFTER SORTING ==>\n\n");
    PrintArray(numbers);
}

void BubbleSort(double **numbers, int ifAscend){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 1; j++) {
            for (int k = 0; k < COLS - j - 1; k++) {
                if ((*(*(numbers + i) + k) > *(*(numbers + i) + k + 1) && ifAscend == 1) || (*(*(numbers + i) + k) < *(*(numbers + i) + k + 1) && ifAscend == 2)) {
                    double temp = *(*(numbers + i) + k);
                    *(*(numbers + i) + k) = *(*(numbers + i) + k + 1);
                    *(*(numbers + i) + k + 1) = temp;
                }
            }
        }
    }
}

void GetArray(double **numbers){
    for (int i = 0; i < ROWS; i++){
        printf("ROW: %d\n", i + 1);
        for (int j = 0; j < COLS; j++){
            printf("Enter any number for [COLUMN %d]: ", j + 1);
            scanf("%lf", *(numbers + i) + j);
        }

        printf("\n");
    }
}

void PrintArray(double **numbers){
    for (int i = 0; i < ROWS; i++){
        printf("ROW: %d\n", i + 1);
        for (int j = 0; j < COLS; j++)
            printf("COLUMN %d: %g\n", j + 1, *(*(numbers + i) + j));

        printf("\n");
    }
}