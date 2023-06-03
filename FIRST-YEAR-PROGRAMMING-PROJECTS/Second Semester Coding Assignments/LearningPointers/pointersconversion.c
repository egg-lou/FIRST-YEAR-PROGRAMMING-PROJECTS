#include <stdio.h>



int main(){

    double x = 100.1, y;

    int *p = NULL;


    p = (int *)&x;

    y = *p;


    return 0;
}