#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // Define a constant for the maximum queue size

// Define the structure for a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* arr;
};

// Function to create a queue with a given capacity
// It initializes the size of the queue as 0
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; // Initialize front and size
    queue->rear = capacity - 1;     // This is important, see the enqueue function
    queue->arr = (int*)malloc(queue->capacity * sizeof(int)); // Allocate memory for the queue array
    return queue;
}

// Function to check if the queue is full
// The queue is full when the size becomes equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
// The queue is empty when the size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
// It changes rear and increases the size by 1
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity; // Circular increment of rear
    queue->arr[queue->rear] = item; // Add item to the queue
    queue->size = queue->size + 1;  // Increment size
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from the queue
// It changes front and decreases the size by 1
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->arr[queue->front]; // Get the front item
    queue->front = (queue->front + 1) % queue->capacity; // Circular increment of front
    queue->size--; // Decrement size
    return item;
}

// Main function to test the queue operations
int main() {
    struct Queue* queue = createQueue(1000); // Create a queue with capacity 1000

    enqueue(queue, 10); // Enqueue 10 to queue
    enqueue(queue, 20); // Enqueue 20 to queue
    enqueue(queue, 30); // Enqueue 30 to queue

    // Dequeue items and print them
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    // Free allocated memory for the queue array and queue itself
    free(queue->arr);
    free(queue);

    return 0;
}
// Output:
// 10 enqueued to queue
// 20 enqueued to queue
// 30 enqueued to queue
// 10 dequeued from queue
// 20 dequeued from queue
// 30 dequeued from queue