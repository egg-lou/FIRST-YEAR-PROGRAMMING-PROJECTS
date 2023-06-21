#include <stdio.h>
#include <malloc.h>

int main()
{
    float **elements, largestElement = 0.0;
    int size;
    printf("Input total number of elements(1 to 100): ");
    scanf("%d", &size);

    elements = (float**)malloc((size + 1) * sizeof(float*));

    elements[0] = &largestElement;

    for (int i = 1; i <= size; i++){
        elements[i] = (float*)malloc(sizeof(float));

        printf("Number %d: ", i);
        scanf("%f", elements[i]);

        if (*(elements[i]) > *elements[0])
            *elements[0] = *(elements[i]);
    }

    printf("The largest element is %.2f", largestElement);
}