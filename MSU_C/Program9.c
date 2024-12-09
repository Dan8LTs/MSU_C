#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include "Functions8.h" 

// Author: 112-Maskin-Danil  
// This function calculates the distance between two points p1 and p2. 
// Returns the distance as a double. 
double distance(Point* p1, Point* p2) {
    if (!p1 || !p2) {
        return INFINITY;
    }
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

// Author: 112-Maskin-Danil  
// This function calculates the minimum distance from a point p to a segment defined by segStart and segEnd. 
// Returns the distance as a double. 
double pointToSegmentDistance(Point* p, Point* segStart, Point* segEnd) {
    if (!p || !segStart || !segEnd) {
        return INFINITY;
    }

    double dx = segEnd->x - segStart->x;
    double dy = segEnd->y - segStart->y;

    if ((dx == 0) && (dy == 0)) {
        return distance(p, segStart);
    }

    double t = ((p->x - segStart->x) * dx + (p->y - segStart->y) * dy) / (dx * dx + dy * dy);

    t = fmax(0, fmin(1, t));

    double nearestX = segStart->x + t * dx;
    double nearestY = segStart->y + t * dy;
    Point nearestPoint = { nearestX, nearestY, NULL };

    return distance(p, &nearestPoint);
}

// Author: 112-Maskin-Danil  
// This function calculates the minimum distance between two polygons poly1 and poly2. 
// Returns the minimum distance as a double. 
double polygonDistance(Point* poly1, Point* poly2) {
    double minDistance = INFINITY;

    for (Point* p1 = poly1; p1 != NULL; p1 = move_to_next(p1)) {
        for (Point* p2 = poly2; p2 != NULL; p2 = move_to_next(p2)) {
            double dist = distance(p1, p2);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    for (Point* p1 = poly1; p1 != NULL; p1 = move_to_next(p1)) {
        for (Point* segStart = poly2; segStart != NULL; segStart = move_to_next(segStart)) {
            Point* segEnd = move_to_next(segStart);
            if (segEnd == NULL) {
                segEnd = poly2;
            }
            double dist = pointToSegmentDistance(p1, segStart, segEnd);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    for (Point* p2 = poly2; p2 != NULL; p2 = move_to_next(p2)) {
        for (Point* segStart = poly1; segStart != NULL; segStart = move_to_next(segStart)) {
            Point* segEnd = move_to_next(segStart);
            if (segEnd == NULL) {
                segEnd = poly1;
            }
            double dist = pointToSegmentDistance(p2, segStart, segEnd);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    return minDistance;
}

// Author: 112-Maskin-Danil  
// This function reads the coordinates of the vertices of a polygon from a file. 
// Returns a pointer to the head of the linked list of points. 
Point* readPolygonFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Can't open file");
        return NULL;
    }

    Point* head = NULL;
    Point* tail = NULL;

    double x, y;
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

// Author: 112-Maskin-Danil  
// This program reads the coordinates of the vertices of 2 polygons from files polygon1.txt and polygon2.txt. 
// Returns the minimum distance between them. 
int main() {
    const char* filename1 = "polygon1.txt";
    const char* filename2 = "polygon2.txt";

    Point* polygon1 = readPolygonFromFile(filename1);
    Point* polygon2 = readPolygonFromFile(filename2);
    double distanceBetweenPolygons = polygonDistance(polygon1, polygon2);

    printf("Distance between polygons: %lf\n", distanceBetweenPolygons);
    return 0;
}