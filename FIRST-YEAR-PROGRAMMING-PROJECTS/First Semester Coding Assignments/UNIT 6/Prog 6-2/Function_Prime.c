/*
Program: Function Prime
Author: Rafael Louie V. Miguel
Creation Date: 02/16/2023
*/

#include <stdio.h>
#include <conio.h>

//is_Prime Function will check if the number is prime or not
int is_Prime(int n){
    int res = 0;
    int k;

    for(k = 1; k <= n; k++ ){
        if(n % k == 0){
            res++;
        }
    }
    
    if(res == 1 || res == 2){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int num;
    int x;

    do{
        printf("\n0 = Prime Number and 1 = Not Prime Number");
        printf("\nEnter a Non-negative number to check if it's is a Prime or Not: ");
        scanf("%d", &num);

        if(num <= -1 ){
            printf("\nInvalid Input, Number should be Non-Negative Number\n");
        }
    }while(num <= -1);
    
    x = is_Prime(num);

    if(x == 0){
        printf("\n%d is a PRIME NUMBER!", num);
        printf("\nResult: %d", is_Prime(num));
    }
    else{
        printf("\n%d is NOT a PRIME NUMBER!", num);
        printf("\nResult: %d", is_Prime(num));
    }


    printf("\nThank you for using the program!");
    getch();
    return 0;
}