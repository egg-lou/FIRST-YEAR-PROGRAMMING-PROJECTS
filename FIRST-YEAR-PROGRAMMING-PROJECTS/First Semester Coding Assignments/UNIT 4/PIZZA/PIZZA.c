/*
Program: Bang for the Buck Pizza Calculator 
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/08/2023
*/

#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(){

    int pizza_10_price, pizza_12_price, pizza_14_price;
    float pizza_area_10, pizza_area_12, pizza_area_14;
    float price_per_sqin_10, price_per_sqin_12, price_per_sqin_14;
    const float pi = 3.14;

    printf("\nBang for the Buck Pizza Calculator\n");
    printf("\n\tEnter the price for the 10inch pizza: ");
    scanf("%d", &pizza_10_price);

    printf("\n\tEnter the price for the 12inch pizza: ");
    scanf("%d", &pizza_12_price);

    printf("\n\tEnter the price for the 14inch pizza: ");
    scanf("%d", &pizza_14_price);

    //Calulation for the price per sqin
    pizza_area_10 = pi * pow(10/2, 2);
    price_per_sqin_10 = pizza_10_price/pizza_area_10;

    pizza_area_12 = pi * pow(12/2, 2);
    price_per_sqin_12 = pizza_12_price/pizza_area_12;

    pizza_area_14 = pi * pow(14/2, 2);
    price_per_sqin_14 = pizza_14_price/pizza_area_14;


    //iff-else will determine which pizza size is bang for the buck
    if(price_per_sqin_10 < price_per_sqin_12 && price_per_sqin_10 < price_per_sqin_14)
        printf("\nThe most bang for the buck size of pizza is the 10 inch pizza with an area of %.2f inches and a price per square inch of PHP %.2f", pizza_area_10, price_per_sqin_10);
    else if(price_per_sqin_12 < price_per_sqin_10 && price_per_sqin_12 < price_per_sqin_14)
        printf("\nThe most bang for the buck size of pizza is the 12 inch pizza with an area of %.2f inches and a price per square inch of PHP %.2f",pizza_area_12, price_per_sqin_12);
    else if(price_per_sqin_14 < price_per_sqin_10 && price_per_sqin_14 < price_per_sqin_12)
        printf("\nThe most bang for the buck size of pizza is the 14 inch pizza with an area of %.2f inches and a price per square inch of PHP %.2f",pizza_area_14, price_per_sqin_14);
    
    //Gratitude message for the user 
    printf("\nThank you for using the program!");
    getch();
    return 0;
}