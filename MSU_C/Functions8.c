#include <stdio.h>
#include <stdlib.h>
#include "Functions8.h"
#define eps 0.000001

// Author: 112-Maskin-Danil 
// This function takes point coordinates "x" and "y"; 
// Returns a pointer to the newly created point.  
Point* createPoint(double x, double y) {
	Point* newPoint = (Point*)malloc(sizeof(Point));
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;
	return newPoint;
}

// Author: 112-Maskin-Danil 
// This function 
// s a new point after the specified current point; 
// Takes the current point and the coordinates of the new point "x" and "y". 
void insert_after(Point* current, double x, double y) {
	Point* newPoint;
	if (current == NULL) return;

	newPoint = createPoint(x, y);
	newPoint->next = current->next;
	current->next = newPoint;
}

// Author: 112-Maskin-Danil 
// This function moves to the next point in the list; 
// Takes the current point and returns the next point. 
Point* move_to_next(Point* current) {
	return current ? current->next : NULL;
}

// Author: 112-Maskin-Danil 
// This function checks if the polygon formed by the points is convex; 
// Takes the head of the linked list of points and returns 1 if convex, 0 otherwise. 
int isConvex(Point* head) {
	Point* p1, * p2, * p3;
	int sign;

	sign = 0;
	p1 = head;
	p2 = move_to_next(p1);
	p3 = move_to_next(p2);

	while (p3 != head) {
		int crossProduct = (p2->x - p1->x) * (p3->y - p2->y) - (p2->y - p1->y) * (p3->x - p2->x);

		if (crossProduct != 0) {
			if (sign == 0) {
				sign = (crossProduct > 0) ? 1 : -1;
			}
			else if ((crossProduct > 0 && sign < 0) || (crossProduct < 0 && sign > 0)) {
				return 0;
			}
		}

		p1 = p2;
		p2 = p3;
		p3 = move_to_next(p3);
	}

	return 1;
}

// Author: 112-Maskin-Danil 
// This function frees the memory allocated for the linked list of points; 
// Takes the head of the list. 
void freeList(Point* head) {
	Point* current = head;
	Point* next;

	do {
		next = current->next;
		free(current);
		current = next;
	} while (current != head);
}


// Author: 112-Maskin-Danil.
// This function returns the absolute value of a number v.
double absvalue(double v) {
	return v > 0 ? v : -v;
}

// Author: 112-Maskin-Danil 
// This function checks the location of a point relative to the polygon
// Takes the head of the linked list of points, coordinates x and y
// Returns "inside", "on the boundary" or "outside.
const char* pointLocation(Point* head, double px, double py) {
	int count = 0;
	Point* current = head;

	if (absvalue(current->x - px) < eps && absvalue(current->y - py) < eps) {
		return "at the vertex";
	}
	do {
		Point* next = current->next;
		if ((current->y > py) != (next->y > py)) {
			double intersectionX = (double)(next->x - current->x) * (py - current->y) / (next->y - current->y) + current->x;
			if (absvalue(px - intersectionX) < eps) {
				return "on the boundary";
			}
			if (px < intersectionX) {
				count++;
			}
		}
		current = next;
	} while (current != head);

	return (count % 2 == 1) ? "inside" : "outside";
}
