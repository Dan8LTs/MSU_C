#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 0.00001

double abs_value(double x);
double koren(double (*f)(double), double a, double b, int* err, int* iterations);
double example_function(double x);

// Author: 112-Maskin-Danil  
// This program calculates the root of the equation f(x) = 0 on a given segment with a given accuracy EPS.
int main() {
	double a1 = 0.0, b1 = 2.0;
	int err1, iterations1;
	double root1 = koren(example_function, a1, b1, &err1, &iterations1);

	double a2 = 1.0, b2 = 2.0;
	int err2, iterations2;
	double root2 = koren(sin, a2, b2, &err2, &iterations2);

	printf("Author: 112-Maskin-Danil\n");
	printf("This program calculates the root of the equation f(x) = 0 on a given segment with a given accuracy EPS.\n\n");

	printf("Test 1: Finding the root of the equation x^2 - 2 on the segment [0, 2]\n");
	if (err1 == 0) {
		printf("Found root: %lf\n", root1);
		printf("Number of iterations: %d\n", iterations1);
		printf("Exact root: %lf\n", sqrt(2));
	}
	else {
		printf("Error: No root in the given interval.\n");
	}

	printf("\n");

	printf("Test 2: Finding the root of the equation sin(x) on the segment [1, 2]\n");
	if (err2 == 0) {
		printf("Found root: %lf\n", root2);
	}
	else {
		printf("Error: No root in the given interval.\n");
	}

	return 0;
}

// Author: 112-Maskin-Danil  
// This function calculates the absolute value of a double number.
// Returns the absolute value as a double.
double abs_value(double x) {
	return (x < 0) ? -x : x;
}

// Author: 112-Maskin-Danil  
// This function finds a root of the function f in the interval [a, b] using the secant method.
// It returns the root as a double and sets err to indicate success or failure.
double koren(double (*f)(double), double a, double b, int* err, int* iterations) {
	if (f(a) * f(b) > 0) {
		*err = 1;
		return 0.0;
	}

	double c;
	*err = 0;
	*iterations = 0;

	while (1) {
		c = b - f(b) * (b - a) / (f(b) - f(a));
		(*iterations)++;

		if (abs_value(f(c)) < EPS) {
			return c;
		}

		if (f(a) * f(c) < 0) {
			b = c;
		}
		else {
			a = c;
		}
	}
}

// Author: 112-Maskin-Danil  
// This function defines the example function f(x) = x^2 - 2.
// Returns the value of the function at x as a double.
double example_function(double x) {
	return x * x - 2;
}