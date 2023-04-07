/*
PROGRAM: TRIANGLE FUNCTION
Author: Rafael Louie V. Miguel
Creation Date: 02/19//2023
*/


#include <stdio.h>
#include <conio.h>

void TRIANGLE(int *, int *, int *);

int main(){
    void TRIANGLE(int *a, int *b, int *c);
    int side1, side2, side3;

    printf("\nEnter the length of the first side of the triangle: ");
    scanf("%d", &side1);

    printf("Enter the length of the second side of the triangle: ");
    scanf("%d", &side2);

    printf("Enter the length of the third side of the triangle: ");
    scanf("%d", &side3);

    TRIANGLE(&side1, &side2, &side3);

    printf("\nThank you for using the program!");
    getch();

    return 0;
}

/*TRIANGLE FUNCTION will check if the entered sides are equal or not 
Then the function will decide what type of Triangle it is depending 
on the lenght of the sides
*/
void TRIANGLE(int *a, int *b, int *c){

    if(*a == *b && *b == *c){
        printf("\nTriangle Type: EQUILATERAL");
        printf("\nAll sides are equal");
    }
    else if(*a == *b || *a == *c || *b == *c ){
        printf("\nTriangle Type: ISOSCELES");
        printf("\nOnly two sides are equal");
    }
    else{
        printf("\nTriangle Type: SCALENE");
        printf("\nAll sides have a different length");
    }
}