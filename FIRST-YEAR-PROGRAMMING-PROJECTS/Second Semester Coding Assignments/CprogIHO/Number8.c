#include <stdio.h>

int converter(int toConvert){

    int binary = 0;
    int place = 1;

    while(toConvert > 0){
        binary += (toConvert % 2) * place;
        toConvert /= 2;
        place *= 10; 
    }

    return binary;
}


int main(){

    int decimal;

    printf("Input a binary number: ");
    scanf("%d", &decimal);

    long long int binary = converter(decimal);

    printf("The Binary value is : %d\n", binary);
    return 0;
}