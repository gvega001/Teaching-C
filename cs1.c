#include <stdio.h>
#include "stepc.h"

int main(void) {
    // Example usage of the library

    // Working with linked lists
    Node* head = NULL;
    append_linked_list(&head, 10);
    append_linked_list(&head, 20);
    append_linked_list(&head, 30);

    printline("Linked List:");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", get_linked_list(head, i));
    }

    // Clean up
    free_linked_list(head);

    // Working with ArrayLists
    ArrayList list = create_array_list(2, 3);
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};
    append_array_list(&list, array1);
    append_array_list(&list, array2);

    printline("Array List:");
    for (int i = 0; i < list.size; i++) {
        int* arr = get_array_list(&list, i);
        for (int j = 0; j < list.array_size; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }

    // Clean up
    free_array_list(&list);

    return 0;
}
