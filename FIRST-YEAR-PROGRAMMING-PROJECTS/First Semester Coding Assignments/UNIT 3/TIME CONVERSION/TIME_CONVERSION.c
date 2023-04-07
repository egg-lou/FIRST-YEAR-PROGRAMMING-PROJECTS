/*
Program: Hours to Minutes Converter
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main(){

    int hours;
    int minutes;
    printf("\nHours to Minutes Converter\n");
    printf("\nEnter the number of hour you want convert to minutes: ");
    scanf("%d", &hours);

    //Formula for converting hours to minutes
    minutes = hours * 60;

    //if-else for the output and a gratitude message for the user 
    if (hours <= 1){
        printf("\n%d hour is equal to %02d minutes\n", hours, minutes);
        printf("Thank you for using the program!");
    }
    else if(hours >=2){
        printf("\n%d hours is equal to %02d minutes\n", hours, minutes);
        printf("Thank you for using the program!");
    }

    getch();
    return 0;
}