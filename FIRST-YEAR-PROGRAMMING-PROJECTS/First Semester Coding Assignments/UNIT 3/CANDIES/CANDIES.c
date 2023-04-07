/*
Program: Amount of bag per type of Candies
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>
int main(){

    float candy_a, candy_b, candy_c, candy_d, amount_a, amount_b, amount_c, amount_d, total;
    const float a_php = 35.00;
    const float b_php = 45.00;
    const float c_php = 56.00;
    const float d_php = 57.50;

    printf("\nAmount of Candy Calculator\n");
    //Asks the user to input the weight of candy per type
    printf("\n\tWeight of Candy A: ");
    scanf("%f", &candy_a);

    printf("\n\tWeight of Candy B: ");
    scanf("%f", &candy_b);

    printf("\n\tWeight of Candy C: ");
    scanf("%f", &candy_c);

    printf("\n\tWeight of Candy D: ");
    scanf("%f", &candy_d);
    
    //To calculate the amount of per candy type and total
    amount_a = candy_a * a_php;
    amount_b = candy_b * b_php;
    amount_c = candy_c * c_php;
    amount_d = candy_d * d_php;
    total = amount_a + amount_b + amount_c + amount_d;

    //Printing the amount of candy per type and gratitude message for the user
    printf("\nThe amount of Candy A is PHP%.2f\n", amount_a);
    printf("The amount of Candy B is PHP%.2f\n", amount_b);
    printf("The amount of Candy C is PHP%.2f\n", amount_c);
    printf("The amount of Candy D is PHP%.2f\n", amount_d);
    printf("The total amount of Candies is PHP%.2f\n", total);
    printf("Thank you for using the program!");
    getch();

    return 0;
}