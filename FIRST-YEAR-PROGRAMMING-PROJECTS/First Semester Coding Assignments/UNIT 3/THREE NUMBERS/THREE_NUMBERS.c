/*
Program: Three numbers calculator that will show the sum, difference, product, quotient, sum of squares 
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>

int main(){
    int a, b, c, sum, difference, product, quotient, sum_squares;

    //Asks the user to input three numbers 
    printf("\nThree Numbers Calculator for Sum, Difference, Product, Quotient, and Sum of its Squares\n");
    printf("\n\tEnter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    //To calculate the sum, difference, product, quotient, and sum of its squares
    sum = a + b + c;
    difference = a - b - c;
    product = a * b * c;
    quotient = a / b / c;
    sum_squares = (a*a) + (b*b) + (c*c);

    //Printing of outputs and gratitude message for the user
    printf("\nThe sum of the three numbers is %d\n",sum);
    printf("The difference of the three numbers is %d\n",difference);
    printf("The product of the three numbers is %d\n",product);
    printf("The quotient of the three numbers is %d\n",quotient);
    printf("The sum of the squares of the three numbers is %d\n",sum_squares);
    printf("Thank you for using the program!");
    getch();
    
    return 0;
}