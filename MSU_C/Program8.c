#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions8.h"

// Author: 112-Maskin-Danil 
// This program reads the coordinates of a polygon from a file and outputs whether it is convex
// It also finds the location of a given point relative to a polygon
int main(void) {
	char filename[100];
	FILE *f, *f2;
	const char* location;
	double x, y;
	int pc = 0;

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

		while (fscanf(f, "%lf %lf", &x, &y) == 2) {
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
			fprintf(stderr, "file contains < 3 points", filename);
			return -1;
		}
		if (isConvex(head)) {
			printf("Convex\n");
		}
		else {
			printf("Not convex\n");
		}

		f2 = fopen("points.txt", "r");
		if (f2) {
			while (fscanf(f2, "%lf %lf", &x, &y) == 2) {
				printf("The point (%lf, %lf) is: %s\n", x, y, pointLocation(head, x, y));
			}
		}
		else {
			fprintf(stderr, "file points.txt is not found", filename);
			return -1;
		}
		
		
		/*printf("Enter point coordinates (x y): ");
		scanf("%lf %lf", &x, &y);
		location = pointLocation(head, x, y);
		printf("The point is: %s\n", location);*/

		freeList(head);
		fclose(f);
	}
	else {
		fprintf(stderr, "file \"%s\" is not found", filename);
		return -1;
	}
	return 0;
}