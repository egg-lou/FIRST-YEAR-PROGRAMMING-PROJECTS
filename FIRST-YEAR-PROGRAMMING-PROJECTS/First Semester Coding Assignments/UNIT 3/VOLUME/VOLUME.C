/*
Program: Rectangular Box Volume Calculator 
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include<stdio.h>
#include<conio.h>

int main(int argc, const char * argv[]){
    int length, width, height, volume;

    //Asks the user to input the measurements of the rectanguler box
    printf("\nEnter the measurements of the Rectangular Box\n");

    printf("\tEnter the lenght: ");
    scanf("%d", &length);

    printf("\tEnter the height: ");
    scanf("%d", &height);

    printf("\tEnter the width:  ");
    scanf("%d", &width);

    //Calculates the volume of the rectangular box using the measurements given by the user
    volume = length*width*height;

    //Printing the the volume of the rectangular box and a gratitude message for the user
    printf("\nThe Volume of the Rectangular Box is %d\n", volume);
    printf("Thank you for using the program!");
    getch();
    return 0;
}