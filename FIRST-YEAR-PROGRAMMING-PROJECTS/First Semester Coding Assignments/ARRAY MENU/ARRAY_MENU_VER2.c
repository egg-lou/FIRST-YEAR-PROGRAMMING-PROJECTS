/*PROGRAM: ARRAY MENU
CREATION DATE: DD/MM/YY
AUTHOR: GROUP 4
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(){
    int add_count, a;  // Number Input Variables
    int X[5] = {0,0,0,0,0};  //Initialization of the X array with size 5
    char name [80]; //User's name variable
    add_count = 0; //Counter for number of inputted numbers by the user
    a = 0; //Counter for the printing of numbers entered by the user
    char response_add; //Response variable to add another number
    int i, j, k, b; //Index Variables 
    int response_main, operation, real_exit, bef_exit;
    int toSearch, found, toInsert, pos, toDelete, sorting, temp;
    b = 5;


    printf("\nWelcome to the Array Menu!");
    printf("\nWhat's your name?");
    printf("\nName: ");
    gets(name);

    printf("\nHi %s, Please enter the numbers that will be stored [min. 2 - max. 3]\n", name);


    do{
        for(i = 0; i < 3; i++){
            printf("\nEnter Number: ");
            scanf("%d", &X[i]);
            a++;
            add_count++;
            printf("\nEnter another number? (Y/N): ");
            scanf(" %c", &response_add);

            if(response_add == 'Y' || response_add == 'y'){
                if(add_count >= 3){
                    printf("You cannot add another number, you've reached the max limit of 3!");
                    goto next;
                }
                else{
                    continue;
                }
            }
            else if(response_add == 'N' || response_add == 'n'){
                if(add_count >= 2 && add_count <= 3){
                    goto next;
                }
                else if(add_count == 1){
                    printf("\nYou did not enter a minimum of 2 numbers!");
                    printf("\nPlease continue adding a number\n");
                    continue;
                }
            }
        }
    
    }while(add_count > 0);
    next:
        printf("\n%s, These are the numbers you entered: \n", name);
        for(i = 0; i < a; i++){
            printf("%d ", X[i]);
        }
    printf("\n\n");
    system("pause");

    do{
        system("cls");
        printf("-------------------------------------\n");
        printf("\t    ARRAY MENU");
        printf("\n-------------------------------------");
        printf("\n[1] Search by Position");
        printf("\n[2] Insertion");
        printf("\n[3] Deletion");
        printf("\n[4] Sort");
        printf("\n[5] Exit");
        printf("\n-------------------------------------");

        printf("\nARRAY\n");
        for(i = 0; i < 5; i++){
            printf("\t %d ", X[i]);
        }
        printf("\n");
        for(i=0; i < 5; i++){
            printf("\t[%d]", i);
        }

        printf("\nOperation: ");
        scanf("%d", &operation);
      

      switch(operation){
        case 1:{
            system("cls");
            printf("-------------------------------------");
            printf("\nSearching an element's position in the array");
            printf("\n-------------------------------------");
            printf("\nEnter Element to be Searched: ");
            scanf("%d", &toSearch);
            found = 0;
            for(i = 0; i < b; i++){
                if(X[i] == toSearch){
                    printf("\nElement %d is found at X[%d] or position %d", toSearch, i, i+1);
                    found = 1;
                    break;
                    }
                }
                if(found == 0){
                    printf("\nElement %d is not found in the array", toSearch);
                }
                goto x;
        }
        case 2: {
                system("cls");
                printf("-------------------------------------");
                printf("\nData Insertion");
                printf("\n-------------------------------------");
                
                // Check if the entered position is within the array bounds
                printf("\nPlease enter the position where you want to insert a number: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > 5) {
                    printf("\nError: The position you entered is invalid. The size of the array is %d.", a);
                } 
                else {
                // Check if the entered value contains only one number
                printf("\nSpecify the number you want to place in that position: ");
                scanf("%d", &toInsert);
                 // Shift the elements in the array to make room for the new value
                for (i = b - 1; i >= pos - 1; i--) {
                    X[i + 1] = X[i];
                    }
                    
                // Inserting the new number at the specified position 
                    X[pos - 1] = toInsert;
                    
                // Print the updated array
                    printf("\nThe array after inserting the new element is: ");
                    for(i = 0; i < b; i++){
                        printf("\n[%d] = %d", i, X[i]);
                    }
                }
            break;
            goto x;
        }
        case 3: {
                system("cls");
                printf("-------------------------------------");
                printf("\nNumber Deletion");
                printf("\n-------------------------------------\n");
                printf("\nThese are the numbers you entered: ");
                        for(i = 0; i < b; i++)
                        {
                        printf("\n[%d] = %d", i, X[i]);
                        }
                printf("\n\nEnter Number to Delete: ");
                scanf("%d", &toDelete);

                found = 0;

                for(i = 0; i < b; i++){
                    if(X[i] == toDelete){
                        for(j = i; j < b - 1; j++){
                            X[j] = X[j + 1];
                        }
                        b--;
                        printf("\n%d was deleted from the array\n", toDelete);
                        b = 5;
                        found = 1;
                        for(i = 0; i < b; i++){
                            printf("\n[%d] = %d", i, X[i]);
                        }
                    }
                } if(found == 0)
                        {printf("\nThe number you entered is invalid\n");}
                    break;
            goto x;
        }
        case 4: {
                system("cls");
                printf("\n---------------------------------------------------");
	            printf("\n SORT: Ascending or Descending Order: \n");
	            printf("---------------------------------------------------");
	            printf("\nHow would you like your inputs to be sorted? Kindly choose between the following:\n");
	            printf("[1] ASCENDING ORDER\n");
	            printf("[2] DESCENDING ORDER\n");
	            printf("Sort it by: ");
	            scanf("%d", &sorting);
	

	            if (sorting == 1){
		            printf("\nThe Ascending Order of your inputs would be:\n");
		                for (i=1; i < 3; i++) 	
			                for (j=0; j<a - 1; j++) {
				                if (X[j] > X[j+1]) {
				                    temp = X[j];
                                    X[j] = X[j+1];
                                    X[j+1] = temp;
          	                        }
			                    }
		                        for (i=0; i<a; i++){
		                        printf("-> %d  ", X[i]);
		                        }
	            }
	            else if (sorting == 2){
		            printf("The Descending Order of your inputs would be:\n");
		                for (i=0; i < 3; ++i) {
			                for (j=i+1; j< 3; ++j){
				                if (X[i] < X[j]) {
				                    temp = X[i];
                                    X[i] = X[j];
                                    X[j] = temp;
          	                    }
			                }
		                }	
		                for (i=0; i< 3; i++){
		                printf("-> %d ", X[i]);
		                }
	            }
            break;
            goto x;
        }
        case 5: {
            system("cls");
            printf("\n---------------------------------------------------");
            printf("\nExit");
            printf("\n---------------------------------------------------");
            printf("\nPRESS 1 for YES");
            printf("\nPRESS 2 for NO");
            printf("\nAre you sure do you want to exit: ");
            scanf("%d", &bef_exit);

            if(bef_exit == 1){
                goto end;
            }
            else if(bef_exit == 2){
                goto x;
            }
        }
    }

      x: 
        printf("\n\nContinue? PRESS 1 for YES & PRESS 2 for NO: ");
        scanf("%d", &response_main);
    }while(response_main == 1);
end:
    printf("\nThank you for using the program!");
    printf("\nGoodbye! %s", name);
    getch();
  return 0;
}