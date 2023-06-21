#include <stdio.h>

int main()
{
    int numbers[] = {2, 9, 1, 4, 6};
    int largest = 0, secondLargest = 0;

    for (int i = 0; i < 5; i++){
        if (numbers[i] > secondLargest)
            secondLargest = numbers[i];
        
        if (secondLargest > largest){
            int temp;
            temp = largest;
            largest = secondLargest;
            secondLargest = temp;
        }
    }

    printf("%d", secondLargest);
}