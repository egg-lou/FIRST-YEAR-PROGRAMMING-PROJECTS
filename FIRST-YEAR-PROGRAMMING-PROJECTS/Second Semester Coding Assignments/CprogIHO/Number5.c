#include <stdio.h>
#include <stdlib.h>

void findMaxMin(int *arr , int size) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }

    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);
}

int main() {
    int size;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    findMaxMin(arr, size);

    return 0;
}
