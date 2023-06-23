
#include <stdio.h>
#include <stdlib.h>

void separator(int *arrMain, int *arrOdd, int *arrEven, int size) {
    int oddIndex = 0;
    int evenIndex = 0;

    for (int i = 0; i < size; i++) {
        if (*(arrMain + i) % 2 == 0) {
            *(arrEven + evenIndex) = *(arrMain + i);
            evenIndex++;
        } else {
            *(arrOdd + oddIndex) = *(arrMain + i);
            oddIndex++;
        }
    }
}

int main() {
    int size, oddC = 0, evenC = 0;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &size);

    int *arrMain = (int *)malloc(size * sizeof(int));

    printf("Input %d elements in the array:\n", size);

    for (int i = 0; i < size; i++) {
        printf("element - %d: ", i);
        scanf("%d", arrMain + i);
    }

    for (int i = 0; i < size; i++) {
        if (*(arrMain + i) % 2 == 0) {
            evenC++;
        } else {
            oddC++;
        }
    }

    int *arrODD = (int *)malloc(oddC * sizeof(int));
    int *arrEVEN = (int *)malloc(evenC * sizeof(int));

    separator(arrMain, arrODD, arrEVEN, size);

    printf("\nThe Even elements are:\n");
    for (int i = 0; i < evenC; i++) {
        printf("%d ", *(arrEVEN + i));
    }

    printf("\nThe odd elements are:\n");
    for (int i = 0; i < oddC; i++) {
        printf("%d ", *(arrODD + i));
    }

    return 0;
}
