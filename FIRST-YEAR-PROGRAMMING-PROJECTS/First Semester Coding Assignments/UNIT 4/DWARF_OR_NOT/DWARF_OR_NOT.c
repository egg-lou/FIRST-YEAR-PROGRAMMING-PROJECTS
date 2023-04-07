/*
Program: Tells a number if it is DWARF OR NOT DWARF based on if the number is 
smaller than the sum of its factors.
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main() {
    int num;
    int count = 1;
    int sum = 0;
    float half;
    
    //Asks the user to input a number that will be tested if dwarf or not dwarf
    printf("\nNumber: DWARF or NOT DWARF\n");
    printf("\n\tInput number: ");
    scanf("%d", &num);
    
    //For loop - will check for the factors and if to print it and then add the factors
    printf("\n\tFactors are: ");
    for(count; count < num; count++){
        if(num % count == 0){
            printf("%d ", count);
            sum = sum + count;
        }
    }
    //Prints the sum of the factors 
    printf("\n\n\tSum of its factors: %d\n", sum);
    
    //Check if it is DWARF or NOT DWARF 
    half = num/2;
    if(sum > half){
        printf("\n\t%d is DWARF\n", num);
    }
    else{
        printf("\n\t%d is NOT DWARF\n", num);
    }
    //Gratitude message to the user
    printf("\nThank you for using the program!");
    getch();
    return 0;
}