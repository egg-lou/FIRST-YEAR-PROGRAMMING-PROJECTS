#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

#define ROWS 3
#define COLS 3
#define DURATION 5

void BubbleSort(double **numbers, int ifAscend);
void GetArray(double **numbers);
void PrintArray(double **numbers);
void showLoadingSpinner(int durationInSeconds);

int i;
int j;
int k;

int main()
{
    double **numbers = (double**)malloc(ROWS * sizeof(double*));
    int ifAscend;
    for (i = 0; i < ROWS; i++)
        *(numbers + i) = (double*)malloc(COLS * sizeof(double));

    printf("\n");
    printf("==========================================\n");
    printf("||");
    printf(" 2d Array Sorter: Bubble Sort Edition ");
    printf("||\n");
    printf("==========================================\n");
    

    GetArray(numbers);

    printf("============================================================\n");

    char input[100];

    while (1) {
        printf("ENTER [1] FOR ASCENDING OR [2] FOR DESCENDING: ");

        fflush(stdin);

        gets(input);

        input[strcspn(input, "\n")] = '\0';

        int isNumber = 1;
        for (i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isNumber = 0;
                break;
            }
        }

        if (isNumber) {
            ifAscend = atoi(input);
            if (ifAscend == 1 || ifAscend == 2) {
                break;
            }
        }

        printf("\033[1;31mInvalid input. Please enter a valid number.\n\033[0m");
    }

    printf("\033[1;32mYou entered: %s \n\033[0m",ifAscend == 1 ? "Ascending" : "Descending");

    getch();

    printf("\n<== BEFORE SORTING ==>\n\n");
    PrintArray(numbers);

    printf("============================================================\n\n");

    setbuf(stdout, NULL);
    showLoadingSpinner(DURATION);
    
    BubbleSort(numbers, ifAscend);

    printf("\033[1;32m<== AFTER SORTING ==>\n\n\033[0m");
    PrintArray(numbers);

    getch();
}

void BubbleSort(double **numbers, int ifAscend){
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS - 1; j++) {
            for (k = 0; k < COLS - j - 1; k++) {
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
    for (i = 0; i < ROWS; i++){
        printf("ROW: %d\n", i + 1);
        for (j = 0; j < COLS; j++){
            double input;
            printf("Enter any number for [COLUMN %d]: ", j + 1);
            while (scanf("%lf", &input) != 1){
                printf("\033[1;31mInvalid input. Please enter a valid number.\n\033[0m");
                scanf("%*[^\n]");
                scanf("%*c");
                printf("Enter any number for [COLUMN %d]: ", j + 1);
            }
            *(*(numbers + i) + j) = input;
        }
        printf("\n");
    }
}

void PrintArray(double **numbers){
    for (i = 0; i < ROWS; i++){
        printf("ROW: %d\n", i + 1);
        for (j = 0; j < COLS; j++)
            printf("COLUMN %d: %g\n", j + 1, *(*(numbers + i) + j));

        printf("\n");
    }
}

void showLoadingSpinner(int durationInSeconds) {
    const char spinner[] = { '|', '/', '-', '\\' };
    i = 0;
    int secondsPassed;
    int millisecondsPassed;
    for (secondsPassed = 0; secondsPassed < durationInSeconds; secondsPassed++) {
        for (millisecondsPassed = 0; millisecondsPassed < 100; millisecondsPassed += 20) {
            printf("\033[1;33mSorting %c\r\033[0m", spinner[i % 4]);
            fflush(stdout);
            Sleep(100);
            i++;
        }
    }
    printf("\r                \r");
    printf("\033[1;32mSorting Complete\n\n\033[0m");
}
