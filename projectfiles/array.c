#include <stdio.h>

int main() {
    int arr[5]; // Declare an array of size 5

    // Initialize each element of the array with a loop
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1; // Assign values 1 to 5 to the array elements
    }

    // Print each element of the array
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]); // Print the value of the current array element
    }

    return 0; // Return 0 to indicate successful execution
}
// Output:
// 1
// 2
// 3
// 4
// 5
