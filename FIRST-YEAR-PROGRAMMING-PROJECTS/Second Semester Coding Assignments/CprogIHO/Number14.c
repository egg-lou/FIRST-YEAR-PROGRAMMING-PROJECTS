#include <stdio.h>

void summerPerfect(int *sum, int start, int end){
	for(int i = start; i < end; i++){
		if(i % 9 == 0){
			printf("%d ", i);
			*sum += i;
		}
	}
}

int main(){

	int start, end;
	int sum = 0;
	int add = 0;

	printf("Kindly input your starting number: ");
	scanf("%d", &start);

	printf("Kindly input your ending number: ");
	scanf("%d", &end);

	summerPerfect(&sum, start, end);

	printf("\nThe sum of the numbers divisible by 9 is %d", sum);

	return 0;
}