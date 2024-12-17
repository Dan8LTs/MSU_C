#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions8.h"

// Author: 112-Maskin-Danil 
// This program reads the coordinates of a polygon from a file and outputs whether it is convex
// It also finds the location of points relative to a polygon
int main(void) {
	char filename1[100], filename2[100];
	FILE* f1, * f2;
	double x, y;
	int pc = 0;

	printf("Author: 112-Maskin-Danil\n");
	printf("This program reads the coordinates of a polygon from a file and outputs whether it is convex.\n");
	printf("It also finds the location of points relative to a polygon\n");

	printf("Enter file with polygon name: ");
	fgets(filename1, sizeof(filename1), stdin);
	filename1[strcspn(filename1, "\n")] = '\0';

	printf("Enter file with points name: ");
	fgets(filename2, sizeof(filename2), stdin);
	filename2[strcspn(filename2, "\n")] = '\0';

	f1 = fopen(filename1, "r");
	f2 = fopen(filename2, "r");

	if (f1 && f2) {
		Point* head = NULL;
		Point* tail = NULL;

		while (fscanf(f1, "%lf %lf", &x, &y) == 2) {
			Point* newPoint = createPoint(x, y);
			pc++;
			if (head == NULL) {
				head = newPoint;
				tail = newPoint;
				tail->next = head;
			}
			else {
				insert_after(tail, x, y);
				tail = tail->next;
			}
		}

		if (pc < 3) {
			fprintf(stderr, "polygon contains < 3 points");
			return -1;
		}
		if (isConvex(head)) {
			printf("Convex\n");
		}
		else {
			printf("Not convex\n");
		}

		while (fscanf(f2, "%lf %lf", &x, &y) == 2)
		{
			printf("The point (%lf, %lf) is: %s\n", x, y, pointLocation(head, x, y));
		}

		freeList(head);
		fclose(f1);
		fclose(f2);
	}
	else {
		fprintf(stderr, "files were not found");
		return -1;
	}
	return 0;
}
