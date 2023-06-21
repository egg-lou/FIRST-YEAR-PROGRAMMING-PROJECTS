#include <stdio.h>
#include <malloc.h>

void SortArray(int arr[]);

int main()
{
    int numOne[] = {5, 2, 3, 1, 6};
    int numTwo[] = {6, 1, 2, 8, 8};
    int *merge;

    merge = (int*)malloc(10 * sizeof(int));

    //INSERTING EVERY ELEMENT OF TWO ARRAYS INTO MERGE ARRAY.
    for (int i = 0; i < 10; i++){
        if (i < 5)
            merge[i] = numOne[i];
        else
            merge[i] = numTwo[i - 5];
    }

    SortArray(merge);
    
    for (int i = 0; i < 10; i++)
        printf("%d ", merge[i]);
}

void SortArray(int arr[]){
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10 - i - 1; j++)
            if (*(arr + j) < *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
}