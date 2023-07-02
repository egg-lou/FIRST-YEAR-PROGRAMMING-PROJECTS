#include <stdio.h>

struct months
{
    int monthNum;
    char monthName [80];
    int monthDays;
}mth[12];


struct months mth[12] = {{1, "January", 31}, 
                        {2, "February", 28}, 
                        {3, "March", 31}, 
                        {4, "April", 30}, 
                        {5, "May", 31}, 
                        {6, "June", 30}, 
                        {7, "July", 31},
                        {8, "August", 31}, 
                        {9, "September", 30}, 
                        {10, "October", 31}, 
                        {11, "November", 30}, 
                        {12, "December", 31}};


int main(){

    for(int i = 0; i < 12; i++){
        printf("%d, %s, %d\n", mth[i].monthNum, mth[i].monthName, mth[i].monthDays);
    }

return 0;
};