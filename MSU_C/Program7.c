#include <stdio.h>

// Author: 112-Maskin-Danil
// This function takes N - number of elements in a set, k - number of elements in required subsets, and file to write output.
// It prints subsets of a set from 1 to n with k elements.
void generateSubsets(int N, int k, FILE* file) {
	int totalSubsets = 1 << N;

	for (int i = 0; i < totalSubsets; i++) {
		int count = 0;
		int subset[32];

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				subset[count++] = j + 1;
			}
		}

		if (count == k) {
			for (int m = 0; m < count; m++) {
				fprintf(file, "%d ", subset[m]);
			}
			fprintf(file, "\n");

			for (int m = 0; m < count; m++) {
				printf("%d ", subset[m]);
			}
			printf("\n");
		}
	}
}

// Author: 112-Maskin-Danil
// This program outputs to a file and to the console all k-element subsets of the set of numbers from 1 to n.
int main() {
	int N, k;
	char filename[100];

	printf("Author: 112-Maskin-Danil\n");
	printf("This program outputs to a file and to the console all k-element subsets of the set of numbers from 1 to n.\n");
	printf("Enter N: ");
	scanf_s("%d", &N);
	printf("Enter k: ");
	scanf_s("%d", &k);
	getchar();

	printf("Enter file name: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strcspn(filename, "\n")] = '\0';
	FILE* f = fopen(filename, "w");
	if (f) {
		if (filename == NULL) {
			perror("Error opening file");
			return 1;
		}

		generateSubsets(N, k, f);
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"%s\" is not found", filename);
		return -1;
	}

	return 0;
}