#include <Stdio.h>
#include <Stdlib.h>


void finder(float *arr, int size, float *largest){
    int i;
    *largest = *arr;

    for(i = 1; i < size; i++){
        if(*(arr + i) > *largest){
            *largest = *(arr + i);
        }
    }
}

int main(){

    float *arr, largest;
    int size, i;

    printf("Input total number of elements (1 to 100): ");
    scanf("%d", &size);

    arr = (float *) malloc (size * sizeof(float));

    for(i = 0; i < size; i++){
        printf("Number %d: ", i + 1);
        scanf("%f", arr + i);
    }

    finder(arr, size, &largest);

    printf("The largest element is %.1lf", largest);


    return 0;
}