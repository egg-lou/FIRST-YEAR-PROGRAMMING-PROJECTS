#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {  // Define a Node struct for the linked list implementation of buckets.
    float data;        // The data stored in the Node is a float number.
    struct Node* next; // The next pointer points to the next Node in the linked list.
} Node;

void insert(Node** head_ref, float value) {  // Define a function to insert a new Node with a given value at the head of a linked list.
    Node* new_node = (Node*) malloc(sizeof(Node));  // Allocate memory for the new Node using malloc().
    new_node->data = value;  // Set the data of the new Node to the given value.
    new_node->next = (*head_ref);  // Set the next pointer of the new Node to point to the current head of the linked list.
    (*head_ref) = new_node;  // Set the head pointer of the linked list to point to the new Node.
}

float remove_node(Node** head_ref) {  // Define a function to remove the head Node from a linked list and return its data.
    if (*head_ref == NULL) {  // Check if the linked list is empty.
        return 0;  // If the linked list is empty, return 0.
    }
    float value = (*head_ref)->data;  // Store the data of the head Node in a variable.
    (*head_ref) = (*head_ref)->next;  // Set the head pointer of the linked list to point to the next Node.
    return value;  // Return the data of the removed head Node.
}

void bucketSort(float array[], int n) {  // Define the main bucket sort function that takes an array of floats and its length as input.
    int i, j;  // Declare two index variables.
    Node* buckets[n];  // Declare an array of n linked lists, where each linked list represents a bucket.
    for (i = 0; i < n; i++) {  // Initialize each bucket to be empty.
        buckets[i] = NULL;
    }
    for (i = 0; i < n; i++) {  // Iterate over each element in the input array.
        int bucket_index = (int)(n * array[i]);  // Calculate the index of the bucket that the current element belongs to.
        insert(&buckets[bucket_index], array[i]);  // Insert the current element into the appropriate bucket.
    }
    for (i = 0, j = 0; i < n; i++) {  // Iterate over each bucket in order.
        while (buckets[i] != NULL) {  // While the current bucket is not empty, remove the elements from the bucket and insert them back into the input array.
            array[j++] = remove_node(&buckets[i]);
        }
    }
}

int main() {
    float array[] = {0.7, 0.2, 0.9, 0.3, 0.6, 0.1};
    int n = sizeof(array)/sizeof(array[0]);
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%g ", array[i]);
    }

    bucketSort(array, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%g ", array[i]);
    }
    printf("\n");
    return 0;
}
