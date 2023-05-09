#include <stdio.h>
#include <stdlib.h>

int TypeSort(int response);
float MaxElement(float array[], int size);
void BucketSort(float array[], int size);
void PrintArray(float array[], int size);
void PrintBorder();

// Main function
int main(void) 
{
    // Declare variables
    int size = 0; // Size of the array
    int ascii, try, userChoice = 0; // Variables for storing user input

    // Loop to allow sorting multiple times
    do {
        // Prompt user for input
        do{
            PrintBorder();
            printf("\nSELECT THE NUMBER OF DATA TYPE YOU WANT TO SORT:\n");
            printf("[1] : CHARACTER\n[2] : FLOAT OR INTEGER\n");
            printf("\nResponse: ");
            scanf("%d", &userChoice);
        } while (userChoice != 1 && userChoice != 2);

        do{
            PrintBorder();
            printf("\nEnter the size of array: ");   
            scanf("%d", &size);
        } while (size <= 1);

        float array[size]; // Array to store elements to be sorted

        // Sort characters
        if (userChoice == 1) {
            char ch[size]; // Array to store characters to be sorted

            PrintBorder();
            printf("\nEnter the %d elements to be sorted:\n",size); 
            for (int i = 0; i < size; i++) {
                scanf(" %c", &ch[i]);
                ascii = ch[i];
                array[i] = ascii;
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
            printf("\nEnter the %d elements to be sorted:\n",size); 
            for (int i = 0; i < size; i++) {
                scanf("%g", &array[i]); 
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

    } while (try == 1); 

    return 0;
}

void BucketSort(float array[], int size) 
{  
    // Find the maximum element in the array
    float max = MaxElement(array, size);
    // Create an array of buckets with size equal to the maximum element in the array
    int bucket_size = (int)(max * 10) + 1; // multiply by 10 to maintain precision
    float bucket[bucket_size];

    // Initialize all elements of the bucket array to zero
    // O(n) time complexity
    for (int i = 0; i < bucket_size; i++)  
        bucket[i] = 0.0f;  
    int counter = 0;
    for(int i = 0; i < bucket_size; i++){
        counter++;
    }
    printf("\nNumber of Buckets Created: %d", counter);
 
    // COUNTING STAGE:
    // Traverse through the array and increment the corresponding bucket element by 1
    // O(n) time complexity
    for (int i = 0; i < size; i++)
        bucket[(int)(array[i] * 10)]++;

    // Prompt user to select ascending or descending order
    int response = 0;
    response = TypeSort(response);

    // SORTING STAGE:
    // Traverse through the bucket array and copy the elements into the original array
    // O(n^2) time complexity
    if (response == 1) { // ascending
        int index = 0;
        for (int i = 0; i < bucket_size; i++) { 
            for (int j = 0; j < bucket[i]; j++) {
                array[index++] = (float)i / 10; // divide by 10 to restore original value 
            }
        }
    } 
    else if (response == 2) { // descending
        int index = 0;
        for (int i = bucket_size - 1; i >= 0; i--) {
            for (int j = 0; j < bucket[i]; j++) {
                array[index++] = (float)i / 10;
            }
        }
    }
}

float MaxElement(float array[], int size)
{  
    float max = array[0];  
    for (int i = 1; i < size; i++)
        max = (array[i] > max) ? array[i] : max;
			
    return max; 
}

int TypeSort(int response){
    do{
        printf("\n[1] Ascending or [2] Descending");
        printf("\nResponse: ");
        scanf("%d", &response);
    } while (response != 1 && response != 2);

    return response;
}

void PrintArray(float array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%g ", array[i]);   
    }
    printf("\n");
}

void PrintBorder(){
    printf("\n======================================================\n");
}


/*
The code is a program that implements bucket sort to sort an array of characters or float/integers in ascending or descending order. 
Bucket sort is a sorting algorithm that works by dividing an array into a number of "buckets" that hold elements that belong to the same range. 
It is a linear-time sorting algorithm and is often used for distributed sorting.

This code relies the number of buckets based on the max value in the array. In simple terms if you the max element is 10 it will create 10 + 1 buckets
and the larger the max value the more buckets it will create.

Each bucket doesn't have a range it is exact 

For Example: 

array [6] = {5, 1, 3, 2, 6, 3}

size = 5 
max value = 6

Creates 6 buckets 

Bucket 0 = 0 (for element/s with value of 0)
Bucket 1 = 0 (for element/s with value of 1)
Bucket 2 = 0 (for element/s with value of 2)
Bucket 3 = 0 (for element/s with value of 3)
Bucket 4 = 0 (for element/s with value of 4)
Bucket 5 = 0 (for element/s with value of 5)
Bucket 6 = 0 (for element/s with value of 6)


Now increment the bucket by 1 if there is an element that has the same value of the bucket
{5, 1, 3, 2, 6, 3}
1st element = 5 goes to bucket 5
2nd element = 1 goes to bucket 1
3rd element = 3 goes to bucket 3
4th element = 2 goes to bucket 2
5th element = 6 goes to bucket 6
6th element = 3 goes to bucket 3


Bucket 0 = 0
Bucket 1 = 1
Bucket 2 = 1
Bucket 3 = 2
Bucket 4 = 0
Bucket 5 = 1
Bucket 6 = 1

Note: Bucket is equal to 0 means that it doesn't have any elements

And each of the buckets are now gonna give or output the elements that they have

Bucket 0 | Bucket 1 | Bucket 2 | Bucket 3 | Bucket 4 | Bucket 5 | Bucket 6 
              1           2        3, 3                   5          6

Note: If the user wants to sort it in descending order start with the last bucket which in this case is Bucket 6

Final Sorted Array in Ascending Order: {1, 2, 3, 3, 5, 6}

*/