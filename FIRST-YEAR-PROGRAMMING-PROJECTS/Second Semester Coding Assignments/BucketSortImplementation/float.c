#include <stdio.h>
#include <stdlib.h>

struct Node {
    float value;
    struct Node* next;
};

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%.2f ", node->value);
        node = node->next;
    }
}

void insert(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void bucketSort(float arr[], int n) {
    // Create bucket list
    struct Node* bucketList[n];

    // Initialize bucket lists
    for (int i = 0; i < n; i++) {
        bucketList[i] = NULL;
    }

    // Add elements to the appropriate bucket
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        insert(&bucketList[index], arr[i]);
    }

    // Sort each bucket list using insertion sort
    for (int i = 0; i < n; i++) {
        struct Node* curr = bucketList[i];
        while (curr != NULL) {
            float value = curr->value;
            int j = i - 1;
            while (j >= 0 && bucketList[j]->value > value) {
                bucketList[j + 1] = bucketList[j];
                j--;
            }
            bucketList[j + 1]->value = value;
            curr = curr->next;
        }
    }

    // Concatenate all the bucket lists into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = bucketList[i];
        while (curr != NULL) {
            arr[index++] = curr->value;
            curr = curr->next;
        }
    }
}

int main() {
    float arr[] = {0.23, 0.32, 0.43, 0.67, 0.21, 0.55, 0.99, 0.01};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printList(arr);
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    printList(arr);
    printf("\n");

    return 0;
}

