#include <stdio.h>

//Create a program that will calculate the weekly wage of hourly employees
int main(int agrc, const char * argv[]){
    /* hours = Amount of hours worked by the employee
       Rwage = the employee's wage for this week (for regular hours)
       OTwage = the employee's wage this week (for overtime)
       const MaxHours = the limit for regular hours
       name = Employee's name
       const PerHr = Payment per hr*/
    int hours, Rwage, OTwage;
    int const MaxHours = 40;
    int const PerHr = 10;
    char name[80];

    //Input the name of the employee
    printf("Enter your Name: ");
    scanf("%s", &name);

    //Input the number of hours the employee worked for the week
    printf("Enter the hour/s of work this week: ");
    scanf("%d", &hours);

    /*If-Else statement to know the weekly wage of the hourly paid employees. If the employee worked within the MaxHours
    of 40hrs, the hours the employee worked will be  multiplied to 10 while if the employee worked overtime, his/her wage 
    will be maxed to 40*10 = 400 plus the overtime hours he/she worked by 15
    */
    if (hours >= 0 && hours <= MaxHours){
        Rwage = hours * PerHr;
        printf("%s, your wage for this week is $%d \n", name, Rwage);
    }
    else{
        OTwage = MaxHours*PerHr + (hours - MaxHours) *PerHr*1.5;
        printf("%s, you worked overtime for this week so your wage is $%d \n", name, OTwage);
    }

    //Thank you message for the user
    printf("Thank you for using the program!");

    return 0;
}