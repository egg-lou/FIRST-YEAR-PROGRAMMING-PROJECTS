/*
Program: is_prime Function?
Author: Rafael Louie V. Miguel
Creation Data: 02/16/2023
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

//Checks the number if it is a prime number
int is_prime(int n) {

    if(n == 1){
        return 1;
    }
    if (n < 2) {
        return 0;
    }
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int num;
    int x;

    printf("\n1 = Prime Number and 0 = Not Prime Number\n");

    do{
        printf("\nEnter a Non-negative number to check if it's a Prime or Not: ");
        scanf("%d", &num);

        if(num <= -1 ){
            printf("\nInvalid Input, Number should be Non-Negative Number\n");
        }
    }while(num <= -1);
    
    x = is_prime(num);

    if(x == 1){
        printf("\n%d is a PRIME NUMBER!", num);
        printf("\nResult: %d", is_prime(num));
    }
    else{
        printf("\n%d is NOT a PRIME NUMBER!", num);
        printf("\nResult: %d", is_prime(num));
    }

    printf("\nThank you for using the program!");
    getch();
}