/*
Program: Prime Factorization that expresses the integer as product of primes
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main(){
    int num, count;
    int is_first = 1;
    int start_num;
    
    //Asks the user to enter a number to find its prime factors and express the number entered as the product
    printf("\nPrime Factorization = Positive Number\n");
    printf("\n\tEnter a Positive Number: ");
    scanf("%d", &num);

    start_num = num; //Saves the start number of num
    printf("\n\tPrime Factorization: "); // Prints the Prime Factorization

    //For loop to check and print the prime factors 
    for(count = 2; count <= num; count++){
        while(num % count == 0){
            if(! is_first)
                printf("x ");
            printf("%d ", count);
            num = num/count;
            is_first = 0;
        }
    }
    printf("= %d\n", start_num);
    
//Gratitude message for the user
printf("\nThank you for using the program!");
getch();
return 0;
}