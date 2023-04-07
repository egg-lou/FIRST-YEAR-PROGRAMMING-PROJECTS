#include <stdio.h>

int main(int argc, const char * argv[]){
    
    int a, b, c;

    printf("Enter three different integers: \n");
    scanf("%d %d %d", &a, &b, &c);

    if(a>b){
        if(a>c)
            printf("%d is the largest number\n",a);
        else
            printf("%d is the largest number\n",c);
    }
    else{
        if (b>c)
            printf("%d is the largest number\n",b);
        else
            printf("%d is the largest number\n",c);
    }
    
    printf("Thank you!");
    return 0;
}