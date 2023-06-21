#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}

void printPerfectNumbers(int start, int end) {
    printf("The perfect numbers between %d to %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if (isPerfect(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    printf("Input lowest search limit of perfect numbers: ");
    scanf("%d", &start);

    printf("Input highest search limit of perfect numbers: ");
    scanf("%d", &end);

    printPerfectNumbers(start, end);

    return 0;
}
