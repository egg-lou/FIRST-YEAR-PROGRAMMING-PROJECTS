#include <stdio.h>
#include <stdbool.h>

int main() 
{
    int numbers[]={3, 2, 2, 5};
    int size = 4;
    bool ifDuplicate;

    for (int i = 0; i < size; i++){
        ifDuplicate = false;

        for (int j = 0; j < size; j++)
            if (i != j && *(numbers + i) == *(numbers + j)){
                ifDuplicate = true;
                break;
            }

        if (!ifDuplicate)
            printf("%d ", *(numbers + i));
    }

}