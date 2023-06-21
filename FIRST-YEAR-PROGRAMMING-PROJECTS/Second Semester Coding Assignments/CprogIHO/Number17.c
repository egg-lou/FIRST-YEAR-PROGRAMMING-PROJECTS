#include <stdio.h>

int converter(int toConvert){

    int decimal = 0;
    int place = 1;
    int digit;

    int temp = toConvert;
    while(temp > 0){

        digit = temp % 10;
        decimal += digit * place;
        place *= 8;
        temp /= 10; 
    }

    return decimal;
}


int main(){

    int octal;

    printf("Input an octal number (using digits 0 - 7): ");
    scanf("%d", &octal);

    int decimal = converter(octal);

    printf("The Octal Number: %d\n", octal);
    printf("The equivalent Decimal Number: %d", decimal);
    return 0;
}