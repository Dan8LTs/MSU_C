#include <stdio.h>
#include <math.h>
#define eps 0.00001

double func(double x);
double find_min(double (*f)(double), double a, double b);

// Author: 112-Maskin-Danil  
// This program calculates the minimum value of a given function f(x) with a given accuracy eps.
int main(void) {
	printf("Author: 112-Maskin-Danil\n");
	printf("This program calculates the minimum value of a given function f(x) with a given accuracy eps.\n\n");

	printf("Test: f(x) = (x-2)^2\n");
	printf("Minimum on segment [0, 4] equals %f\n", find_min(func, 0, 4));
	printf("Exact value: minimum at x = 2, f(2) = 0\n");

	return 0;
}

// Author: 112-Maskin-Danil  
// This function defines the example function f(x) = (x-2)^2.
// Returns the value of the function at x as a double.
double func(double x) {
	return (x - 2) * (x - 2);
}

// Author: 112-Maskin-Danil
// This function calculates the minimum of the given function f on the interval [a, b] with a given accuracy eps.
double find_min(double (*f)(double), double a, double b) {
	double x1 = a;
	double x2 = (a + b) / 2;
	double x3 = b;
	double f1, f2, f3, denominator, x_min;

	while (fabs(b - a) > eps) {
		f1 = f(x1);
		f2 = f(x2);
		f3 = f(x3);

		denominator = (f1 - f2) * (f1 - f3) * (f2 - f3);
		if (denominator < eps) break;

		x_min = (f1 * (x2 * x2 - x3 * x3) + f2 * (x1 * x1 - x3 * x3) + f3 * (x1 * x1 - x2 * x2)) /
			(f1 * (x2 - x3) + f2 * (x1 - x3) + f3 * (x1 - x2));

		if (x_min < x2) {
			b = x2;
			x3 = x2;
			x2 = x_min;
		}
		else {
			a = x2;
			x1 = x2;
			x2 = x_min;
		}
	}

	return f((a + b) / 2);
}
