#include <stdio.h>
#define eps 0.00001

double abs(double);
int Process(FILE*, double, int*);

int main() {
	double x;
	int res = 0;
	int retcode;

	printf("This program finds the number X in the sequence of numbers from input.txt\n");
	FILE* f = fopen("input.txt", "r");
	if (f) {
		printf("Enter X: ");
		if (scanf_s("%lf", &x) != 1) {
			fprintf(stderr, "wrong format");
			return -1;
		}
		retcode = Process(f, x, &res);
		if (retcode < 0) {
			fprintf(stderr, "file is empty");
			return -1;
		}
		printf("Result: ");
		printf(res > 0 ? "X was found" : "X wasn't found");
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"input.txt\" is not found");
		return -1;
	}
	return 0;
}

double abs(double v) {
	return v > 0 ? v : -v;
}

int Process(FILE* f, double x, int* res) {
	double n;
	int retcode = -1;
	while (fscanf_s(f, "%lf", &n) == 1) {
		retcode = 0;
		if (abs(x - n) < eps) {
			*res = 1;
			break;
		}
	}
	return retcode;
}