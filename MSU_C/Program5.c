#include <stdio.h>
#include <string.h>
#include "Functions5.h"
#define N 1000

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
			getchar();
			return -1;
		}
		else if (i >= N) {
			printf("Warning: The file contains more than N elements. I will process only N elements.\n");
		}
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"%s\" is not found", filename);
		getchar();
		return -1;
	}

	printf("Result: ");
	printf(Process(data, i < N ? i : N) == 1 ? "Yes" : "No");
	getchar();
	return 0;
}