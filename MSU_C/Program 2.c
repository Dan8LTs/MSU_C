#include <stdio.h>
#define eps 0.00001

double abs(double);
int Process1(FILE*, double, int*);
int Process2(FILE*, double*);

// This program solves tasks 5 and 23. You can choose mode. 
// In both modes, the program reads data from a file and outputs the result. Author: 112-Maskin-Danil. 
int main() {
	int mode = 0;
	int retcode;

	printf("This program solves tasks 5 and 23. Author: 112-Maskin-Danil. \n");
	printf("Select mode 5 or 23: \n");
	if (scanf_s("%d", &mode) != 1) {
		fprintf(stderr, "wrong format");
		return -1;
	}
	if (mode != 5 && mode != 23) {
		fprintf(stderr, "wrong mode");
		return -1;
	}

	if (mode == 5) {
		int res1 = 0;
		double x;
		printf("This program finds the number X in the sequence of numbers from input.txt\n");
		FILE* f = fopen("input.txt", "r");
		if (f) {
			printf("Enter X: ");
			if (scanf_s("%lf", &x) != 1) {
				fprintf(stderr, "wrong format");
				return -1;
			}
			retcode = Process1(f, x, &res1);
			if (retcode < 0) {
				fprintf(stderr, "file is empty");
				return -1;
			}
			printf("Result: ");
			printf(res1 > 0 ? "X was found" : "X wasn't found");
			fclose(f);
		}
		else {
			fprintf(stderr, "file \"input.txt\" is not found");
			return -1;
		}
	}
	else if (mode == 23) {
		double res2;
		printf("This program finds the largest sum of an increasing portion of a sequence from input.txt\n");
		FILE* f = fopen("input.txt", "r");
		if (f) {
			retcode = Process2(f, &res2);
			if (retcode < 0) {
				fprintf(stderr, "file is empty");
				return -1;
			}
			printf("Result: %lf", res2);
			fclose(f);
		}
		else {
			fprintf(stderr, "file \"input.txt\" is not found");
			return -1;
		}
	}
	return 0;
}

// This function returns the absolute value of a number.
double abs(double v) {
	return v > 0 ? v : -v;
}

// Solution of problem 5.
// This function takes a file, a number x, and a variable res to write the result to.
// It returns retcode -1 if the file is empty, else 0.
int Process1(FILE* f, double x, int* res1) {
	double n;
	int retcode = -1;
	while (fscanf_s(f, "%lf", &n) == 1) {
		retcode = 0;
		if (abs(x - n) < eps) {
			*res1 = 1;
			break;
		}
	}
	return retcode;
}

// Solution of problem 23.
// This function takes a file and a variable res to write the result to.
// It returns retcode -1 if the file is empty, else 0.
int Process2(FILE* f, double* res2) {
	double a, b, s, max_s;
	max_s = 0;
	int retcode = -1;
	if (fscanf_s(f, "%lf", &a) == 1) {
		s = a;
		retcode = 0;
	}

	while (fscanf_s(f, "%lf", &b) == 1) {
		if (b > a) {
			s += b;
		}
		else {
			s = b;
		}
		max_s = max_s > s ? max_s : s;
		a = b;
	}
	*res2 = max_s;
	return retcode;
}