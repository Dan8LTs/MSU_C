#include <stdio.h>
#include <stdlib.h>


void bubbleIntSort(int arr[], int n);
int* generateIntArray(int n);
void printBinary(int n);
int cmp(int a, int b);


// Author: 112-Maskin-Danil
// This program sorts generated numbers by the number of ones in binary notation. 
// It outputs the number, its binary representation, and the number of ones.
int main() {
	int n = 15;
	int* arr = generateIntArray(n);
	int onecount;
	int i;

	printf("Author: 112-Maskin-Danil\n");
	printf("This program sorts generated numbers by the number of ones in binary notation.\n");
	printf("It outputs the number, its binary representation, and the number of ones.\n");

	printf("\nSource int array: \n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	bubbleIntSort(arr, n);

	printf("Sorted int array: \n");
	for (i = 0; i < n; i++) {
		onecount = 0;
		printf("%6d  ", arr[i]);
		printBinary(arr[i]);
		for (int j = 0; j < 32; j++) {
			if ((arr[i] >> j) & 1) {
				onecount++;
			}
		}
		printf(" %d\n", onecount);
	}
	return 0;
}


// Author: 112-Maskin-Danil
// This function returns an array of length n random integers. 
int* generateIntArray(int n) {
	int i;
	int* res = (int*)malloc(n * sizeof(int));

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		res[i] = rand();
	}
	return res;
}

// Author: 112-Maskin-Danil.
// This function takes numbers "a" and "b".
// Returns 1 if the binary form of "a" contains more ones than "b", else 0.
int cmp(int a, int b) {
	int aonecount = 0;
	int bonecount = 0;

	for (int i = 0; i < 32; i++) {
		if ((a >> i) & 1) {
			aonecount++;
		}
		if ((b >> i) & 1) {
			bonecount++;
		}
	}
	return aonecount > bonecount ? 1 : 0;
}

// Author: 112-Maskin-Danil
// Implementation of the bubble sort algorithm for an array of integers of length n.
void bubbleIntSort(int arr[], int n) {
	int i, k, temp, swapped;

	for (k = n - 1; k > 0; k--) {
		swapped = 0;
		for (i = 1; i <= k; i++) {
			if (cmp(arr[i - 1], arr[i])) {
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0) {
			break;
		}
	}
}

// Author: 112-Maskin-Danil.
// This function takes a number n.
// Returns the binary form of n.
void printBinary(int n) {
	for (int i = 31; i >= 0; i--) {
		printf("%d", (n >> i) & 1);
		if (i % 8 == 0) printf(" ");
	}
}