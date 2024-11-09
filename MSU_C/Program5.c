#include <stdio.h>
#define N 1000

int Process(int*, int);

// Author: 112-Maskin-Danil. 
// This program solves task 1.
// The program reads data from a file and outputs the result. 
int main() {
	int i = 0, data[N], el;
	char filename[100];

	printf("This program solves task 1. Author: 112-Maskin-Danil. \n");
	printf("It returns yes if the array elements from file are symmetrical, else - no.\n");

	printf("Enter file name: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strcspn(filename, "\n")] = '\0';
	FILE* f = fopen(filename, "r");
	if (f) {
		for (i = 0; fscanf_s(f, "%d", &el) == 1; ++i)
		{
			if (i < N) data[i] = el;
		}
		if (i == 0) {
			fprintf(stderr, "file is empty");
			return -1;
		}
		else if (i >= N) {
			printf("Warning: The file contains more than N elements. I will process only N elements.\n");
		}
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"%s\" is not found", filename);
		return -1;
	}

	printf("Result: ");
	printf(Process(data, i < N ? i : N) == 1 ? "Yes" : "No");
}

// Author: 112-Maskin-Danil.
// Solution of problem 1.
// This function takes an array data, used array length - n
// It returns 1 if the array elements are symmetrical, else 0
int Process(int data[], int n) {
	int i = 0, j = n - 1;
	if (n % 2 == 0) {
		while (i < j) {
			if (data[i] != data[j]) {
				return 0;
			}
			++i, --j;
		}
	}
	else {
		while (i <= j) {
			if (data[i] != data[j]) {
				return 0;
			}
			++i, --j;
		}
	}
	return 1;
}