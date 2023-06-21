#include <stdio.h>
#include <malloc.h>

#define ROWS 3
#define COLS 3

void BubbleSortperRow(double **numbers, int ifAscend);
void GetArray(double **numbers);
void PrintArray(double **numbers);
void printBoard(double **numbers);
void BubbleSortWhole(double **numbers, int ifAscend);


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

    printBoard(numbers);

    printf("============================================================\n\n");

    BubbleSortperRow(numbers, ifAscend);
    BubbleSortWhole(numbers, ifAscend);

    printf("<== AFTER SORTING ==>\n\n");
    PrintArray(numbers);

    printBoard(numbers);
}

void BubbleSortperRow(double **numbers, int ifAscend){
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

void BubbleSortWhole(double **numbers, int ifAscend) {
    int totalElements = ROWS * COLS;

    for (int i = 0; i < totalElements; i++) {
        for (int j = 0; j < totalElements - i - 1; j++) {
            double *current = *(numbers + (j / COLS)) + j % COLS;
            double *next = *(numbers + ((j + 1) / COLS)) + (j + 1) % COLS;

            if ((*current > *next && ifAscend == 1) || (*current < *next && ifAscend == 2)) {
                double temp = *current;
                *current = *next;
                *next = temp;
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

    }
}

void printBoard(double **numbers){
    for(int r = 0; r <  ROWS; r++){
        if(r == 0 || r == 2)
            printf("\n+------------------------+\n");
        else   
            printf("\n--------------------------\n");
        for (int c = 0; c < COLS; c++){
            printf("%s  %3g  %s", c < COLS ? "|" : "", *(*(numbers + r) + c), c == COLS - 1 ? " |" : "");
        }
    }
    printf("\n+------------------------+\n");
}




/*

Change Logs 
1. added a printBoard function to print the 2d array as a table
2. added a function to sort the whole 2d array


*/