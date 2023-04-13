#include <stdio.h>

void selection_sort(int arr[], int n){
    int i, j, temp;
    int pass_count = 0;

    for(i = 0; i < n - 1; i++){
        int min_index = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
        pass_count++;
    }
    printf("\nNumber of Passes: %d", pass_count);
}
int main(){
    int SORT_THIS_ASC [10] = {5, 7, 1, 2, 8, 6, 9, 4, 10, 3};
    int n = sizeof(SORT_THIS_ASC)/sizeof(SORT_THIS_ASC[0]);
    int i;

    printf("Before Sorting: ");
    for(i = 0; i < n; i++){
        printf("%d ", SORT_THIS_ASC[i]);
    }

    selection_sort(SORT_THIS_ASC, n);
    printf("\n");

    printf("After Sorting: ");
    for(i = 0; i < n; i++){
        printf("%d ", SORT_THIS_ASC[i]);
    }
    return 0;
}