#include <stdio.h>
#include <stdlib.h>

int main (){
	
	
	int n, i;
	
	printf("\nEnter how many numbers you want to enter: ");
	scanf("%d", &n);
	
	int *ptr = (int* )malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++){
		printf("\nNumber %d: ", i);
		scanf("%d", (ptr + i));
	}
	
	printf("\nThe numbers you entered: ");
	for (i = 0; i < n; i++){
		printf("%d%s", *(ptr + i), i != n - 1 ? ", " : "");
	}
	
	return 0;
}
