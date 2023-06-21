#include <stdio.h>


int factorial(int num){
	int result = 1;
	
	for(int i = 1; i <= num; i++){
		
		result = result*(i);
	}
	return result;
}

int main (){
	int num = 5;
	
	printf("Factorial of %d is %d", num, factorial(num));
	
	
	return 0;
}
