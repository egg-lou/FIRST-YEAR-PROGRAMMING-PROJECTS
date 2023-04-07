#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main(){

    int operations, response, des_asc, temp, bef_exit;
    int X[5] = {0,0,0,0,0};
    int i,j, toSearch, toDelete, toInsert, found, pos, a, c;
    int b = 5;


    do{
        system("cls");
        printf("\t    ARRAY MENU");
        printf("\n-------------------------------------");
        printf("\n[1] Create Data");
        printf("\n[2] Display Data");
        printf("\n[3] Search by Position");
        printf("\n[4] Delete an Element");
        printf("\n[5] Append");
        printf("\n[6] Sort");
        printf("\n[0] Exit");
        printf("\n-------------------------------------");

        printf("\nOperation: ");
        scanf("%d", &operations);

        switch(operations){
            case 0:{
                system("cls");
                printf("-------------------------------------");
                printf("\nAre you sure do you want to exit?");
                printf("\nPRESS 1 for YES");
                printf("\nPRESS 2 for NO");
                printf("\n-------------------------------------");
                printf("\nExit: ");
                scanf("%d", &bef_exit);

                if(bef_exit == 1){
                    goto end;
                }
                else if(bef_exit == 2){
                    goto x;
                }
            }
            case 1:{
                system("cls");
                printf("-------------------------------------");
                printf("\nCreating Data");
                printf("\n-------------------------------------\n");
                printf("\nEnter number of data to be inputted: ");
                scanf("%d", &a);
                if(a == 2 || a == 3){
                    printf("\nEnter %d numbers: \n", a);
                    for(i=0; i < a; i++ ){
                        printf("[%d]: ", i+1);
                        scanf("%d", &X[i]);
                    }
                    printf("\nThese are the numbers you entered: ");
                        for(i = 0; i < a; i++){
                        printf("\n[%d] = %d", i, X[i]);
                        }
                }
                    goto x;
            break;
            }
            case 2:{
                system("cls");
                printf("-------------------------------------");
                printf("\nCurrent Data\n");
                printf("\n-------------------------------------\n");
                for(i = 0; i < b; i++){
                    printf("[%d] = %d\n",i, X[i]);
                }
                goto x;
            }
            break;
            case 3: {
                system("cls");
                printf("-------------------------------------");
                printf("\nSearching a number's position in the array");
                printf("\n-------------------------------------");
                printf("\nEnter Number to Search by Position: ");
                scanf("%d", &toSearch);
                found = 0;
                for(i = 0; i < b; i++){
                    if(X[i] == toSearch){
                        found = 1;
                        break;
                    }
                }
                if(found == 1){
                    printf("\n%d searched for is found at position %d", toSearch, i + 1);
                }
                else{
                    printf("\n%d is not found in the array", toSearch);
                }
                goto x;
            }
            break;
            case 4: {
                system("cls");
                printf("-------------------------------------");
                printf("\nNumber Deletion");
                printf("\n-------------------------------------");
                printf("\nEnter Number to Delete: ");
                scanf("%d", &toDelete);

                for(i = 0; i < b; i++){
                    if(X[i] == toDelete){
                        for(j = i; j < b - 1; j++){
                            X[j] = X[j + 1];
                        }
                        b--;
                        printf("\n%d was deleted from the array\n", toDelete);
                        b = 5;
                        for(i = 0; i < b; i++){
                            printf("\n[%d] = %d", i, X[i]);
                        }
                    }
                }
            break;
            goto x;
            }
            case 5: {
                system("cls");
                printf("-------------------------------------");
                printf("\nData Insertion");
                printf("\n-------------------------------------");
                printf("\nEnter the position you want to insert the number: ");
                scanf("%d", &pos);

                printf("\nEnter the number you want to insert: ");
                scanf("%d", &toInsert);

                for(i= b; i >= pos; i--){
                    X[i] = X[i-1];
                }
                X[pos - 1] = toInsert;

                printf("\nArray after inserting new element: ");
                for(i = 0; i < b; i++){
                    printf("\n[%d] = %d", i, X[i]);
                }
            break;
            goto x;
            }
            case 6:{
                system("cls");
                printf("-------------------------------------");
                printf("\nSORT: Ascending or Descending");
                printf("\n-------------------------------------");
                printf("\n[1] Ascending Order");
                printf("\n[2] Descending Order");
                printf("\nSorting Order: ");
                scanf("%d", &des_asc);

                
                if(des_asc == 1){
                    printf("\nAscending Order: ");
                    for(i=0; i<3; i++){
                        for(j = i + 1; j < 3; j++){
                            if(X[i] > X[j]){
                                temp = X[i];
                                X[i] = X[j];
                                X[j] = temp;
                            }
                        }
                    }
                for(i=0; i<3; i++){
                    printf("%d ", X[i]);
                }
                }
                else if(des_asc == 2){
                    printf("\nDescending Order: ");
                    for(i = 0; i < 3; ++i){
                        for(j = i + 1; j < 3; ++j){
                            if(X[i] < X[j]){
                                temp = X[i];
                                X[i] = X[j];
                                X[j] = temp;
                            }
                        }
                    }
                    for(i = 0; i < 3; ++i){
                        printf("%d ",X[i]);
                    }
                }
            break;
            goto x;
            }
        }
        x:
            printf("\n\nContinue? PRESS 1 for YES & PRESS 2 for NO: ");
            scanf("%d", &response);
    }while(response ==1 );
    end:
        printf("\nThank you for using the program!");
    getch();
    return 0;
}