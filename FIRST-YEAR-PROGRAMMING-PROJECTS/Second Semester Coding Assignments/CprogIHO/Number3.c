#include <stdio.h>
#include <stdlib.h>

void sortArray(int *merged, int mergedSize) {
    for (int i = 0; i < mergedSize; i++) {
        for (int j = 0; j < mergedSize - i - 1; j++) {
            if (*(merged + j) < *(merged + j + 1)) {
                int temp = *(merged + j);
                *(merged + j) = *(merged + j + 1);
                *(merged + j + 1) = temp;
            }
        }
    }
}

int main() {
    int *arr1, *arr2, *arr3;
    int size1, size2, size3;

    printf("\nInput the number of elements to be stored in the first array: ");
    scanf("%d", &size1);

    arr1 = (int *)malloc(size1 * sizeof(int));

    for (int i = 0; i < size1; i++) {
        printf("element - %d : ", i + 1);
        scanf("%d", arr1 + i);
    }

    printf("\nInput the number of elements to be stored in the second array: ");
    scanf("%d", &size2);

    arr2 = (int *)malloc(size2 * sizeof(int));

    for (int i = 0; i < size2; i++) {
        printf("element - %d : ", i + 1);
        scanf("%d", arr2 + i);
    }

    size3 = size1 + size2;

    arr3 = (int *)malloc(size3 * sizeof(int));

    for (int i = 0; i < size1; i++) {
        *(arr3 + i) = *(arr1 + i);
    }

    for (int i = 0; i < size2; i++) {
        *(arr3 + size1 + i) = *(arr2 + i);
    }

    sortArray(arr3, size3);

    printf("\nThe merged array in descending order is: \n");
    for (int i = 0; i < size3; i++) {
        printf("%d ", *(arr3 + i));
    }

    return 0;
}
