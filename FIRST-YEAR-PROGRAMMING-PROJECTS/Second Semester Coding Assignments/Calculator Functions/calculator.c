#include <C:\Calculator Functions\addition.c>
#include <C:\Calculator Functions\subtraction.c>
#include <C:\Calculator Functions\multiplication.c>
#include <C:\Calculator Functions\division.c>
#include <C:\Calculator Functions\options.c>


int calculator (){
    float num1, num2;
    int userChoice = 0;
    int done = 0;

    do{
        do{
        options();

        printf("\nResponse: ");
        scanf("%d", &userChoice);

        if(userChoice == 5)
            break;
        if(userChoice < 1 || userChoice > 5){
            printf("INVALID INPUT!!!");
            system("cls");
            }
        
            switch(userChoice){
                case 1: {

                    done = addition();
                    system("cls");
                    break;
                }

                case 2: {

                    done = subtraction();
                    system("cls");
                    break;
                }

                case 3: {

                    done = multiplication();
                    system("cls");
                    break;
                }

                case 4: {

                    done = division();
                    system("cls");
                    break;
                }
            }
        }while(done == 2);

    }while(userChoice < 1 || userChoice > 5);

}