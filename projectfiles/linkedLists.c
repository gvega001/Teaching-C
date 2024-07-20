#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;            // Data stored in the node
    struct Node* next;   // Pointer to the next node in the list
};

// Function to print the elements of the linked list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data); // Print the data of the current node
        n = n->next;            // Move to the next node
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* tmp;  // Temporary pointer to hold the node to be freed

    while (head != NULL) {
        tmp = head;    // Store the current head in tmp
        head = head->next; // Move to the next node
        free(tmp);     // Free the memory of the current node
    }
}

int main() {
    struct Node* head = NULL;    // Pointer to the head of the linked list
    struct Node* second = NULL;  // Pointer to the second node
    struct Node* third = NULL;   // Pointer to the third node

    // Allocate memory for 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the first node and link it to the second node
    head->data = 1;
    head->next = second;

    // Assign data to the second node and link it to the third node
    second->data = 2;
    second->next = third;

    // Assign data to the third node and terminate the list
    third->data = 3;
    third->next = NULL;

    // Print the linked list
    printList(head);
    printf("\n");

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
// Output:
// 1 2 3
