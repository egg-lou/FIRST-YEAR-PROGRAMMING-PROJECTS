/*
About: Implementation of the BUCKET Sort Algorithm in C and a combination of the SELECTION Sort Algorithm
Author: GROUP 4
CREATION DATE: 04/15/2023
VERSION: 2.5
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NUM_BUCKETS 6 // Define the number of buckets for Bucket Sort

// Function to determine data type to be sorted based on user input
int TypeSort(int response);

// Function to perform Bucket Sort on an array of floats
void BucketSort(float array[], int size);

// Function to print an array of floats
void PrintArray(float array[], int size);

// Function to print a border for output formatting
void PrintBorder();

int main() {
    float grades [100] = {85, 93, 76, 82, 91, 
                         87, 76, 89, 78, 84, 
                         92, 77, 88, 81, 86, 
                         85, 79, 90, 98, 92, 
                         87, 84, 89, 77, 95, 
                         75, 83, 72, 93, 96}; // Array to store elements to be sorted
    int size = 30;


    printf("\nWelcome to the Grades Sorter");
    PrintBorder();
    printf("Here are the grades that you want to sort: \n");
    PrintArray(grades, size);

    PrintBorder();
    BucketSort(grades, size);
    PrintBorder();

    printf("\nSorted Grades: \n");
    PrintArray(grades, size);

    printf("\n");
    printf("\nThank you for using the Program!");
    getch();
    return 0;
}

void BucketSort(float array[], int size) {
    // Find minimum and maximum values
    float min_val = array[0], max_val = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min_val) {
            min_val = array[i];
        } else if (array[i] > max_val) {
            max_val = array[i];
        }
    }

    // Calculate range of each bucket
    float bucket_range = (max_val - min_val) / NUM_BUCKETS;
    printf("\nBucket Range: %.1f \n", bucket_range);

    // Create the buckets
    float buckets[NUM_BUCKETS][size];

    // Initialize the bucket sizes
    int bucket_sizes[NUM_BUCKETS] = {0};

    // Initialize the buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = (array[i] - min_val) / bucket_range;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = array[i];
    }
    
    // Prompt the user for ascending or descending order
    int response = 0;
    response = TypeSort(response);

    int index = (response == 1) ? 0 : size - 1;
    //Sort the buckets using SELECTION sort
    for (int i = 0; i < NUM_BUCKETS; i++)
    {
        for (int j = 0; j < bucket_sizes[i]; j++){
            int min = j;
            for (int k = j + 1; k < bucket_sizes[i]; k++)
                if (buckets[i][min] > buckets[i][k]) 
                    min = k;

            float temp = buckets[i][j];
            buckets[i][j] = buckets[i][min];
            buckets[i][min] = temp;
            array[(response == 1 ? index++ : index--)] = buckets[i][j];
        }
    }
            printf("\n");
            //Print the elements inside each bucket
            for (int i = 0; i < NUM_BUCKETS; i++) {
            printf("Bucket %d Range: [%.1f, %.1f] - Elements: ", i + 1, min_val + i * bucket_range, min_val + (i + 1) * bucket_range);
            for (int j = 0; j < bucket_sizes[i]; j++) {
                printf("%g ", buckets[i][j]);
        }
        printf("\n");
    }
}

int TypeSort(int response){ //Asks the user wheter they want it to be sorted in asc or dsc
    do{
        printf("\n[1] Ascending or [2] Descending");
        printf("\nResponse: ");
        scanf("%d", &response);
    } while (response != 1 && response != 2);

    return response;
}

void PrintArray(float array[], int size){ //Prints the array
    printf("{\n");
    for(int i = 0; i < size; i++){
        printf("%g%s%s", array[i], (i == size - 1) ? "" : ", " , (((i + 1) % 10 == 0) ? "\n": ""));
    }
    printf("}");
}

void PrintBorder(){ //Prints the border
    printf("\n======================================================\n");
}


/*
This is a C program that implements the Bucket Sort algorithm to sort an array of either characters or floats/integers based on user input. 
The program prompts the user to choose the data type to be sorted and then the size and elements of the array. 
The program then sorts the array using the Bucket Sort algorithm and prints the array before and after sorting. 
The program then prompts the user whether to sort again or exit the program.



The program includes the following functions:

1. int TypeSort(int response): This function prompts the user for input to determine the order (ascending or descending) in which the array should be sorted. 
It returns an integer value that is used in the main function to determine the starting index of the sorted array.

2. oid BucketSort(float array[], int size): This function takes an array of floats and its size as input, finds the minimum and maximum values of the array, calculates the range of each bucket, 
creates the buckets, initializes the bucket sizes and the buckets, sorts the buckets using the Selection Sort algorithm, and then combines the sorted buckets into the final sorted array.

3. oid PrintArray(float array[], int size): This function takes an array of floats and its size as input and prints the array.
4. void PrintBorder(): This function prints a border for output formatting.


The program uses the #define directive to define the number of buckets for the Bucket Sort algorithm as NUM_BUCKETS. The program also includes the following header files:

stdio.h: This header file includes standard input/output functions.
stdlib.h: This header file includes standard library functions.
conio.h: This header file includes console input/output functions.


Important Parts:

Our BucketSort Algorithm Relies on the SELECTION SORT ALGORITHM to sort the elements inside the buckets.
Also uses a 2 dimensional array to store the elements inside the buckets 

Example:
          1        2 
Bucket [index][elements]

The number of buckets is fixed to 10 (10 NUM_BUCKETS) so we have 10 rows 
                           column 1  | column 2 | next columns
Row 1 - Bucket 1 [range]= 1st element, 2nd element and so on...
Row 2 - Bucket 2 [range]= 1st element, 2nd element and so on...
Row 3 - Bucket 3 [range]= 1st element, 2nd element and so on...
Row 4 - Bucket 4 [range]= 1st element, 2nd element and so on...
Row 5 - Bucket 5 [range]= 1st element, 2nd element and so on...
Row 6 - Bucket 6 [range]= 1st element, 2nd element and so on...
Row 7 - Bucket 7 [range]= 1st element, 2nd element and so on...
Row 8 - Bucket 8 [range]= 1st element, 2nd element and so on...
Row 9 - Bucket 9 [range]= 1st element, 2nd element and so on...
Row 10 - Bucket 10 [range]= 1st element, 2nd element and so on...

The range of each bucket depends on 
 float bucket_range = (max_val - min_val + 1.0) / NUM_BUCKETS;
*/