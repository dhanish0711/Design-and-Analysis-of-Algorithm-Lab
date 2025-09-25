// Write a program to perform Quick sort. Display the partial pass-wise sorting done.

#include <stdio.h>
void displayPass (int arr[], int l, int r) {
	printf("Pass: ");
	for (int i = l; i <= r; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition (int arr[20], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return(i + 1);
}

void quicksort (int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		displayPass(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int main() {
	int n;
	printf("number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("elements: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Original array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	quicksort(arr, 0, n - 1);
	printf("Sorted array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
