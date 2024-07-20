#include <stdio.h>
// Function to perform linear search in an array
int linearSearch(int arr[], int size, int target) {
	// Iterate through the array
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1; 
}

int main() {
	// Define an array and its size
	int arr[] = { 10, 20, 30, 40, 50 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 30;
	int result = linearSearch(arr, size, target);
	//	Print the result
	if (result != -1) {
		printf("Element found at index %d\n", result);
	}
	else {
		printf("Element not found\n");
	}

	return 0; 
}
// Output: Element found at index 2