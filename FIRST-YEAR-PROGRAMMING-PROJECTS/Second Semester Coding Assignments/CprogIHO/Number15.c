#include <stdio.h>

int converter(long long int toConvert){

    int decimal = 0;
    int place = 1;
    int digit;

    int temp = toConvert;
    while(temp > 0){

        digit = temp % 10;
        decimal += digit * place;
        place *= 2;
        temp /= 10; 
    }

    return decimal;
}


int main(){

    int binary;

    printf("Input a binary number: ");
    scanf("%d", &binary);

    int decimal = converter(binary);

    printf("The Binary Number : %d\n", binary);
    printf("The equivalent Decimal Number : %d\n", decimal);
    return 0;
}