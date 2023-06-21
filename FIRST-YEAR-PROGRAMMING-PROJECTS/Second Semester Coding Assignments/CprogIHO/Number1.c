#include <stdio.h>
#include <stdlib.h>

void countDuplicateElements(int *arr, int size , int *duplicateCount) {
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) == *(arr + j)) {
                (*duplicateCount)++;
                break;
            }
        }
    }
}

int main() {
    int size;
    int duplicateCount = 0;
    
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);
    
    int *arr = (int *) malloc (size * sizeof(int));
    
    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d: ", i);
        scanf("%d", arr + i);
    }
    
    countDuplicateElements(arr, size, &duplicateCount);
    
    printf("Total number of duplicate elements found in the array is: %d\n", duplicateCount);
    
    return 0;
}
