#include <stdio.h>
#include <stdlib.h>

void stackExample() {
    int stackVar = 42;  // Stack variable
    printf("Stack variable: %d\n", stackVar);
}

void heapExample() {
    int* headVar = (int*)malloc(sizeof(int)); // Heap variable
    if(headVar == NULL) {
        fprintf(stderr, "Memory allocation failed \n");
        return;
    }
    *headVar = 42;
    printf("Heap variable: %d\n", *headVar);
    free(headVar); // Free the allocated memory
}

int main() {
    stackExample();
    heapExample();
    return 0;
}