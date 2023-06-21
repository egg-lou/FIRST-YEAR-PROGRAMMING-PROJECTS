#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

void sum(int x[])
{
    int sum_even = 0;
    int sum_odd = 0;

    int n = 0;
    int i = 0;
    while((x + i) != ){
        i++;
        n++;
    }

    printf("%d", n);

}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sum(arr);
    return 0;
}

 // int n = sizeof(arr) / sizeof(int);
    // for(int i = 0; i < n; i++){

    //     if(x[i] % 2 == 0){
    //         sum_even += x[i];
    //     }

    //     else{
    //         sum_odd +=  x[i];
    //     }
    // }
    // printf("Sum of odd indexed elements: %d\n", sum_odd);
    // printf("Sum of even indexed elements: %d\n", sum_even);