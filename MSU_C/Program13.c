#include <stdio.h>
#include <math.h>
#define eps 0.00001

double cos_taylor(double x);

// Author: 112-Maskin-Danil  
// This program calculates the value of cos at a given point x with a given accuracy eps by summing the Taylor series.
int main(void) {
	double x;

	printf("Author: 112-Maskin-Danil\n");
	printf("This program calculates the value of cos at a given point x with a given accuracy eps by summing the Taylor series.\n\n");

	printf("Enter x: ");
	scanf("%lf", &x);

	printf("Cos (Taylor series): %lf\n", cos_taylor(x));
	printf("Cos (math.h): %lf\n", cos(x));

	return 0;
}

// Author: 112-Maskin-Danil  
// Returns the value of cos at a given point x with a given accuracy eps
double cos_taylor(double x) {
	double term = 1.0;
	double sum = term;
	int n = 1;

	while (fabs(term) > eps) {
		term *= -x * x / ((2 * n - 1) * (2 * n));
		sum += term;
		n++;
	}

	return sum;
}


