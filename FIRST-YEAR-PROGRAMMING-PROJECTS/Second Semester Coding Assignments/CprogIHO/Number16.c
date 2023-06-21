#include <stdio.h>

int converter(int toConvert){

    int octal = 0;
    int place = 1;
    int digit;

    int temp = toConvert;
    while(temp > 0){

        digit = temp % 8;
        octal += digit * place;
        place *= 10;
        temp /= 8; 
    }

    return octal;
}


int main(){

    int decimal;

    printf("Enter a number to convert: ");
    scanf("%d", &decimal);

    int octal = converter(decimal);

    printf("The Octal of %d is %d\n", decimal, octal);
    return 0;
}