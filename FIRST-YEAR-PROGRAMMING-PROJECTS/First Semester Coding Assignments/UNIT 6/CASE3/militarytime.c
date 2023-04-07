/*
Program: Military Time Conversion
Author: Rafael Louie V. Miguel
Creation Date: 02/19/2023
*/

#include <stdio.h>
#include <conio.h>

/*MilitaryTime Function will convert the Military time entered
to the standard 12Hr Format
*/
void MilitaryTime(int *time){
    int h, m, H;

    h = *time / 100;
    m = *time % 100;

    if((h >= 0 && h <= 24) && (m >= 0 && m <= 59)){
        if(h > 12 && h < 23){
            H = h%12;
            printf("\nThe standard time of %d:%02dPM", H, m);
        }
    else if(h == 0 || h == 24){
        H = 12;
        printf("\nThe standard time of %d:%02dAM", H, m);
    }
    else{
        H=h;
        printf("\nThe standard time of %d:%02dAM", H, m);
    }
    }
}

int main(){
    int Military_time;

    do{
        printf("\nEnter Military Time must be [0-2400] Only: ");
        scanf("%d", &Military_time);

        if(Military_time < 0 || Military_time > 2400){
            printf("Military Time Entered must be within [0-2400] Only!");
        }
    }while(Military_time < 0 || Military_time > 2400);

    printf("%04d Military Time is eqiuvalent to: ", Military_time);

    MilitaryTime(&Military_time);
    
    printf("\nThank you for using the program!");
    getch();
    return 0;
}
