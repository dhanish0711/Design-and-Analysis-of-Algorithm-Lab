// Write a program to search the given element from a list of elements with binary search technique using recursion.

// Program912.c
#include <stdio.h>
#include "Program912a.c"
void main() {
	int a[20], n, key, flag;
	printf("Enter value of n : ");
	scanf("%d", &n);
	read1(a, n);
	bubbleSort(a, n);
	printf("After sorting the elements are : ");
	display(a, n);
	printf("Enter key element : ");
	scanf("%d", &key);
	flag = binarySearch(a, 0, n - 1, key);
	if (flag == -1) {
		printf("The given key element %d is not found\n", key);
	} else {
		printf("The given key element %d is found at position : %d\n", key, flag);
	}
}

// Program912a.c
#include <stdio.h>

void read1(int a[], int n) {
	printf("Enter %d elements : ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

void bubbleSort(int a[], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 -i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void display(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
}

int binarySearch(int a[], int low, int high, int key) {
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (a[mid] == key) {
		return mid;
	} else if (key < a[mid]) {
		return binarySearch(a, low, mid - 1, key);
	} else {
		return binarySearch(a, mid + 1, high, key);
	}
}
