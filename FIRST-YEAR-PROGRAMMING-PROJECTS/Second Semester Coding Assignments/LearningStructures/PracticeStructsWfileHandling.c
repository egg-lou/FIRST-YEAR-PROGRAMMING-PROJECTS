#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGETH 100

struct student_grades{
    float CPROG;
    float DS1;
    float GPA;
};

struct student_record{
    char stud_id[10];
    char *stud_name;
    struct student_grades grade;
}std[10];

void getRecords(int numberOfStudents){
    for(int i = 0; i < numberOfStudents; i++){
        float CPROG = 0.00;
        float DS1 = 0.00;

        printf("Enter the Student's ID Number: ");
        scanf("%s", &std->stud_id);
        std[i].stud_name = (char* )malloc(MAX_NAME_LENGETH * sizeof(char));

        while (getchar() != '\n');

        printf("Enter name of Student %d: ", i + 1);
        fgets(std[i].stud_name, MAX_NAME_LENGETH, stdin);
        std[i].stud_name[strcspn(std[i].stud_name, "\n")] = '\0';
        printf("Enter the grades of the student for the following Subjects: \n");
        printf("CPROG: ");
        scanf("%f", &std[i].grade.CPROG);
        printf("DS1: ");
        scanf("%f", &std[i].grade.DS1);

        CPROG = std[i].grade.CPROG;
        DS1 = std[i].grade.DS1;

        std[i].grade.GPA = (CPROG + DS1) / 2;
    }
}

void swapper(struct student_record *std1, struct student_record *std2){
    struct student_record temp = *std1;
    *std1 = *std2;
    *std2 = temp;
}

void sorter(int numberOfStudents){
    for(int i = 0; i < numberOfStudents; i++){
        for(int j = i + 1; j < numberOfStudents; j++){
            if(std[i].grade.GPA > std[j].grade.GPA){
                swapper(&std[i], &std[j]);
            }
        }
    }
}

void printRecords(int numberOfStudents) {
    sorter(numberOfStudents);
    printf("-----------------------------------------------------------------------------------\n");
    printf("| No. |  %-5s |  %-21s |  %-12s |  %-4s |  %-4s |\n", "ID", "NAME", "CPROG Grade", "DS1 Grade", "GPA Grade");
    printf("-----------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < numberOfStudents; i++){
        printf("| %2d |  %s |  %-21s |  %-12.2f |  %-9.2f |  %-9.2f |\n", i+1, std[i].stud_id, std[i].stud_name, std[i].grade.CPROG, std[i].grade.DS1, std[i].grade.GPA);
    }
    
    printf("-----------------------------------------------------------------------------------\n");
}


void saveRecordsToFile(int numberOfStudents) {
    FILE *file = fopen("student_records.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < numberOfStudents; i++) {
        fprintf(file, "ID Number: %s\n", std[i].stud_id);
        fprintf(file, "Name: %s\n", std[i].stud_name);
        fprintf(file, "CPROG Grade: %.2f\n", std[i].grade.CPROG);
        fprintf(file, "DS1 Grade: %.2f\n", std[i].grade.DS1);
        fprintf(file, "GPA: %.2f\n", std[i].grade.GPA);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Records saved to student_records.txt\n");
}

int main(){

    int NumOfStudents;

    printf("| STUDENT RECORDS |\n");

    printf("How Many Students would you like to record: \n");
    printf("Response: ");
    scanf("%d", &NumOfStudents);

    getRecords(NumOfStudents);

    printRecords(NumOfStudents);

    saveRecordsToFile(NumOfStudents);

    return 0;
}