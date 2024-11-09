#include <stdio.h>
#define eps 0.00001
#define N 1000

double abs(double);
void Process1(double*, int, double, int*);
void Process2(double*, int, double*);

// Author: 112-Maskin-Danil. 
// This program solves tasks 5 and 23. You can choose mode. 
// In both modes, the program reads data from a file and outputs the result. 
int main() {
	int mode = 0, i = 0, res1;
	double el, res2, x, data[N];
	char filename[100];

	printf("This program solves tasks 5 and 23. Author: 112-Maskin-Danil. \n");
	printf("Select mode 5 or 23: ");

	if (scanf_s("%d", &mode) != 1) {
		fprintf(stderr, "wrong format");
		return -1;
	}
	getchar();

	printf("Enter file name: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strcspn(filename, "\n")] = '\0';
	FILE* f = fopen(filename, "r");
	if (f) {
		for (i = 0; fscanf_s(f, "%lf", &el) == 1; ++i)
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

	if (mode == 5) {
		printf("This program finds the number X in the sequence of numbers from %s\n", filename);
		printf("Enter X: ");
		if (scanf_s("%lf", &x) != 1) {
			fprintf(stderr, "wrong format");
			return -1;
		}

		Process1(data, i < N ? i : N, x, &res1);

		printf("Result: ");
		printf(res1 == 1 ? "X was found" : "X wasn't found");
	}
	else if (mode == 23) {
		printf("This program finds the largest sum of an increasing portion of a sequence from %s\n", filename);

		Process2(data, i < N ? i : N, &res2);

		printf("Result: %lf", res2);
	}
	else {
		fprintf(stderr, "wrong mode");
		return -1;
	}
	return 0;
}

// Author: 112-Maskin-Danil.
// This function returns the absolute value of a number v.
double abs(double v) {
	return v > 0 ? v : -v;
}

// Author: 112-Maskin-Danil.
// Solution of problem 5.
// This function takes an array data, used array length - n, a number x, a variable res1 to write the result to.
void Process1(double data[], int n, double x, int* res1) {
	int i;
	for (i = 0; i < n; ++i) {
		if (abs(x - data[i]) < eps) {
			*res1 = 1;
			break;
		}
	}
}

// Author: 112-Maskin-Danil.
// Solution of problem 23.
// This function takes an array data, used array length - n, a variable res2 to write the result to.
void Process2(double data[], int n, double* res2) {
	double s = data[0], max_s = data[0];
	int i;

	for (i = 0; i < (n - 1); ++i)
	{
		if (data[i + 1] > data[i]) {
			s += data[i + 1];
		}
		else {
			s = data[i + 1];
		}
		max_s = max_s > s ? max_s : s;
	}
	*res2 = max_s;
}