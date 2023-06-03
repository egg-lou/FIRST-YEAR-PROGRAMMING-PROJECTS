#include <stdio.h>



int main(){

    int var = 10;
    int *ptr1 = NULL;
    ptr1 = &var;
   

    int **ptr2 = NULL;
    ptr2 = &ptr1;
    **ptr2 = 30;
    int *ptr3 = ptr1;
     *ptr1 = 20;


    printf("\n address of var :%p\n", &var);
    printf("\n address of *ptr1 :%p\n", ptr1);
    printf("\n address of **ptr2 :%p\n", ptr2);
    printf("\n address of *ptr3 :%p\n", ptr3);

    printf("\n value of var :%d\n", var);
    printf("\n value of *ptr1 :%d\n", *ptr1);
    printf("\n value of **ptr2 :%d\n", **ptr2);
    printf("\n value of *ptr3 :%d\n", *ptr3);


    return 0;
}