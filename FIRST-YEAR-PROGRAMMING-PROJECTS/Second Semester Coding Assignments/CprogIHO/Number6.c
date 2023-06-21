#include <stdio.h>
#include <stdlib.h>

int separator(){

	for(int i = 0; i < size1; i++){

	}

	for(int i = 0; i < size2; i++)

}





int main ()	{
	
	int size, oddC= 0, evenC = 0;

	printf("\nInput the number of elements to be stored in the array : ");
	scanf("%d", &size);

	int *arrMain = (int *)malloc(size * sizeof(int));

	printf("Input %d elements in the array : \n", size);

	for(int i = 0; i < size; i++){
		printf("element - %d : ", i);
		scanf("%d", arrMain + i);
	}

	for(int i = 0; i < size; i++){
		if(*(arrMain + i) % 2 == 0){
			evenC++;
		}
		else{
			oddC++;
		}
	}

	int *arrODD = (int *)malloc(oddC * sizeof(int));
	int *arrEVEN = (int *)malloc(evenC * sizeof(int));


	
	return 0;

}