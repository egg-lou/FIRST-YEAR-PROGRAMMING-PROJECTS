/*
Program: isPrime Function?
Author: Rafael Louie V. Miguel
Creation Data: 02/16/2023
*/

#include <stdio.h>
#include <conio.h>

//Checks the number if it is a prime number
int isPrime(int n){
    int res = 0;
    int k;

    for(k = 1; k <= n; k++){
        if(n % k == 0);
        res++;
    }

    if(res == 1 || res == 2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int num;
    int x;

    do{
        printf("\n1 = Prime Number and 0 = Not Prime Number\n");
        printf("\nEnter a Non-negative number to check if it's a Prime or Not: ");
        scanf("%d", &num);

        if(num <= -1 ){
            printf("\nInvalid Input, Number should be Non-Negative Number\n");
        }
    }while(num <= -1);
    
    x = isPrime(num);

    if(x == 1){
        printf("\n%d is a PRIME NUMBER!", num);
        printf("\nResult: %d", isPrime(num));
    }
    else{
        printf("\n%d is NOT a PRIME NUMBER!", num);
        printf("\nResult: %d", isPrime(num));
    }

    printf("\nThank you for using the program!");
    getch();
}