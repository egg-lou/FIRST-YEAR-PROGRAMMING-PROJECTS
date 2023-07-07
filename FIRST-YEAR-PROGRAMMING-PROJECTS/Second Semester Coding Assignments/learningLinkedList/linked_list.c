#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Basics of Linked List 
        - Create, Read, Update, Delete
        - Reverse a linked list
*/

struct Node
{
    int data;  //Holds data of the Node
    struct Node* next; //Holds the address of the next link
};

struct Node* head;  //Global variable, can be accessed anywhere

void Insert(int x);
void InsertSpecific(int data, int position);
void DeleteAtPosition(int position);
void Reverse1();
void Reverse2(struct Node* p);
void Print();

int main(void) {

    head = NULL;
    int options, UserChoice, again, reverseway;
    int n, i, x, position, insidecounter, outsidecounter = 0;

    do {
        if(outsidecounter >= 1){
            system("cls");
        }
        printf("\nLINKED LIST MENU\n");
        printf("Current ");
        Print();
        printf("\nOPTIONS:\n");
        printf("\n[1] Input Numbers in the Linked List");
        printf("\n[2] Input a Number at a Specific Position");
        printf("\n[3] Delete a Specific Position in the Linked List");
        printf("\n[4] Reverse Linked List");
        printf("\n[5] EXIT");
        printf("\nOPERATION: ");
        scanf("%d", &UserChoice);

        switch (UserChoice) {
            case 1: { //Input numbers at the start of the linked list
                insidecounter = 0;
                do {
                    if(insidecounter >= 1){
                        system("cls");
                    }
                    printf("Enter how many numbers you want to insert: ");  //How many numbers to be inserted in the linked list
                    scanf("%d", &n);
                    for (i = 0; i < n; i++) {
                        printf("Enter a number: "); //The numbers to be inserted
                        scanf("%d", &x);
                        Insert(x);
                    }
                    printf("\nThe numbers you inserted into the linked list: ");
                    Print();  //The numbers inside the list
                    printf("\nDo you still want to continue? [1] Yes & [2] No ");
                    scanf("%d", &again);
                    if(again == 1){
                        insidecounter++;
                    }
                } while (again == 1);

                printf("\nThe Numbers in the Linked List: ");
                Print();
                outsidecounter++;
                break;
            }
            case 2: {
                insidecounter = 0;
                do{
                    if(insidecounter >= 1){
                        system("cls");
                    }
                    printf("\nEnter the Number and the Position where you want to insert it: ");  //The number and the position where you want to insert it
                    printf("\nNumber: ");
                    scanf("%d", &x);  //data
                    printf("\nPosition: ");
                    scanf("%d", &position);  //position
                    InsertSpecific(x, position);  //InsertSpecific Functiuon
                    printf("\n");
                    printf("Updated ");
                    Print();
                    printf("\nDo you still want to continue? [1] Yes & [2] No ");
                    scanf("%d", &again);
                    if(again == 1){
                        insidecounter++;
                    }
                }while(again == 1);
                outsidecounter++;
                break;
            }
            case 3: {
                insidecounter = 0;

                do{
                    if(insidecounter >= 1){
                        system("cls");
                    }
                    printf("\nCurrent ");
                    Print();
                    printf("\nEnter the position that you want to delete: ");
                    scanf("%d", &position);
                    DeleteAtPosition(position);
                    printf("\n");
                    printf("Updated ");
                    Print();
                    printf("\nDo you still want to continue? [1] Yes & [2] No ");
                    scanf("%d", &again);
                    if(again == 1){
                        insidecounter++;
                    }

                }while(again == 1);
                outsidecounter++;
                break;
            }
            case 4: {  //Reverses the linked list
                insidecounter = 0;
                do{
                    printf("\nPress [1] to reverse the list using Iteration and [2] to reverse it using recursion");
                    printf("\nOption: ");
                    scanf("%d", &reverseway);

                    if(reverseway == 1){  //Iteration Method
                        Reverse1();
                        printf("\nThe Reversed ");
                        Print();
                    }

                    else if(reverseway == 2){  //Recursion Method
                        printf("\nThe Reversed List is: ");
                        Reverse2(head);
                    }

                    printf("\nDo you still want to continue? [1] Yes & [2] No ");
                    scanf("%d", &again);
                    if(again == 1){
                        insidecounter++;
                    }

                }while(again == 1);

            }
            default: {
                if(UserChoice > 5)
                    printf("Invalid choice.\n");
                break;
            }
        }
    } while (UserChoice != 5);
    printf("\nThank you for using the program!");
    getch();
    return 0;
}

void Insert(int x){ //Inserts the data in the head rather at the back or at a specific position
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); //same with struct Node* temp = new Node(); if you are using cpp//Creates a new node
    temp -> data = x;  //Same with the (*temp).data
    temp -> next = head;  //Points to the next even if Null or occuppied 
    head = temp;
}

void InsertSpecific(int data, int position) {
    if (position <= 0) {  //Checks if the position is valid
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {  //If the data to be inserted will be placed at the head or at the first node
        Insert(data);
        return;
    }
    
    // If position is not existent in the current linked list for example there are only 3 numbers in the list and you want to insert at position 5 it is not possible
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    //Creates a New Node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}


void DeleteAtPosition(int position){
    struct Node* temp = head; //initialize a pointer to the head of the list

    if(position == 1){  //if the first node is to be deleted
        head = temp -> next; //update head to the next node
        free(temp); //free the memory of the deleted node
        return;
    }

    for(int i = 0; i < position - 2; i++){ //traverse the list to get to the node before the one to be deleted
        temp = temp -> next;
    }
    struct Node* temp1 = temp -> next; //create a pointer to the node to be deleted
    temp -> next = temp1 -> next; //update the next pointer of the previous node to skip over the deleted node
    free(temp1); //free the memory of the deleted node
}


void Reverse1(){  //Iterative Approach
    /*                                                                                                       [address]
    Note: Reversing linked list doesn't mean that we will reposition the elements in the link like this [value][link to the next address]
   [-> 250]  [100]        [250]       [130]       [325]
    head -> [4][250] -> [5][130] -> [1][325] -> [3][0] -> NULL
    to                                                                   THIS IS WRONG!!!!!
   [-> 250]  [100]       [250]       [130]       [325]
    head -> [3][250] -> [1][130] -> [5][325] -> [4][0] -> NULL

    but rather THIS

   [-> 250]   [100]       [250]       [130]       [325]
    head -> [4][250] -> [5][130] -> [1][325] -> [3][0] -> NULL
    to                                                                   THIS IS CORRECT!!!!!
             [100]        [250]       [130]       [325]   [ 325 <-]
    NULL <- [4][0] <- [5][130] <- [1][325] <- [3][130] <- head
    
    */
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL){
        next = current->next;  //The next variable is local but the (->next) is the global variable and the next local variable is getting the address of the next
        current -> next = prev;  //The current -> next will now have the address of the prev variable
        prev = current; //Now the prev will be have the current
        current = next;  //The current will have the address of the next
    }
    head = prev;  //After the loop is done, the head will have the prev address
}

void Reverse2(struct Node* p) {  //Recursion Approach
//Read the Note on Reverse1 function to understand what is the correct reversing a list
    if (p == NULL) {
        return;
    }
    Reverse2(p->next);  //Calls the function again 
    printf("%d ", p->data);  //Prints the data 
}

void Print(){

    struct Node* temp = head;
    printf("List is: ");
    printf("\n");
    printf("{");
    if (temp == NULL){
        printf("EMPTY");
        printf("}");
    }
    else{
        while(temp != NULL){  //Traverses the list until it reaches the Node with NULL
            printf("%d%s", temp -> data, temp -> next != NULL ? ", " : "");  //Prints the value of the current node
            temp = temp -> next;  //To the next Node
    }
    printf("}");
    }
    printf("\n");
}
