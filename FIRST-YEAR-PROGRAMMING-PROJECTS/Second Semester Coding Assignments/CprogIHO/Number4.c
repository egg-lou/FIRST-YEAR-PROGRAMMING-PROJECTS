#include <stdio.h>
#include <stdlib.h>

void countFrequency(int arr[], int size) {
    int *frequency = (int *) malloc (sizeof(int));
    int visited = -1;

    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                frequency[j] = visited;
            }
        }
        if (frequency[i] != visited) {
            frequency[i] = count;
        }
    }

    printf("The frequency of all elements of an array:\n");
    for (int i = 0; i < size; i++) {
        if (frequency[i] != visited) {
            printf("%d occurs %d times\n", arr[i], frequency[i]);
        }
    }
}

int main() {
    int size;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc (size * sizeof(int));

    printf("Input %d elements in the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    countFrequency(arr, size);

    return 0;
}
