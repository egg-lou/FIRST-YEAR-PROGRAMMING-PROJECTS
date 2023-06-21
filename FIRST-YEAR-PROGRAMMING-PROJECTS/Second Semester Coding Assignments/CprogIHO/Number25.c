#include <stdio.h>

void finder(int arr[], int size, int target){
	int i, j;
	int found = 0;

	for(i = 0; i < size; i++){
		for(j = i; j < size; j++){
			if(arr[i] + arr[j] == target){
				printf("Found two indices equal to target\n");
				printf("%d and %d equal to %d", arr[i], arr[j], target);
				found = 1;
			}
		}
	}
	if(found == 0){
		printf("No indices found equal to target");
	}
}

int main(){
	int arr [] = {4, 2, 1, 5};
	int target = 11;
	int size = sizeof(arr)/sizeof(arr[0]);
	
	finder(arr, size, target);
	
	return 0;
}
