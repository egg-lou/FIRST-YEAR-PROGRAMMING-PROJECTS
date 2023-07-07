/*
Author: Rafael Louie V. Miguel
Year & Section: BSIT 1 - 4

Problem:
Define a structure of  student having data members name, address, grade in C language, and grade in Information Management. 
Take data for n students in an array dynamically and find the total grade obtained.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_LENGTH_ADDRESS 200

struct Student_Name {
    char Fname[80];
    char Lname[80];
};

struct student_grades {
    float CLang;
    float InfoMan;
    float GPA;
};

struct Student {
    struct Student_Name name;
    char *address;
    int age;
    struct student_grades grade;
}*std;

void allocateMemory(int numberOfStudents);
void getRecords(int numberOfStudents);
void printRecords(int numberOfStudents);

int main(){

    char try;
    int numberOfStudents;

    do{
        printf("How many student records would you like to enter? \n");
        printf("Response: ");
        scanf("%d", &numberOfStudents);

        allocateMemory(numberOfStudents);

        getRecords(numberOfStudents);

        printRecords(numberOfStudents);

        printf("---------------------------------------------------\n");

        printf("Try Again? \n");
        printf("Response: ");
        scanf(" %c", &try);

    }while(try == 'Y' || try == 'y');
    return 0;
}

void allocateMemory(int numberOfStudents) {
    std = (struct Student *)malloc(numberOfStudents * sizeof(struct Student));
}

void getRecords(int numberOfEmployees){

    for(int i = 0; i < numberOfEmployees; i++){
        printf("Student #%d\n", i + 1);
        printf("Enter the First Name of student: ");
        scanf("%s", (std + i)->name.Fname);

        while (getchar() != '\n');

        printf("Enter the Last Name of student: ");
        scanf("%s", (std + i)->name.Lname);

        while (getchar() != '\n');

        printf("Enter the Address of student: ");
        (std + i)->address = (char* )malloc(MAX_LENGTH_ADDRESS * sizeof(char));
        gets((std + i)->address);

        printf("Enter the age of student: ");
        scanf("%d", &(std + i)->age);
        
        printf("Enter the grades of the student for the following Subjects: \n");
        printf("C Language: ");
        scanf("%f", &(std + i)->grade.CLang);
        printf("Information Management: ");
        scanf("%f", &(std + i)->grade.InfoMan);

        (std + i)->grade.GPA = ((std + i)->grade.CLang + (std + i)->grade.InfoMan) / 2; 
    }
}

void printRecords(int numberOfStudents){
    system("cls"); 

    for(int i = 0; i < numberOfStudents; i++){
        printf("Student: %d\n", i + 1);
        printf("Name: %s %s\n", (std + i)->name.Fname, (std + i)->name.Lname);
        printf("Address: %s\n", (std + i)->address);
        printf("Age: %d\n", (std + i)->age);
        printf("C Language Grade: %.2f\n",(std + i)->grade.CLang);
        printf("Information Management Grade: %.2f\n",(std + i)->grade.InfoMan);
        printf("Total Grade: %.2f\n", (std + i)->grade.GPA);
        printf("\n");
    }
}