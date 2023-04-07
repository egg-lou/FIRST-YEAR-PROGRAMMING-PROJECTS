/*
Program: Factorial Function
Author: Rafael Louie V. Miguel
Creation Date: 02/23/2023
*/
#include <stdio.h>
#include <conio.h>

//I used a different approach to printing the factorial of a number
//Instead using the normal way that will not work above 13!
//I used the array way which can find the factorial even up to 100
/*
I used an array to store each digit in the factorial and print it out
one by one */
#define MaxSize 10000000
int alpha [MaxSize];

/*Factorial Function will get the factorial of the number by storing each digit
then print it out until the last digit of the factorial is reached
*/
void Factorial(int *n){
    int temp;
    int i, j;
    int index;


    alpha [0] = 1;
    index = 0;
    i = 1;

    while (i <= *n){
        j = 0;
        temp = 0;
        while( j <= index){
            temp = (alpha [j] * i ) + temp;
            alpha [j] = temp % 10;
            temp = temp / 10;
            j++;
        }
        while (temp > 0){  //if temp >= 10
            index++;
            alpha [index] = temp % 10;
            temp = temp / 10;
        }
        i++;
    }
    for(i = index; i >= 0; i--){
        printf("%d", alpha[i]);
    }
}


int main(){
    int num;
     do{
        printf("\nEnter a Non-negative number to calculate its Factorial: ");
        scanf("%d", &num);

        if(num <= -1 ){
            printf("\nInvalid Input, Number should be Non-Negative Number\n");
        }
    }while(num <= -1);

    printf("%d! Factorial is ", num);
    Factorial(&num);
    
    printf("\nThank you for using the program!");
    getch();
}