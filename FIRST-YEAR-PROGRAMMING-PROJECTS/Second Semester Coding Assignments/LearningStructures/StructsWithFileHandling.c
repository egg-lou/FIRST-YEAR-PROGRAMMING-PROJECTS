#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGETH 100

//Inner Struct Student Grades
struct student_grades {
    float CPROG;
    float DS1;
    float GPA;
};

//Main Struct for collecting student records
struct student_record {
    char stud_id[10];
    char *stud_name;
    struct student_grades grade;
}*std;

void allocateMemory(int numberOfStudents); //Memory Allocation for an array of structs
void getRecords(int numberOfStudents); //Collection of Data
void swapper(struct student_record *std1, struct student_record *std2); //Swaps the contents of one struct to another
void printRecords(int numberOfStudents); //Prints the array of structs
void saveRecordsToFile(int numberOfStudents); //Saves the contents of each struct to a txt file

int main() {
    int NumOfStudents;

    printf("\n| STUDENT RECORDS |\n");

    printf("How Many Students would you like to record: \n");
    printf("Response: ");
    scanf("%d", &NumOfStudents);

    allocateMemory(NumOfStudents);

    getRecords(NumOfStudents);

    printRecords(NumOfStudents);

    saveRecordsToFile(NumOfStudents);

    return 0;
}

// Function to allocate memory for the student records
void allocateMemory(int numberOfStudents) {
    std = (struct student_record *)malloc(numberOfStudents * sizeof(struct student_record));
}

// Function to get student records from the user
void getRecords(int numberOfStudents) {
    for (int i = 0; i < numberOfStudents; i++) {
        float CPROG = 0.00;
        float DS1 = 0.00;

        printf("Student: %d\n", i + 1);
        printf("Enter the Student's ID Number: ");
        scanf("%s", (std + i)->stud_id);

        (std + i)->stud_name = (char *)malloc(MAX_NAME_LENGETH * sizeof(char));

        // Clearing input buffer
        while (getchar() != '\n');

        printf("Enter name of Student: ");
        fgets((std + i)->stud_name, MAX_NAME_LENGETH, stdin);

        // Removing trailing newline character
        (std + i)->stud_name[strcspn((std + i)->stud_name, "\n")] = '\0';

        printf("Enter the grades of the student for the following Subjects: \n");
        printf("CPROG: ");
        scanf("%f", &(std + i)->grade.CPROG);
        printf("DS1: ");
        scanf("%f", &(std + i)->grade.DS1);

        CPROG = (std + i)->grade.CPROG;
        DS1 = (std + i)->grade.DS1;

        (std + i)->grade.GPA = (CPROG + DS1) / 2;
    }
}

// Function to swap two student records
void swapper(struct student_record *std1, struct student_record *std2) {
    struct student_record temp = *std1;
    *std1 = *std2;
    *std2 = temp;
}

// Function to sort the student records based on GPA
void sorter(int numberOfStudents) {
    for (int i = 0; i < numberOfStudents; i++) {
        for (int j = i + 1; j < numberOfStudents; j++) {
            if ((std + i)->grade.GPA > (std + j)->grade.GPA) {
                swapper((std + i), (std + j));
            }
        }
    }
}

// Function to print the student records
void printRecords(int numberOfStudents) {
    sorter(numberOfStudents);

    printf("-----------------------------------------------------------------------------------\n");
    printf("| No.|  %-5s  |  %-21s |  %-12s |  %-4s |  %-4s |\n", "ID", "NAME", "CPROG Grade", "DS1 Grade", "GPA Grade");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < numberOfStudents; i++) {
        printf("| %2d |  %s |  %-21s |  %-12.2f |  %-9.2f |  %-9.2f |\n", i + 1, (std + i)->stud_id, (std + i)->stud_name, (std + i)->grade.CPROG, (std + i)->grade.DS1, (std + i)->grade.GPA);

    printf("-----------------------------------------------------------------------------------\n");
    }
}

// Function to save the student records to a file
void saveRecordsToFile(int numberOfStudents) {
    FILE *file = fopen("student_records.txt", "w");
    //w is to create a new file
    //a is to append data to an existing file but the file must exist first

    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < numberOfStudents; i++) {
        fprintf(file, "ID Number: %s\n", (std + i)->stud_id);
        fprintf(file, "Name: %s\n", (std + i)->stud_name);
        fprintf(file, "CPROG Grade: %.2f\n", (std + i)->grade.CPROG);
        fprintf(file, "DS1 Grade: %.2f\n", (std + i)->grade.DS1);
        fprintf(file, "GPA: %.2f\n", (std + i)->grade.GPA);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Records saved to student_records.txt\n");
}