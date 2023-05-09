/*
About: Implementation of the BUCKET Sort Algorithm in C and a combination of the SELECTION Sort Algorithm
Author: GROUP 4
CREATION DATE: 04/15/2023
VERSION: 2.5
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// Function to determine data type to be sorted based on user input
int TypeSort(int response);

// Function to perform Bucket Sort on an array of floats
void BucketSort(float array[], int size);

// Function to print an array of floats
void PrintArray(float array[], int size);

// Function to print a border for output formatting
void PrintBorder();

int main() {
    float array[1000]; // Array to store elements to be sorted
    int size, i, ascii, try, userChoice, try_counter = 0;

    do {
        // Prompt user for input
        do {
            if (try_counter >= 1) {
                system("cls"); // Clear screen for multiple sorting attempts
            }
            PrintBorder();
            printf("\nWelcome to Group 4's Bucket Sorting Algorithm");
            printf("\nSELECT THE NUMBER OF DATA TYPE YOU WANT TO SORT:\n");
            printf("[1] : CHARACTER\n[2] : FLOAT OR INTEGER\n");
            printf("\nResponse: ");
            scanf("%d", &userChoice);
        } while (userChoice != 1 && userChoice != 2);

        do {
            PrintBorder();
            printf("\nEnter the size of array: ");
            scanf("%d", &size);
        } while (size <= 1);

        float array[size]; // Array to store elements to be sorted

        // Sort characters
        if (userChoice == 1) {
            char ch[size]; // Array to store characters to be sorted

            PrintBorder();
            printf("\nEnter the %d elements to be sorted:\n", size);
            for (int i = 0; i < size; i++) {
                scanf(" %c", &ch[i]); // Read input characters from user
                ascii = ch[i];
                array[i] = ascii; // Convert characters to ASCII values and store in float array
            }

            // Print the array before sorting
            PrintBorder();
            printf("\nThe array of elements before sorting: \n");
            for (int i = 0; i < size; i++) {
                printf("%c ", ch[i]);
            }
            printf("\n");

            // Sort the array using Bucket Sort
            PrintBorder();
            BucketSort(array, size);

            // Convert the sorted array back to characters and print
            PrintBorder();
            printf("\nThe array of elements after sorting: \n");
            for (int i = 0; i < size; i++) {
                ch[i] = array[i];
                printf("%c ", ch[i]);
            }
            printf("\n");
        }
        // Sort floats or integers
        else if (userChoice == 2) {
            PrintBorder();
            printf("\nEnter the %d elements to be sorted:\n", size);
            for (int i = 0; i < size; i++) {
                scanf("%g", &array[i]); // Read input floats/integers from user
            }

            // Print the array before sorting
            PrintBorder();
            printf("\nThe array of elements before sorting: \n");
            PrintArray(array, size);

            // Sort the array using Bucket Sort
            PrintBorder();
            BucketSort(array, size);

            // Print the sorted array
            PrintBorder();
            printf("\nThe array of elements after sorting: \n");
            PrintArray(array, size);
        }
        // Prompt user whether to sort again

    PrintBorder();
    printf("\nDo you want to sort again? [1] for Yes & [0] for No\n");
    printf("Response: ");
    scanf("%d", &try);
    if(try == 1)
        try_counter++; // Increment try_counter if user wants to sort again

    }while (try == 1);

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
    float bucket_range = (max_val - min_val + 1.0) / size + 1;
    printf("\nBucket Range: %.1f", bucket_range);

    //Calculate the number of buckets to be created
    int NUM_BUCKETS = (max_val - min_val) / bucket_range + 1;
    printf("\nNumber of buckets created: %d", NUM_BUCKETS);

    // Create the buckets
    float** buckets = (float**)malloc(NUM_BUCKETS * sizeof(float*));  // Allocate memory for an array of bucket pointers
    for (int i = 0; i < NUM_BUCKETS; i++) {  // For each bucket index
        buckets[i] = (float*)malloc(size * sizeof(float));  // Allocate memory for a bucket that can hold all elements
    }

    // Initialize the bucket sizes
    // Allocate memory for an array of size NUM_BUCKETS and initialize all elements to 0
    // This array will be used to keep track of the size of each bucket during the sorting process
    int *bucket_sizes = (int *)calloc(NUM_BUCKETS, sizeof(int));
    // The calloc function initializes all elements of the array to 0

    // The 2D array of buckets will be used to store the elements of the input array during the sorting process.
    // The size of each bucket is not known in advance, so dynamic memory allocation is used to create the buckets.

    // The outer loop of the first block of code iterates over each row of the 2D array,
    // creating a new row by allocating memory for it using malloc.
    // The inner loop then initializes each element of the row to 0 using the memset function.

    // The second block of code creates an array of ints, with NUM_BUCKETS elements, and initializes all elements to 0 using calloc.
    // This array will be used to keep track of the size of each bucket during the sorting process.
    // The calloc function initializes all elements of the array to 0.


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
    for (int i = 0; i < size; i++) {
        printf("%g ", array[i]);   
    }
    printf("\n");
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

2. void BucketSort(float array[], int size): This function takes an array of floats and its size as input, finds the minimum and maximum values of the array, calculates the range of each bucket, 
creates the buckets, initializes the bucket sizes and the buckets, sorts the buckets using the Selection Sort algorithm, and then combines the sorted buckets into the final sorted array.

3. void PrintArray(float array[], int size): This function takes an array of floats and its size as input and prints the array.
4. void PrintBorder(): This function prints a border for output formatting.


The program uses the #define directive to define the number of buckets for the Bucket Sort algorithm as NUM_BUCKETS. The program also includes the following header files:

stdio.h: This header file includes standard input/output functions.
stdlib.h: This header file includes standard library functions.
conio.h: This header file includes console input/output functions.


Important Parts:

Our BucketSort Algorithm Relies on the SELECTION SORT ALGORITHM to sort the elements inside the buckets.
Also uses a 2 dimensional array to store the elements inside the buckets 

Example:
                 1       2 
Bucket Number [index][elements]

The number of buckets now depends on this formula int NUM_BUCKETS = (max_val - min_val) / bucket_range + 1 
it is important to get the bucket range for the bucket/s 

Note: Why use dynamic memory allocation? since we do not still know the number of buckets in compile time or ahead of time
so with the use of dynamic memory allocation we can know the number of buckets at run time and we get the number of buckets
during the program is running rather than setting a specified number of buckets. Now this code will have a varying number
of buckets rather than a fixed number of buckets. 


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