#include <stdio.h>

// Author: 112-Maskin-Danil.
void MinMax(double* A, int N, double* min1, double* max1) {
	int i;
	*min1 = A[0];
	*max1 = A[0];
	for (i = 1; i < N; i++) {
		*min1 = *min1 < A[i] ? *min1 : A[i];
		*max1 = *max1 > A[i] ? *max1 : A[i];
	}
}

// Author: 112-Maskin-Danil.
int main() {
	double nums[1000];
	int i = 0;
	double min1;
	double max1;

	FILE* f = fopen("input.txt", "r");
	if (f) {
		for (i = 0; fscanf_s(f, "%lf", &nums[i]) == 1 && i < 1000; ++i) {}
		if (i == 0) {
			fprintf(stderr, "file is empty");
			return -1;
		}
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"input.txt\" is not found");
		return -1;
	}

	MinMax(nums, i, &min1, &max1);
	printf("Result: min: %lf, max: %lf", min1, max1);
}