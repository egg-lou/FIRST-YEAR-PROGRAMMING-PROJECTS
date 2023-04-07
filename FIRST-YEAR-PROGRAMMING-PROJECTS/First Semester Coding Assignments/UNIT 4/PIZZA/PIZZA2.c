/*
Program: Bang for the Buck Pizza Calculator 
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/09/2023
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int pizza_diameter, pizza_price, response;
    float pizza_area, pizza_price_per_sqin;
    const double pi = 3.141592653589793238;
    float previous = 0;
    int previous_size = 0.0;
    int counter = 0;

    //do-while loop to help the user know which is more bang for the buck if the previous or the current calculations
    do{
        printf("\nBang for the Buck Pizza Calculator\n");

            if(counter > 0){
                previous = pizza_price_per_sqin; //To store the previous value
                previous_size = pizza_diameter; //To store the previous value
                printf("\n\tPrice per square inch of the %d inch pizza: PHP %.2f\n", previous_size, previous);
            }
        //Asks the user to input the diameter and price of the pizza
        printf("\n\tEnter the diameter of the pizza: ");
        scanf("%d", &pizza_diameter);

        printf("\tEnter the price of the pizza: ");
        scanf("%d", &pizza_price);

        //To calculate the area and price per square inch of the pizza
        pizza_area = pi * pow(pizza_diameter/2, 2);
        pizza_price_per_sqin = pizza_price / pizza_area;

        //Printing the area and price per square inch and prints the which is more bang for the buck compared to the previous input
        printf("\nThe area of a %d inch pizza is %.2f square inches\n", pizza_diameter, pizza_area);
        printf("The price per square inch of the %d inch pizza is PHP %.2f\n", pizza_diameter, pizza_price_per_sqin);
        if(counter > 0){
                if(previous < pizza_price_per_sqin){
                    printf("The %d inch pizza is more bang for the buck than the %d inch pizza\n", previous_size, pizza_diameter);
                }
                else if(pizza_price_per_sqin < previous){
                    printf("The %d inch pizza is more bang for the buck than the %d inch pizza\n", pizza_diameter, previous_size);
                }
            }
        printf("Calculate for another pizza size? Press 1 to calculate again & Press 2 to exit: ");
        scanf("%d", &response);

        //To serve as the counter for the next calculation and to save the previous calculation
        //It can only store 2 calculations at a time
        if(response == 1){
            counter++;
            system("cls");
        }

    }while(response == 1);
    //Gratitude message for the user
    printf("Thank you for using the program!");
    getch();
    return 0;
}