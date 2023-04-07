/*
Program: Child, Teen-Ager, & Adult identifier based on the age
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main(){
    int age;

    //Asks the user to input their age 
    printf("\nAge Group Identifier: C = Child, T = Teen-ager, and A = Adult\n");
    printf("\n\tEnter age: ");
    scanf("%d", &age);


    //Switch case to determine the age group of the user based on their age
    switch(age)
    {
        case 0 ... 12:
            printf("\tAge Group: C\n");
            break;
        
        case 13 ... 19:
            printf("\tAge Group: T\n");
            break;
        
        case 20 ... 100:
            printf("\tAge Group: A\n");
            break;
        
        defeault:
            printf("\tINVALID INPUT!\n");
    }

    //Gratitude message for the user
    printf("\nThank you for using the program!");
    getch();
    return 0;
}