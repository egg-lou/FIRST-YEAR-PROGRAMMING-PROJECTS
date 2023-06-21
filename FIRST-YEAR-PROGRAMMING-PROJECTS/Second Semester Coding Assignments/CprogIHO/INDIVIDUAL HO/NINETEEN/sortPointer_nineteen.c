#include <stdio.h>

void SortArray(int arr[]);

int main()
{
    int array[5] = {25, 45, 89, 15, 82};

    SortArray(array);

    for (int i = 0; i < 5; i++)
        printf("%d ", *(array + i));
}

void SortArray(int arr[]){
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5 - i - 1; j++)
            if (*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
}