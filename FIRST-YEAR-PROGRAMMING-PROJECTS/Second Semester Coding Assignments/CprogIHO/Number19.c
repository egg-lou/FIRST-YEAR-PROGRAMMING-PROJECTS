#include <stdio.h>
#include <stdlib.h>

void sorter(int *arr, int size){

    int i, j, min_index;

    for(i = 0; i < size - 1 ; i++){
        min_index = i;
        for(j = i + 1; j < size; j++){
            if(*(arr + j) < *(arr + min_index)){
                min_index = j;

            
            int temp = *(arr + min_index);
            *(arr + min_index) = *(arr + i);
            *(arr + i) = temp;
            }
        }

    }

}

int main(){
    int size;
    int i;

    printf("Input the number of elements to store in the array: ");
    scanf("%d", &size);
    printf("Input %d number of elements in the array: \n", size);

    int *arr = (int *) malloc (size * sizeof(int));

    for(i = 0; i < size; i++){
        printf("\nelement - %d : ", i + 1);
        scanf("%d", arr + i);
    }

    sorter(arr, size);

    printf("\nThe elements in the array after sorting: ");
    for(i = 0; i < size; i++){
        printf("\nelement - %d : %d", i + 1, *(arr + i));
    }
    return 0;
}