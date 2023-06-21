#include <stdio.h>

int main() 
{
    int numbers[] = {3, 2, 2, 5, 1, 7, 3, 1, 2, 1, 6};
    int size = 11, count;

    for (int i = 0; i < size; i++){
        count = 1;

        for (int j = i + 1; j < size; j++){
            if (numbers[i] == numbers[j]){
                count++;
                numbers[j] = -1;
            }
        }

        if (numbers[i] != -1)
            printf("%d occurs %d times\n", numbers[i], count);
    }

}