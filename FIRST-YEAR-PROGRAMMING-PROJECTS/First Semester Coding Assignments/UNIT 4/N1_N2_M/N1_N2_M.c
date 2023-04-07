/*
Program: Outputs the number from a certain range and the numbers divisible that 
were specified by the user
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main() {
    int N1, N2, M;
    int orig_number;

    //Asks the user to input a range of numbers N1 = Minimum number, N2 = Maximum Number, and M = divisible
    printf("\nRange of Numbers that will find the numbers that are divisible by a number\n");
    printf("\n\tEnter N1: ");
    scanf("%d", &N1);
    
    printf("\n\tEnter N2: ");
    scanf("%d", &N2);
    
    printf("\n\tEnter M:  ");
    scanf("%d", &M);


    orig_number = N1; //Saves the N1 before the for loop
    int counter = 0; //Counter for the number of divisible numbers
    printf("\n\tNumbers divisible by %d in the range [%d - %d]: \n\t", M, orig_number, N2);
    if(M > N2){
        printf("none"); //Since if M is bigger than the maximum number then there are no divisible numbers
    }
    //To check and find the numbers that are divisible by M in the range N1-N2
    for(N1; N1 <= N2; N1++){
        if(N1 % M == 0){
            printf("%d\t", N1);
            N1++;
            counter++;
        }
    }
    //if-else to print the number of divisible numbers
    if(counter >= 2){
        printf("\n\n\tThere are %d numbers that are divisible by %d in the range [%d - %d]\n", counter, M, orig_number, N2);
    }
    else if(counter == 1){
        printf("\n\n\tThere is only %d number that is divisible by %d in the range [%d - %d]\n\n", counter, M, orig_number, N2);
    }
    else{
        printf("\n\n\tThere is %d number that is divisible by %d in the range of numbers [%d - %d]\n\n", counter, M, orig_number, N2);
    }
    //Gratitude message for the user 
    printf("\nThank you for using the program!");
    getch();
    return 0;
}