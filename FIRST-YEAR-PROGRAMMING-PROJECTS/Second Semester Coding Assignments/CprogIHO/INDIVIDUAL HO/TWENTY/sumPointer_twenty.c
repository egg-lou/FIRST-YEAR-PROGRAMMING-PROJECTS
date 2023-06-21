#include <stdio.h>

void GetSum(int arr[], int *sum);

int main()
{
    int array[5] = {2, 3, 4, 5, 6};
    int sum = 0;
    GetSum(array, &sum);

    printf("Sum: %d", sum);
}

void GetSum(int arr[], int *sum){
    for (int i = 0; i < 5; i++)
        *sum += *(arr + i);
}