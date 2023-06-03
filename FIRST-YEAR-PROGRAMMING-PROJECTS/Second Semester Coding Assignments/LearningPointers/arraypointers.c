#include <stdio.h>


void ascend(int *arr, int size){

    for(int element = 0; element < size - 1; element++){
        for(int i = element + 1; i < size; i++){
            if(*(arr + i) < *(arr + element)){
                int temp = *(arr + element);
                *(arr + element) = *(arr + i);
                *(arr + i) = temp;
            }
        }
    }
}



int main(){

    int X[] = {2, 1, 3, 9, 7, 5, 6, 13, 90, 15};

    int i;
    int size = sizeof(X)/sizeof(X[0]);
    printf("\nBefore: ");
    for(i = 0; i < size; i++){
        printf("%d%s", *(X+i), i == size - 1 ? "" : ", ");
    }
    ascend(X, size);

    printf("\nAfter: ");
    for(i = 0; i < size; i++){
        printf("%d%s", *(X+i), i == size - 1 ? "" : ", ");
    }

    printf("\n\n");
    
    return 0;
}