#include "Functions5.h"

// Author: 112-Maskin-Danil.
// Solution of problem 1.
// This function takes an array data, used array length - n
// It returns 1 if the array elements are symmetrical, else 0
int Process(int data[], int n) {
	int i = 0, j = n - 1;
	if (n % 2 == 0) {
		while (i < j) {
			if (data[i] != data[j]) {
				return 0;
			}
			++i, --j;
		}
	}
	else {
		while (i <= j) {
			if (data[i] != data[j]) {
				return 0;
			}
			++i, --j;
		}
	}
	return 1;
}