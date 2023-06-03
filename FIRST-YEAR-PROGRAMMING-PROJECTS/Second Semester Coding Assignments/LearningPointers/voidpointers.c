#include <stdio.h>



int main(){
    int num = 10;
    void *ptr = NULL;

    printf("%d", *(int* )&num);

    return 0;
}