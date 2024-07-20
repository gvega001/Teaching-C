#include <stdio.h>

int main() {
    int arr[5]; // Declare an array of size 5
    char word[6] = "hello"; // Declare a character array with a string "hello"

    // Declare and initialzie an arrazy of char pointers with positive sayings
    char* positiveSayings[] = {
        "Keep going!",
        "You can do it",
        "Believe in yourself",
        "Stay positive",
        "Never give up",
        "Good luck",
        "You are awesome"
    };
    // Get the number of positive sayings
    int sayings_count = sizeof(positiveSayings) / sizeof(positiveSayings[0]);

    // Print each positive saying
    // Initialize each element of the array with a loop
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1; // Assign values 1 to 5 to the array elements
    }

    // Print each element of the array
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]); // Print the value of the current array element
    }

    // Print each positive saying
    for (int i = 0; i < sayings_count; i++) {
        printf("%s\n", positiveSayings[i]); // Print the current positive saying
    }

    // Print each character of the word
    for (int i = 0; i < 5; i++) {
        printf("%c", word[i]); // Print the current character of the word
    }
    return 0; 
}
// Output:
// 1
// 2
// 3
// 4
// 5

// Keep going!
// You can do it
// Believe in yourself
// Stay positive
// Never give up
// Good luck
// You are awesome
// hello
