#include <stdio.h>

int main()
{
    int numbers[] = {3, 2, 2, 5, 1, 7, 3, 1, 2, 1, 6};
    int size = 11, maxElement = 0, minElement;

    for (int i = 0; i < size; i++){
        if (numbers[i] > maxElement)
            maxElement = numbers[i];

        if (i == 0)
            minElement = numbers[i];

        if (numbers[i] < minElement)
            minElement = numbers[i];
    }

    printf("Maximum element is %d\n", maxElement);
    printf("Minimum element is %d", minElement);
}