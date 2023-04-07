#include <stdio.h>

int main(int argc, char*argv[]){

    char color;

    printf("Input Traffic Color: ");
    scanf("%c", &color);

    if (color == 'r' || color == 'R')
        printf("STOP");
    else if (color == 'y' || color == 'Y')
        printf("WAIT");
    else if (color == 'g' || color == 'G')
        printf("GO");

    printf("\nCareful in Driving");
    printf("Thank you!");

    return 0;
}