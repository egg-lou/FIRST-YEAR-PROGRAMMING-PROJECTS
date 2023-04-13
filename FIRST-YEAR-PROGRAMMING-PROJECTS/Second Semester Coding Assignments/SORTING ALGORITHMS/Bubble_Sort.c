#include <stdio.h>

void bubble_sort(int arr[], int n ){
    int i, j, temp;
    int pass_count = 0;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n -1; j++){
            if(arr[j] > j[arr + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        pass_count++;
    }
    printf("\nNumber of Passes: %d", pass_count);
}


int main(){
    int SORT_THIS_ASC [10] = {5, 7, 1, 2, 8, 6, 9, 4, 10, 3};
    int n = sizeof(SORT_THIS_ASC)/ sizeof(SORT_THIS_ASC[0]);
    int i; 

    printf("Before Sorting: ");
    for(i = 0; i < n; i++){
        printf("%d ", SORT_THIS_ASC[i]);
    }

    bubble_sort(SORT_THIS_ASC, n);

    printf("\n");

    printf("After Sorting: ");
    for(i = 0; i < n; i++){
        printf("%d ", SORT_THIS_ASC[i]);
    }

    return 0;
}