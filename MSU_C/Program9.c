#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include "Functions8.h" 
#define eps 0.000001

double PPdistance(Point* p1, Point* p2);
double PEdistance(Point* p, Point* s, Point* e);
double polygonDistance(Point* poly1, Point* poly2);
Point* readPolygonFromFile(const char* filename);

// Author: 112-Maskin-Danil  
// This program reads the coordinates of the vertices of 2 polygons from files polygon1.txt and polygon2.txt. 
// Returns the minimum distance between them. 
int main(void) {
	Point* polygon1 = readPolygonFromFile("polygon1.txt");
	Point* polygon2 = readPolygonFromFile("polygon2.txt");

	printf("Author: 112-Maskin-Danil\n");
	printf("This program reads the coordinates of the vertices of 2 polygons from files polygon1.txt and polygon2.txt. \n");
	printf("Returns the minimum distance between them.\n");
	printf("Distance between polygons: %lf\n", polygonDistance(polygon1, polygon2));

	return 0;
}

// Author: 112-Maskin-Danil  
// This function calculates the distance between two points p1 and p2. 
// Returns the distance as a double. 
double PPdistance(Point* p1, Point* p2) {
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

// Author: 112-Maskin-Danil  
// This function calculates the minimum distance from a point p to a segment defined by s and e. 
// Returns the distance as a double. 
double PEdistance(Point* p, Point* s, Point* e) {
	double dx = e->x - s->x;
	double dy = e->y - s->y;
	double t;
	Point nearestPoint = { 0, 0, NULL };

	if (absvalue(dx - 0) < eps && absvalue(dy - 0) < eps) {
		return PPdistance(p, s);
	}
	t = ((p->x - s->x) * dx + (p->y - s->y) * dy) / (dx * dx + dy * dy);
	if (t < 0) {
		t = 0;
	}
	if (t > 1) {
		t = 1;
	}

	nearestPoint.x = s->x + t * dx;
	nearestPoint.y = s->y + t * dy;

	return PPdistance(p, &nearestPoint);
}

// Author: 112-Maskin-Danil  
// This function calculates the minimum distance between two polygons poly1 and poly2. 
// Returns the minimum distance as a double. 
double polygonDistance(Point* poly1, Point* poly2) {
	double minDistance = INFINITY;

	for (Point* p1 = poly1; p1 != NULL; p1 = move_to_next(p1)) {
		for (Point* p2 = poly2; p2 != NULL; p2 = move_to_next(p2)) {
			double dist = PPdistance(p1, p2);
			if (dist < minDistance) {
				minDistance = dist;
			}
		}
	}

	for (Point* p1 = poly1; p1 != NULL; p1 = move_to_next(p1)) {
		for (Point* s = poly2; s != NULL; s = move_to_next(s)) {
			Point* e = move_to_next(s);
			if (e != NULL) {
				double dist = PEdistance(p1, s, e);
				if (dist < minDistance) {
					minDistance = dist;
				}
			}
		}
	}

	for (Point* p2 = poly2; p2 != NULL; p2 = move_to_next(p2)) {
		for (Point* s = poly1; s != NULL; s = move_to_next(s)) {
			Point* e = move_to_next(s);
			if (e != NULL) {
				double dist = PEdistance(p2, s, e);
				if (dist < minDistance) {
					minDistance = dist;
				}
			}
		}
	}

	return minDistance;
}

// Author: 112-Maskin-Danil  
// This function reads the coordinates of the vertices of a polygon from a file. 
// Returns a pointer to the head of the linked list of points. 
Point* readPolygonFromFile(const char* filename) {
	Point* head = NULL;
	Point* tail = NULL;
	double x, y;
	FILE* file = fopen(filename, "r");

	if (!file) {
		fprintf(stderr, "file was not found");
		return NULL;
	}

	while (fscanf(file, "%lf %lf", &x, &y) == 2) {
		Point* newPoint = createPoint(x, y);
		if (!head) {
			head = newPoint;
			tail = newPoint;
		}
		else {
			tail->next = newPoint;
			tail = newPoint;
		}
	}

	fclose(file);
	return head;
}
