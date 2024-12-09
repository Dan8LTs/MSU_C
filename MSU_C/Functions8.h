#pragma once
#include <stdio.h>

typedef struct Point {
	double x;
	double y;
	struct Point* next;
} Point;

Point* createPoint(double x, double y);
void insert_after(Point* current, double x, double y);
Point* move_to_next(Point* current);
int isConvex(Point* head);
void freeList(Point* head);
const char* pointLocation(Point* head, double px, double py);
double absvalue(double v);