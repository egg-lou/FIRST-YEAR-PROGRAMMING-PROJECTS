/*
Program: Three integers that will be sorted in descending order
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main(){
    
    int n1, n2, n3;
    int lowest, middle, highest;

    //Asks the user to input three integers
    printf("\nThree Intergers Arranger: Descending Order\n");
    printf("\n\tEnter three integers: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    //If-else to know which number is the highest, middle, and lowest
    if(n1 <= n2 && n1 <= n3){
        lowest = n1;
            if(n2 <= n3){
                middle = n2;
                highest = n3;
            }
            else{
                highest = n2;
                middle = n3;
            }
    }
    else if(n2 <= n1 && n2 <= n3){
        lowest = n2;
            if(n1 <= n3){
                middle = n1;
                highest = n3;
            }
            else{
                highest = n1;
                middle = n3;
            }
    }
    else{
        lowest = n3;
            if(n1 <= n2){
                middle = n1;
                highest = n2;
            }
            else{
                highest = n1;
                middle = n2;
            }
    }
    //Printing the three integers in descending order and a gratitude message for the user
printf("\n\tDescending Order: %d %d %d\n", highest, middle, lowest);
printf("\nThank you for using the program!");
getch();
    return 0;
}