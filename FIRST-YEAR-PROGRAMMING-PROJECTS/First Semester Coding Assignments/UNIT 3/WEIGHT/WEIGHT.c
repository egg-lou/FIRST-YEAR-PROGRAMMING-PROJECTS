/*
Program: Weight on Mars and Jupiter Calculator 
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/
#include <stdio.h>
#include <conio.h>

int main(){

    char name[80];
    int weight_earth, weight_mars, weight_jupiter;
 

    //Welcomes and asks the user for his/her name and weight in lbs
    printf("\nWeight on Mars and Jupiter Calculator\n");
    printf("\n\tEnter your name: ");
    scanf("%s", name);

    printf("\tEnter your weight in lbs: ");
    scanf("%d", &weight_earth);

    //Calculation for the weight on Mars and Jupiter
    weight_mars = weight_earth * 38/100;
    weight_jupiter = weight_earth* 264/100;

    //Prints the result and a gratitude message for the user
    printf("\n%s, your weight on Mars is %dlbs and your weight on Jupiter is %dlbs\n", name, weight_mars, weight_jupiter);
    printf("Thank you for using the program!");
    getch();
    return 0;
}