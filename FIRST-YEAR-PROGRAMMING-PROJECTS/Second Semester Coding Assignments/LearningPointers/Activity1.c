#include <stdio.h>

int array [] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int Index;
int *ptr = NULL;

int main(){

    Index = 0;
    ptr = array;

    while(*(ptr + Index) != 0)
        ++Index;


    printf("Number of elements before zero: %d\n", Index);

    return 0;
}