/*
Program: Prime Factors of a Number 
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main() {
    int num, count, isPrime;

    //Asks the user to input a number to find its prime factors
    printf("\nPrime Factors of a Number\n");
    printf("\n\tEnter a number: ");
    scanf("%d", &num);
    
    printf("\n\tThe Prime Factors of %d: ",num);
    //To check and print the numbers that are the prime factors of a number
    for(count = 2; count < num; count++){
        while(num % count == 0){
            printf("%d ", count);
            num = num/count;
        }
    }
    //Gratitude message for the user
    printf("\n\nThank you for using the program!");
    getch();
    return 0;
}