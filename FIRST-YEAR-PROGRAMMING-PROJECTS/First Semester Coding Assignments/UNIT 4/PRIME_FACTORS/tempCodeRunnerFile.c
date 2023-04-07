/*
Program: Prime Factors of a Number 
Programmed by: Rafael Louie V. Miguel
Creation Date: 02/05/2023
*/

#include <stdio.h>
#include <conio.h>
 
int main()
{
  	int count, j, num, isPrime; 
   
   //Asks the user to input a number to find its Prime Factors
  	printf("\nPrime Factors of a Number\n");
    printf("\n\tEnter a number: ");
    scanf("%d", &num);
 
    //For loop to print the prime factors of the number entered 
    printf("\tThe Prime Factors of %d: ", num);
  	for (count = 2; count <= num; count++)
   	{
     	if(num % count == 0)
        {
   			isPrime = 1;
			for (j = 2; j <= count/2; j++)
			{
				if(count % j == 0)
				{
					isPrime = 0;
					break;
				}
			} 
			if(isPrime == 1)
			{
				printf("%d ", count);
			}	          	
		}
   }
    //Gratitude message for the user
    printf("\n\nThank you for using the program!");
    getch();
  	return 0;
}