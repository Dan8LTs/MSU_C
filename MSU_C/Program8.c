#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions8.h"

// Author: 112-Maskin-Danil 
// This program reads the coordinates of a polygon from a file and outputs whether it is convex
// It also finds the location of a given point relative to a polygon
int main(void) {
	char filename[100];
	FILE* f;

	printf("Author: 112-Maskin-Danil\n");
	printf("This program reads the coordinates of a polygon from a file and outputs whether it is convex.\n");
	printf("It also finds the location of a given point relative to a polygon.\n");
	printf("Enter file name: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strcspn(filename, "\n")] = '\0';

	f = fopen(filename, "r");
	if (f) {
		Point* head = NULL;
		Point* tail = NULL;

		int x, y;
		while (fscanf(f, "%d %d", &x, &y) == 2) {
			Point* newPoint = createPoint(x, y);
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

		if (isConvex(head)) {
			printf("Convex\n");
		}
		else {
			printf("Not convex\n");
		}

		int px, py;
		printf("Enter point coordinates (x y): ");
		scanf("%d %d", &px, &py);
		const char* location = pointLocation(head, px, py);
		printf("The point is: %s\n", location);

		freeList(head);
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"%s\" is not found", filename);
		return -1;
	}
	return 0;
}
