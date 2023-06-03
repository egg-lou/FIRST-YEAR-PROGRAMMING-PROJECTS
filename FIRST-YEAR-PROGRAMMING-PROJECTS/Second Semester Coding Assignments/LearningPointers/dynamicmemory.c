#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>

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

void descend(int *arr, int size){
    for(int element =  size - 1; element >= 0; element--){
        for(int i = element - 1; i >= 0; i--){
            if(*(arr + i) < *(arr + element)){
                int temp = *(arr + i);
                *(arr + i) = *(arr + element);
                *(arr + element) = temp;
            }
        }
    }
}

int main(){

    int n;

    int *arr = NULL;

    arr = (int* )malloc(n * sizeof(int));

    printf("\nHow many numbers do you want to enter? ");
    printf("\nResponse: ");
    scanf("%d", &n);

    
    for(int i = 0; i < n; i++){
        printf("\nNumber Count: %d\n", i + 1);
        printf("Number: ");
        scanf("%d", arr+i);
    }

    printf("\nCurrent Array List: ");
    for (int i = 0; i < n; i++){
        printf("%d%s", *(arr+i), i != n - 1 ? ", " : "");
    }

    printf("\nAddress: ");
    for (int i = 0; i < n; i++){
        printf("%p%s", (arr+i), i != n - 1 ? ", " : "");
    }

    printf("\nSorted Ascending: ");
    ascend(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d%s", *(arr+i), i != n - 1 ? ", " : "");
    }

    printf("\nAddress: ");
    for (int i = 0; i < n; i++){
        printf("%p%s", (arr+i), i != n - 1 ? ", " : "");
    }

    printf("\nSorted Descending: ");
    descend(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d%s", *(arr+i), i != n - 1 ? ", " : "");
    }
    
    printf("\nAddress: ");
    for (int i = 0; i < n; i++){
        printf("%p%s", (arr+i), i != n - 1 ? ", " : "");
    }

    free(arr);
    return 0;
}