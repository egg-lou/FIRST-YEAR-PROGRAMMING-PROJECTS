#include <stdio.h>
#include <malloc.h>

int main()
{
    float *elements, largestElement = 0.0;
    int size;
    printf("Input total number of elements(1 to 100): ");
    scanf("%d", &size);

    elements = (float*)malloc(size * sizeof(float));

    for (int i = 0; i < size; i++){
        printf("Number %d: ", i + 1);
        scanf("%f", elements + i);

        if(i != 0 && *elements < *(elements + i)) 
           *elements = *(elements + i);
    }

    printf("The largest element is %.2f", *elements);
}