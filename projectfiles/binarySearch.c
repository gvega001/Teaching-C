#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    // Define the left and right pointers
    int left = 0, right = size - 1;
    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Check if the target is present at the middle
        if (arr[mid] == target) {
            return mid;
        }
        // If the target is greater, ignore the left half
		else
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Define an array and its size
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 40;
    int result = binarySearch(arr, size, target);
    // Print the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    }
    else {
        printf("Element not found\n");
    }

    return 0;
}
// Output: Element found at index 3
