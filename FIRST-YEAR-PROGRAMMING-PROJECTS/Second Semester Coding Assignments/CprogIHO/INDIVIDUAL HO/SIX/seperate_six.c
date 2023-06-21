#include <stdio.h>
#include <malloc.h>

int main()
{
    int numbers[] = {3, 2, 2, 5, 1, 7, 3, 1, 2, 1, 6};
    int size = 11, oddIndex = 0, evenIndex = 0;
    int oddArray[size], evenArray[size]; 

    for (int i = 0; i < size; i++){
        if (numbers[i] % 2 == 0){
            evenArray[evenIndex] = numbers[i];
            evenIndex++;
        }
        else{
            oddArray[oddIndex] = numbers[i];
            oddIndex++;
        }
    }

    printf("EVEN NUMBERS: ");
    for (int i = 0; i < evenIndex; i++)
        printf("%d ", evenArray[i]);

    printf("\n\nODD NUMBERS: ");
    for (int i = 0; i < oddIndex; i++)
        printf("%d ", oddArray[i]);
}