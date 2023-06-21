#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int count = 0, size = 0;
    int *toCheck;
   
   printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);
    
    int *numbers = (int *) malloc (size * sizeof(int));
    
    printf("\nInput %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d: ", i);
        scanf("%d", numbers + i);
    }

    toCheck = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (*(numbers + i) == *(numbers + j) && *(toCheck + (*(numbers + j) - 1)) != 0){
                count++;

                *(toCheck + (*(numbers + j) - 1)) = 0;
            }   

    printf("Total number of duplicate elements found in the array is: %d\n", count);
}