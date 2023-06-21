#include <stdio.h>
#include <stdlib.h>


int finder(int *arr, int size){

    int largest = 0;
    int secLargest = 0;

    for(int i = 0; i < size; i++){

        if(*(arr + i) > secLargest){
            secLargest = *(arr + i);
        }

        if(secLargest > largest){
            int temp = largest;
            largest = secLargest;
            secLargest = temp;
        }
    }
    return secLargest;
}

int main(){
    int size;
    int *arr;
    int secLargest = 0;

    printf("\nInput the size of the array : ");
    scanf("%d", &size);

    arr = (int *) malloc (size * sizeof(int));
    
    printf("\nInput %d elements in the array : \n",size);
    for(int i = 0;  i < size; i++){
        printf("element - %d : ", i + 1);
        scanf("%d", arr + i);
    }

    secLargest = finder(arr, size);
    printf("\nThe Second largest element in the array is : %d", secLargest);
    return 0;
}