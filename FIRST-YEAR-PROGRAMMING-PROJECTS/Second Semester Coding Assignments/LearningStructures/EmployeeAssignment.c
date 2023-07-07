// Define a structure of  employee having data members name, address, age and salary.  Take data for n employee in an array dynamically and find the average salary.


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_LENGTH_ADDRESS 200

struct Employee_Name {
    char Fname[80];
    char Lname[80];
};

struct Employee {
    struct Employee_Name name;
    char *address;
    int age;
    float salary;
}*emp;

void allocateMemory(int numberOfEmployees);
void getRecords(int numberOfEmployees);
void printRecords(int numberOfEmployees);
float averageSalary(int numberOfEmployees);

int main(){

    char try;
    int numberOfEmployees;

    do{
        printf("How many employee records would you like to enter? \n");
        printf("Response: ");
        scanf("%d", &numberOfEmployees);

        allocateMemory(numberOfEmployees);

        getRecords(numberOfEmployees);

        printRecords(numberOfEmployees);

        printf("Average Salary: %.2f Pesos\n", averageSalary(numberOfEmployees));

        printf("---------------------------------------------------\n");

        printf("Try Again? \n");
        printf("Response: ");
        scanf(" %c", &try);

    }while(try == 'Y' || try == 'y');


    return 0;
}

void allocateMemory(int numberOfEmployees) {
    emp = (struct Employee *)malloc(numberOfEmployees * sizeof(struct Employee));
}

void getRecords(int numberOfEmployees){

    for(int i = 0; i < numberOfEmployees; i++){
        printf("Employee #%d\n", i + 1);
        printf("Enter the First Name of employee: ");
        scanf("%s", (emp + i)->name.Fname);

        while (getchar() != '\n');

        printf("Enter the Last Name of employee: ");
        scanf("%s", (emp + i)->name.Lname);

        while (getchar() != '\n');

        printf("Enter the Address of employee: ");
        (emp + i)->address = (char* )malloc(MAX_LENGTH_ADDRESS * sizeof(char));
        gets((emp+i)->address);

        printf("Enter the age of employee: ");
        scanf("%d", &(emp + i)->age);
        
        printf("Enter the salary of employee: ");
        scanf("%f", &(emp + i)->salary);
    }
}

void printRecords(int numberOfEmployees){
    system("cls"); 

    for(int i = 0; i < numberOfEmployees; i++){
        printf("Employee: %d\n", i + 1);
        printf("Name: %s %s\n", (emp + i)->name.Fname, (emp + i)->name.Lname);
        printf("Address: %s\n", (emp + i)->address);
        printf("Age: %d\n", (emp + i)->age);
        printf("Salary: %.2f\n", (emp + i)->salary);
        printf("\n");
    }
}

float averageSalary(int numberOfEmployees){
    float sumOfSalaries = 0;

    for(int i =0 ; i < numberOfEmployees; i++){
        sumOfSalaries += ((emp + i )->salary );
    }
    return sumOfSalaries / numberOfEmployees;
}