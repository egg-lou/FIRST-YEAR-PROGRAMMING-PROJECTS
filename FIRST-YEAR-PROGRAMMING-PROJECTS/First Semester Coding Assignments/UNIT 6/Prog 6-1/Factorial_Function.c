/*
Program: Factorial
Author: Rafael Louie V. Miguel
Creation Data: 02/16/2023
*/


#include <stdio.h>
#include <stdlib.h>

size_t Factorial(size_t n){
    size_t c;
    size_t result = 1;


    for(c = 1; c <= n; c++){
        result = result * c;
    }
    return (result);
}

int main(){
    int num;

    do{
        printf("\nEnter a Non-negative number to calculate its Factorial: ");
        scanf("%d", &num);

        if(num <= -1 ){
            printf("\nInvalid Input, Number should be Non-Negative Number\n");
        }
    }while(num <= -1);

    printf("%zu! factorial is %zu", num, Factorial(num));


    return 0;
}