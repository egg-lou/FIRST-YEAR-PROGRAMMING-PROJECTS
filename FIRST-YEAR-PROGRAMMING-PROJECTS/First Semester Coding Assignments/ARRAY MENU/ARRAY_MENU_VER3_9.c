/*PROGRAM: ARRAY MENU
CREATION DATE: 13/02/23
AUTHOR: GROUP 4
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main(){
    int X[5] = {-1,-1,-1,-1,-1}; //Initialization of the X[5] Array
    int num_count, num_tracker; // Tracker and counter for the inputting of numbers in the welcome
    char addnum, try, exit_operation, name[80]; //For char and array variables
    int i, j; //Indexes
    int operation, bef_exit; //Variables in the Menu 
    int toSearch, found, sorting, temp, toInsert, pos, toDelete; //Variables for each of the operations in the menu

    //Asks for the user's name and asks to input at least 2-3 numbers
    //Loop for entering the numbers will continue to run if it does not satisfy the 2-3 numbers entered
    do{
        printf("\n==================================================================\n");
        printf("                    WELCOME TO THE ARRAY MENU!");
        printf("\n==================================================================\n");
        printf("\nHi! What's your name?");
        printf("\nName: ");
        gets(name);
        printf("\n%s, Please enter at least 2 -3 numbers [Min. 2 - Max. 3]\n", name);

            num_count = 0;
            for(i = 0; i < 3; i++){
                printf("[%d] Enter Number: ", i+1);
                scanf("%d", &X[i]);
                num_tracker++;
                num_count++;

                printf("\nEnter another number? \'Y\' for YES & \'N\' for NO: ");
                scanf(" %c", &addnum);

                if(addnum == 'Y' || addnum == 'y'){
                    if(num_count >= 3){
                        printf("\nSorry %s, but you cannot add another number,\n", name);
                        printf("you have already reached the max limit of 3 numbers");
                        goto next; //Jump to next since it already satisfied the condition
                    }
                    else{
                        continue; 
                    }
                }
                else if(addnum == 'N' || addnum == 'n'){
                    if(num_count >=2 && num_count <= 3){
                        goto next; //Jump to next since it already satisfied the condition
                    }
                    else if(num_count == 1){
                        printf("\n%s, you did not enter a minumum of 2 numbers!", name);
                        printf("\nPlease continue entering a number\n");
                        continue; //Did not satisfy the no. of entered numbers
                    }
                }
            }
        }while(num_count > 0);
        
        next: //Next part of the code after the data entry & serves as the next base
            printf("\n------------------------------------------------------------------");
            printf("\nYou entered %d numbers,", num_count);
            printf("\nX[5] = {");
            for(i = 0; i < num_tracker; i++){
                printf("%d%s", X[i], (i == num_tracker - 1) ? "" : ", ");    
            }
                printf("}\n\n");
            system("pause");
        
    menu: //A base to return to the menu 
        do{ //Menu
            system("cls");
            printf("\n==================================================================\n");
            printf("                            ARRAY MENU");
            printf("\n==================================================================\n");
            printf("                   X[5] = {");
            for(i = 0; i < 5; i++){ //Displays the current values of the array
                printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", "); 
            }
                printf("}\n");
            printf("\n[1] Search by Position");
            printf("\n[2] Insertion");
            printf("\n[3] Deletion");
            printf("\n[4] Sort");
            printf("\n[5] Exit");
            printf("\n------------------------------------------------------------------");

            printf("\nChoose an Operation from 1 - 5");
            printf("\nOperation of Choice: ");
            scanf("%d", &operation);

            if(operation > 5 || operation < 1){
                printf("INVALID INPUT!");
            }
        }while(operation > 5 && operation < 1);

        switch(operation){
            case 1:{ //Searching
                do{
                    system("cls");
                    printf("\n------------------------------------------------------------------");
                    printf("\nSearching an element's position in the array");
                    printf("\n------------------------------------------------------------------\n");
                    printf("                   X[5] = {"); //Displays the current array
                         for(i = 0; i < 5; i++){
                            printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
                        }
                        printf("}");
                        printf("\n");
                    printf("\nEnter Number to be Searched: ");
                    scanf("%d", &toSearch);
                    found = 0;
                    for(i = 0; i < 5; i++){
                        if(X[i] == toSearch){
                            printf("\nNumber %d is found at X[%d] or position %d", toSearch, i, i+1);
                            found = 1;
                            break;
                    }
                }
                if(found == 0){
                    printf("\nNumber %d is not found in the array", toSearch);
                }
                printf("\n"); //Asks the user if they want to do it again
                printf("\n------------------------------------------------------------------");
                printf("\nWant to do another search? \'Y\' for YES & \'N\' for NO: ");
                scanf(" %c", &try);

                }while(try == 'Y' || try == 'y');
                break;
            }
            case 2:{
                do{ //Insertion
                    system("cls");
                    printf("\n------------------------------------------------------------------");
                    printf("\nData Insertion");
                    printf("\n------------------------------------------------------------------\n");
                    printf("                 X[5] = {");
                    for(i = 0; i < 5; i++){
                        printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
                    }
                    printf("}");

                    do{
                        printf("\n");
                        printf("\nPlease enter the position where you want to insert a number: ");
                        scanf("%d", &pos);

                        if (pos < 1 || pos > 5) {
                            printf("\nError: The position you entered is invalid. The size of the array is %d.", 5);
                        } 
                    }while(pos > 5 || pos < 1);
                    printf("\nSpecify the number you want to place in that position: ");
                    scanf("%d", &toInsert);

                    if(X[pos - 1] != -1){
                        printf("\nElement %d is with a value of %d is about to be replaced with %d", pos,X[pos -1], toInsert);
                        printf("\n");
                        system("pause");
                        X[pos - 1] = toInsert;
                        printf("\nThe insertion of the number to the array was a SUCCESS!");
                    }
                    else{
                        X[pos - 1] = toInsert;
                        printf("\nThe insertion of the number to the array was a SUCCESS!");
                    }
                    printf("\n");
                    printf("\nNew Values: ");
                    printf("\n");
                    printf("                 X[5] = {");
                        for(i = 0; i < 5; i++){ //Prints the new values after insertion
                        printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
                    }
                    printf("}");

                    printf("\n"); //Asks the user if they want to do it again
                    printf("\n------------------------------------------------------------------");
                    printf("\nWant to do another insertion? \'Y\' for YES & \'N\' for NO: ");
                    scanf(" %c", &try);

                }while(try == 'Y' || try == 'y');
                break;
            }
            case 3:{
                do{ //Deletion
                    system("cls");
                    printf("\n------------------------------------------------------------------");
                    printf("\nElement Deletion");
                    printf("\n------------------------------------------------------------------\n");
                    printf("                 X[5] = {");
                    for(i = 0; i < 5; i++){
                        printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
                    }
                    printf("}");

                    found = 0;
                    printf("\n");
                    printf("\nEnter the Number to Delete from the array: ");
                    scanf("%d", &toDelete);



                    for(i = 0; i < 5; i++){ //Searching for the element in the array
                        if(X[i] == toDelete){ //If a match
                            printf("\n%d was deleted from the array\n", X[i], toDelete);
                            X[i] = -1; //Resets the value of the matched number to be deleted back to -1
                            found = 1;
                        }
                    }
                    if(found == 0){
                        printf("%d is not in the array", toDelete);
                    }
                    printf("\nNew Values: ");
                    printf("\n");
                    printf("                 X[5] = {");
                    for(i = 0; i < 5; i++){ //Printing of the new values in the array
                        printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
                    }
                    printf("}");
                    printf("\n"); //Asks the user if they want to do it again
                    printf("\n------------------------------------------------------------------");
                    printf("\nWant to do another deletion? \'Y\' for YES & \'N\' for NO: ");
                    scanf(" %c", &try);
                }while(try == 'Y' || try == 'y');
                break;
            }
            case 4:{
                do{//Descending or Ascending Sorting
                    system("cls");
                    printf("\n------------------------------------------------------------------");
	                printf("\nSORT: Ascending or Descending Order: \n");
	                printf("\n------------------------------------------------------------------\n");
                    printf("\n");
                    printf("               X[5] = {");
                    for(i = 0; i < 5; i++){
                        printf("%d%s", (X[i] == -1) ? 0 : X[i], (i == 4) ? "" : ", ");
                    }
                    printf("}");
                    printf("\n");
	                printf("\nHow would you like your inputs to be sorted?\n");
                    printf("Kindly choose between the following:\n");
	                printf("[1] ASCENDING ORDER\n");
	                printf("[2] DESCENDING ORDER\n");
	                printf("\nSort it by: ");
	                scanf("%d", &sorting);
	

	                if (sorting == 1){
		                printf("\nThe Ascending Order of your inputs would be:\n");
		                    for (i=1; i < 5 - 1; i++) 	
			                    for (j=0; j < 5 - 1; j++) {
				                    if (X[j] > X[j+1]) {
				                        temp = X[j];
                                        X[j] = X[j+1];
                                        X[j+1] = temp;
          	                            }
			                        }
	                }
	                else if (sorting == 2){
		                printf("The Descending Order of your inputs would be:\n");
		                    for (i=0; i < 5 - 1; i++) {
			                    for (j = 0; j < 5 - i - 1; j++){
				                    if (X[j] < X[j + 1]) {
				                        temp = X[j];
                                        X[j] = X[j + 1];
                                        X[j + 1] = temp;
          	                        }
			                    }
		                    }
	                }
                    for (i=0; i < 5; i++){
                        if(X[i] != -1)
		                    printf("-> %d ", X[i]); //Prints the sorted array
		                }
                printf("\n"); //Asks the user if they want to do it again
                printf("\n------------------------------------------------------------------");
                printf("\nWant to do another sorting? \'Y\' for YES & \'N\' for NO: ");
                scanf(" %c", &try);
                }while(try == 'Y' || try == 'y');
                break;
            }
            case 5:{ //Exit
                    system("cls");
                    printf("\n------------------------------------------------------------------");
                    printf("\nExit");
                    printf("\n------------------------------------------------------------------");
                    printf("\nPRESS 1 to EXIT");
                    printf("\nPRESS 2 to go back to the MENU");
                    printf("\nChoice: ");
                    scanf("%d", &bef_exit);

                    if(bef_exit == 1){
                        goto end; //To jump at the end of the program
                    }
                    else if(bef_exit == 2){
                        goto menu; //To jump back to the menu
                    }
            }
        }
        printf("\n");
        printf("\n------------------------------------------------------------------");
        printf("\nDo you want to EXIT or GO BACK TO THE MENU?\n");
        printf("\nPRESS M for MENU");
        printf("\nPRESS E for EXIT");
        printf("\nChoice: ");
        scanf(" %c", &exit_operation);
        if(exit_operation == 'M' || exit_operation == 'm'){
            goto menu;
        }
        else if(exit_operation == 'E' || exit_operation == 'e'){
            goto end;
        }
    end: //Landing for the end of the program
        printf("\nThank you for using the program!");
        printf("\nGoodbye! %s", name);
        getch();
    return 0;
}