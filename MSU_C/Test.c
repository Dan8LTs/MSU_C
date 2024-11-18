#include <stdio.h>
#include <string.h>

struct Student {
	int id;
	char name[50];
	float grade;
};

int compare(const void* a, const void* b) {
	return ((struct Student*)a)->grade > ((struct Student*)b)->grade ? 1 : -1;
}

int main() {
	struct Student students[] = {
		{1, "Alice", 85.5},
		{2, "Bob", 92.0},
		{3, "Charlie", 78.0},
		{4, "David", 88.5}
	};
	int i;
	int indices[4];

	for (i = 0; i < 4; i++) {
		indices[i] = i;
	}

	qsort(indices, 4, sizeof(int), compare);

	printf("Sorted students by grade:\n");
	for (i = 0; i < 4; i++) {
		printf("ID: %d, Name: %s, Grade: %.2f\n", students[indices[i]].id, students[indices[i]].name, students[indices[i]].grade);
	}

	return 0;
}