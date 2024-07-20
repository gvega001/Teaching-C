#include <stdio.h> 

void selectionSort(int arr[], int size) {

	// Iterate through the array
	for (int i = 0; i < size - 1; i++) {
		int min_idx = i;
		// Find the minimum element in the unsorted part of the array
		for (int j = i + 1; j < size; j++) {
			// Update the minimum index
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		// Swap the minimum element with the first element
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp; 
	}
}

int main() {

	// Define an array and its size
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int size = sizeof(arr) / sizeof(arr[0]);

	// Call the selection sort function
	selectionSort(arr, size);

	// Print the sorted array
	printf("Sorted array: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	return 0; 
}
// Output: Sorted array:
	// 11 12 22 25 34 64 90