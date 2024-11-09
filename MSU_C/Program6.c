#include <stdio.h>

int changeBit0(int n, int bit);
int changeBit1(int n, int bit);
void PrintBinary(int n);

// Author: 112-Maskin-Danil.
// Solution of problem 1.
// This program writes 0 and 1 to the specified bit of the given integer.
int main() {
	int n, bit;
	printf("Author: 112-Maskin-Danil.\n");
	printf("This program writes 0 and 1 to the specified bit of the given integer.\n");
	printf("Enter number: ");
	if (scanf_s("%d", &n) != 1) {
		fprintf(stderr, "wrong format");
		return -1;
	}
	printf("Enter bit: ");
	if (scanf_s("%d", &bit) != 1) {
		fprintf(stderr, "wrong format");
		return -1;
	}

	printf("Result:\n");
	printf("n = %d, binary: ", n);
	PrintBinary(n);

	printf("bit %d = 0:\n", bit);
	printf("n = %d, binary: ", changeBit0(n, bit));
	PrintBinary(changeBit0(n, bit));

	printf("bit %d = 1:\n", bit);
	printf("n = %d, binary: ", changeBit1(n, bit));
	PrintBinary(changeBit1(n, bit));
	return 0;
}

// Author: 112-Maskin-Danil.
// This function takes a number n, bit number to change.
// Returns a number with bit changed to 0.
int changeBit0(int n, int bit) {
	return n & ~(1 << bit);
}
// Author: 112-Maskin-Danil.
// This function takes a number n, bit number to change.
// Returns a number with bit changed to 1.
int changeBit1(int n, int bit) {
	return n | (1 << bit);
}
// Author: 112-Maskin-Danil.
// This function takes a number n.
// Returns the binary form of n.
void PrintBinary(int n) {
	for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
		printf("%d", (n >> i) & 1);
		if (i % 8 == 0) printf(" ");
	}
	printf("\n");
}