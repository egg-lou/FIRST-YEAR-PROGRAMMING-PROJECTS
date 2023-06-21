#include <stdio.h>
#include <stdlib.h>

void printUniqueElements(int *arr, int size) {
    printf("The unique elements found in the array are:\n");

    for (int i = 0; i < size; i++) {
        int isUnique = 1;

        for (int j = 0; j < size; j++) {
            if (i != j && *(arr + i) == *(arr + j)) {
                isUnique = 0;
                break;
            }
        }

        if (isUnique) {
            printf("%d ", *(arr + i));
        }
    }

    printf("\n");
}

int main() {
    int size;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d : ", i);
        scanf("%d", arr + i);
    }

    printUniqueElements(arr, size);

    return 0;
}