#include <stdio.h>

int main ()	{
	
	int num1, num2, i;
    int sum = 0, add = 0;
	
	printf("Kindly input your first number:");
	scanf("%d", &num1);
	printf("Kindly input your last number:");
	scanf("%d", &num2);
	
	printf("Numbers from %d to %d that are divisible by 9: \n", num1, num2);
	for (i=num1; num1<=num2;num1++)	{
		if (num1 % 9 ==0)   {
		printf("\t | %d |", num1);
            add++;
            sum+=num1;
        }
	}

    printf("\nthe sum of the numbers divisible by 9 is: %d", sum);
	return 0;
}
