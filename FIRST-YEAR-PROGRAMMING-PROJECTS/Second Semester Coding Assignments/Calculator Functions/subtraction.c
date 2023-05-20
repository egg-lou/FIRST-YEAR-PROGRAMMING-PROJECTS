float subtraction (){
    float num1, num2;
    int again = 0;
    do{
        system("cls");
        printf("\nSUBTRACTION\n");
        printf("----------------\n");

        printf("\nEnter 2 numbers ");
        printf("\nFirst Number: ");
        scanf("%g", &num1);

        printf("\nSecond Number: ");
        scanf("%g", &num2);


        printf("\nResult: %g - %g = %g\n", num1, num2, num1-num2);

        do{
            printf("\n-------------------------------------");
            printf("\nTry Again? [1] for YES and [2] for NO");
            printf("\nResponse: ");
            scanf("%d", &again);

            if(again == 2)
                break;

            if(again != 1 && again != 2)
                printf("INVALID INPUT!!!");
            }while(again != 1 && again != 2);
                
        }while(again == 1);

        return again;
}