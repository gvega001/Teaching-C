#include <stdio.h>

void bubbleSort(int arr[], int size) {
	// Iterate through the array
	for (int i = 0; i < size - 1; i++) {
		// Compare adjacent elements
		for (int j = 0; j < size - 1 - i; j++) {
			// Swap if the element is greater
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				// Swap the elements
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	// Define an array and its size
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int size = sizeof(arr) / sizeof(arr[0]);

	// Call the bubble sort function
	bubbleSort(arr, size);

	// Print the sorted array
	printf("Sorted arrray: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]); 
	}
	return 0; 
}
// Output: Sorted array:	
	// 11 12 22 25 34 64 90