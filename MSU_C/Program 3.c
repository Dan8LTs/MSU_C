#include <stdio.h>
#define eps 0.00001

double abs(double);
void Process1(double*, int, double, int*);
void Process2(double*, int, double*);


// This program solves tasks 5 and 23. You can choose mode. 
// In both modes, the program reads data from a file and outputs the result. Author: 112-Maskin-Danil. 
int main() {
	int mode = 0;
	int i = 0;
	int retcode = 0;
	char filename[100];
	double data[1000];

	printf("This program solves tasks 5 and 23. Author: 112-Maskin-Danil. \n");
	printf("Select mode 5 or 23: \n");

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
		for (i = 0; fscanf_s(f, "%lf", &data[i]) == 1 && i < 1000; ++i) {}
		if (i == 0) {
			fprintf(stderr, "file is empty");
			return -1;
		}
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"%s\" is not found", filename);
		return -1;
	}

	if (mode == 5) {
		int res1 = 0;
		double x;
		printf("This program finds the number X in the sequence of numbers from %s\n", filename);
		printf("Enter X: ");
		if (scanf_s("%lf", &x) != 1) {
			fprintf(stderr, "wrong format");
			return -1;
		}
		Process1(data, i, x, &res1);

		printf("Result: ");
		printf(res1 > 0 ? "X was found" : "X wasn't found");
	}
	else if (mode == 23) {
		double res2;
		printf("This program finds the largest sum of an increasing portion of a sequence from %s\n", filename);
		Process2(data, i, &res2);

		printf("Result: %lf", res2);
	}
	else {
		fprintf(stderr, "wrong mode");
		return -1;
	}
	return 0;
}

// Author: 112-Maskin-Danil.
// This function returns the absolute value of a number.
double abs(double v) {
	return v > 0 ? v : -v;
}

// Author: 112-Maskin-Danil.
// Solution of problem 5.
// This function takes a file, a number x, and a variable res to write the result to.
// It returns retcode -1 if the file is empty, else 0.
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
// This function takes a file and a variable res to write the result to.
// It returns retcode -1 if the file is empty, else 0.
void Process2(double data[], int n, double* res2) {
	double s = data[0], max_s;
	int i;
	max_s = 0;

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