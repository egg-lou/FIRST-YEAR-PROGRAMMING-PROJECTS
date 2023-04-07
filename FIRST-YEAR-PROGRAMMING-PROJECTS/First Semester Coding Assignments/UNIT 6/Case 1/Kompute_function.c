/*
Program: Kompute Function
Author: Rafael Louie V. Miguel
Creation Date: 02/19/2023
*/

#include <stdio.h>
#include <conio.h>

//kompute function to get the proper divisors of the number entered 
//Then the kompute function will add the proper divisors
//Lastly, it will check if it is DEFICIENT, ABUNDANT, & PERFECT
void kompute(int *n){
    int i;
    int count =0;
    int sum;
        printf("The proper divisors of %d: ", *n);
        for(i = 1; i < *n; i++){
            if(*n % i == 0){
                count++;
                if(count == 1){
                    printf("%d", i);
                }
                else{
                    printf(", %d", i);
                }
            }
        }
        printf("\nThe sum of its proper divisors: ");
        count = 0;
        sum = 0;
        for (i = 1; i < *n; i++){
            if(*n % i == 0){
                count++;
                sum += i;
                if(count == 1){
                    printf("%d", i);
                }
                else{
                    printf(" + %d",i);
                }
            }
        }
        printf(" = %d", sum);

        if(sum < *n){
            printf("\n%d < %d DEFICIENT", sum, *n);
        }
        else if(sum > *n){
            printf("\n%d > %d ABUNDANT", sum, *n);
        }
        else{
            printf("\n%d = %d PERFECT", sum, *n);
        }
}


int main(){

    int num;

    printf("\nEnter a Non-Negative Number: ");
    scanf("%d",&num);

    kompute(&num);

    printf("\nThank you for using the program!");

    getch();
    return 0;
}