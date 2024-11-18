#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void tests();
int checkIntOrder(int arr[], int n);
int checkDoubleOrder(double arr[], int n);
int* generateIntArray(int n);
double* generateDoubleArray(int n);
void bubbleIntSort(int arr[], int n);
void bubbleDoubleSort(double arr[], int n);
void siftingIntSort(int arr[], int n);
void siftingDoubleSort(double arr[], int n);
void printIntArray(int arr[], int n);
void printDoubleArray(double arr[], int n);
double* readDoublesFromFile(int n);
void writeDoublesToFile(const char* filename, double* array, size_t size);


// Author: 112-Maskin-Danil
// Program for sorting algorithms.
int main() {
	tests();

	clock_t s1, s2, e1, e2;
	int n = 15;
	int* arr1 = generateIntArray(n);
	double* arr2 = generateDoubleArray(n);
	double* arr3;

	printf("Author: 112-Maskin-Danil\n");
	printf("Program for sorting algorithms.\n");

	printf("\nSource int array: \n");
	printIntArray(arr1, n);
	s1 = clock();
	siftingIntSort(arr1, n);
	e1 = clock();
	printf("Sorted int array: \n");
	printIntArray(arr1, n);
	printf("Is sorted: %d\n", checkIntOrder(arr1, n));
	printf("Execution time: %lf seconds\n\n", (double)(e1 - s1) / CLOCKS_PER_SEC);

	printf("Source double array: \n");
	printDoubleArray(arr2, n);
	s2 = clock();
	siftingDoubleSort(arr2, n);
	e2 = clock();
	printf("Sorted double array: \n");
	printDoubleArray(arr2, n);
	printf("Is sorted: %d\n", checkDoubleOrder(arr2, n));
	printf("Execution time: %lf seconds\n\n", (double)(e2 - s2) / CLOCKS_PER_SEC);

	arr3 = readDoublesFromFile(n);
	bubbleDoubleSort(arr3, n);
	writeDoublesToFile("output.txt", arr3, n);

	return 0;
}

// Author: 112-Maskin-Danil
// This function was created for testing program.
void tests() {
	clock_t s1, s2, e1, e2;
	int n = 10000;
	double* arr1 = generateDoubleArray(n);
	double* arr2 = generateDoubleArray(n);

	printf("Tests\n");
	printf("%d elements\n", n);

	s1 = clock();
	siftingDoubleSort(arr1, n);
	e1 = clock();
	printf("Algorithm - sifting double sort: \n");
	printf("Is sorted: %d\n", checkDoubleOrder(arr1, n));
	printf("Execution time: %lf milliseconds\n\n", (double)(e1 - s1) / CLOCKS_PER_SEC);

	s2 = clock();
	bubbleDoubleSort(arr2, n);
	e2 = clock();
	printf("Algorithm - bubble double sort: \n");
	printf("Is sorted: %d\n", checkDoubleOrder(arr2, n));
	printf("Execution time: %lf milliseconds\n\n", (double)(e2 - s2) / CLOCKS_PER_SEC);
}

// Author: 112-Maskin-Danil
// This function checks if the elements of int array "arr" are in order, n - arr length
// Returns 1 if true, else 0
int checkIntOrder(int arr[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return 0;
		}
	}
	return 1;
}

// Author: 112-Maskin-Danil
// This function checks if the elements of double array "arr" are in order, n - arr length
// Returns 1 if true, else 0
int checkDoubleOrder(double arr[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return 0;
		}
	}
	return 1;
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

// Author: 112-Maskin-Danil
// This function returns an array of length n random doubles. 
double* generateDoubleArray(int n) {
	int i;
	srand(time(NULL));

	double* res = (double*)malloc(n * sizeof(double));

	for (i = 0; i < n; i++) {
		res[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
	}
	return res;
}

// Author: 112-Maskin-Danil
// Implementation of the bubble sort algorithm for an array of integers of length n.
void bubbleIntSort(int arr[], int n) {
	int i, k, temp, swapped;

	for (k = n - 1; k > 0; k--) {
		swapped = 0;
		for (i = 1; i <= k; i++) {
			if (arr[i - 1] > arr[i]) {
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

// Author: 112-Maskin-Danil
// Implementation of the bubble sort algorithm for an array of doubles of length n.
void bubbleDoubleSort(double arr[], int n) {
	int i, k, swapped;
	double temp;
	for (k = n - 1; k > 0; k--) {
		swapped = 0;
		for (i = 1; i <= k; i++) {
			if (arr[i - 1] > arr[i]) {
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

// Author: 112-Maskin-Danil
// Implementation of the sifting sort algorithm for an array of integers of length n.
void siftingIntSort(int arr[], int n) {
	int i, k, temp;
	for (i = 1; i < n; i++) {
		for (k = i; k > 0 && arr[k] < arr[k - 1]; k--) {
			temp = arr[k];
			arr[k] = arr[k - 1];
			arr[k - 1] = temp;
		}
	}
}

// Author: 112-Maskin-Danil
// Implementation of the sifting sort algorithm for an array of doubles of length n.
void siftingDoubleSort(double arr[], int n) {
	int i, k;
	double temp;
	for (i = 1; i < n; i++) {
		for (k = i; k > 0 && arr[k] < arr[k - 1]; k--) {
			temp = arr[k];
			arr[k] = arr[k - 1];
			arr[k - 1] = temp;
		}
	}
}

// Author: 112-Maskin-Danil
// Outputs an array of integers to the console
void printIntArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Author: 112-Maskin-Danil
// Outputs an array of doubles to the console
void printDoubleArray(double arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%lf ", arr[i]);
	printf("\n");
}

// Author: 112-Maskin-Danil
// Reads doubles from file. 
// Returns array of doubles length n.
double* readDoublesFromFile(int n)
{
	char filename[100];
	double* array;
	double el;
	int i;

	printf("Enter file name: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strcspn(filename, "\n")] = '\0';
	FILE* f = fopen(filename, "r");
	if (f) {
		array = malloc(n * sizeof(double));
		for (i = 0; fscanf_s(f, "%lf", &el) == 1; i++)
		{
			if (i < n) array[i] = el;
		}
		if (i == 0) {
			fprintf(stderr, "file is empty");
			return -1;
		}
		else if (i > n) {
			printf("Warning: The file contains more than N elements. I will process only N elements.\n");
		}
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"%s\" is not found", filename);
		return -1;
	}
	return array;
}

// Author: 112-Maskin-Danil
// Writes doubles to file. 
// Takes a file name, an array and its size.
void writeDoublesToFile(const char* filename, double* array, size_t size) {
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "file \"%s\" is not found", filename);
		return;
	}

	for (size_t i = 0; i < size; i++) {
		fprintf(file, "%1.7f ", array[i]);

		if ((i + 1) % 10 == 0) {
			fprintf(file, "\n");
		}
	}

	fclose(file);
}