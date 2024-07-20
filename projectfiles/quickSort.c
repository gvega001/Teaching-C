#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int arr[], int low, int high) {
	int pivot = arr[high]; 
	int i = (low - 1);
	// Iterate through the array
	for (int j = low; j <= high - 1; j++) {
		// If the current element is smaller than the pivot element
		if (arr[j] < pivot) {
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	// Swap the pivot element with the element at index i + 1
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high);
	}
}

int main() {
	// Define an array and its size
	int arr[] = { 10, 7, 8, 9, 1, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	// Call the quick sort function
	quickSort(arr, 0, size - 1);

	// Print the sorted array
	printf("Sorted array: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

// Output: Sorted array:
	// 1 4 7 8 9 10