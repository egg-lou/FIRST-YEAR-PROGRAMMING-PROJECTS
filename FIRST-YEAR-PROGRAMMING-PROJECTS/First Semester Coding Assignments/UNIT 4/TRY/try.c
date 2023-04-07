#include <stdio.h>


int main(){

    int a;
    int c = 0; //For c to start from 0

    x:
    c++;
    a = 5; //To store the value of a 
    if(c==1){
        a = a*a;
        printf("The value of a is %d\n", a);
        goto x;
    }
    else{
        if(c==2){
            a = a + a;
            printf("The value of a is %d\n", a);
            goto x;
        }
        else{
            a = a - a;
            printf("The value of a is %d\n", a);
        }
    }
    return 0;
}