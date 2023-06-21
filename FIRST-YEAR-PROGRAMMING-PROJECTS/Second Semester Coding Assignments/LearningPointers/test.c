#include <stdio.h>

void sum(int x[]) {
    int n = 0;
    int sum_even = 0;
    int sum_odd = 0;

    // Calculate the size of the array
    int* p = x;
    while (*p != '\0') {
        p++;
        n++;
    }

    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0) {
            sum_even += x[i];
        } else {
            sum_odd += x[i];
        }
    }

    printf("Sum of even numbers: %d\n", sum_even);
    printf("Sum of odd numbers: %d\n", sum_odd);
}

int main() {
    int arr[] = {2, 5, 8, 3, 6, 4, 1};
    sum(arr);
    return 0;
}

