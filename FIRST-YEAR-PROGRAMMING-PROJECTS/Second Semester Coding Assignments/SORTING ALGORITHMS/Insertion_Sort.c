#include <stdio.h>

void insertion_sort(int arr[], int n){
    int i, j, key;
    int pass_count = 0;

    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertion_sort(SORT_THIS_ASC, n);
    printf("\n");

    printf("After Sorting: ");
    for(i = 0; i < n; i++){
        printf("%d ", SORT_THIS_ASC[i]);
    }

    return 0;
}