#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

void printreverse(int *arr, int size){
	int i;
	printf("The Elements of array in reverse order: \n");
	
	for(i = size; i > 0; i--){
		printf("element - %d : %d\n", i, *(arr + i - 1));
	}
}

int main(){
	
	int arr[MAX_SIZE];
	int size;
	int i, j;
	
	
	printf("Input the number of elements to store in the array (max 15): ");
	scanf("%d", &size);
	printf("Input %d number of elements in the array: \n", size);
	
	
	for(i = 0; i < size; i++){
		printf("element - %d : ", i + 1);
		scanf("%d", arr + i);
	} 

	printreverse(arr, size);
	
	
	return 0;
}
