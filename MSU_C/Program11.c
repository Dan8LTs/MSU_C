#include <stdio.h>

#define EPS 0.00001

double integral(double (*f)(double), double a, double b);
double func(double x);
double abs_value(double x);

// Author: 112-Maskin-Danil  
// This program calculates the integral of a given function on a given segment with a given accuracy EPS.
int main() {
	double a = 0.0, b = 1.0;
	double result = integral(func, a, b);

	printf("Author: 112-Maskin-Danil\n");
	printf("This program calculates the integral of a given function on a given segment with a given accuracy EPS.\n\n");

	printf("Test: calculation of the integral of the function x^2 on the segment [0, 1]\n");
	printf("Result: %.10f\n", result);
	printf("Exact value: %.10f\n", 1.0 / 3.0);

	return 0;
}

// Author: 112-Maskin-Danil
// This function performs numerical integration of the given function f on the interval [a, b].
// Returns the final estimate of the integral.
double integral(double (*f)(double), double a, double b) {
	int N = 20, i;
	double h, integral_old = 0.0, integral_new;

	h = (b - a) / N;
	for (i = 0; i < N; i++) {
		integral_old += f(a + i * h);
	}
	integral_old *= h;

	while (1) {
		N *= 2;
		h = (b - a) / N;
		integral_new = 0.0;

		for (i = 0; i < N; i++) {
			integral_new += f(a + i * h);
		}
		integral_new *= h;

		if (abs_value(integral_new - integral_old) < EPS) {
			break;
		}

		integral_old = integral_new;
	}
	return integral_new;
}

// Author: 112-Maskin-Danil  
// This function defines the mathematical function to be integrated.
// In this case, it returns the square of the input value x.
double func(double x) {
	return x * x;
}

// Author: 112-Maskin-Danil  
// This function calculates the absolute value of a double number.
// Returns the absolute value as a double.
double abs_value(double x) {
	return (x < 0) ? -x : x;
}