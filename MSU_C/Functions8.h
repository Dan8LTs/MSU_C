#pragma once
#include <stdio.h>

typedef struct Point {
	int x;
	int y;
	struct Point* next;
} Point;

Point* createPoint(int x, int y);
void insert_after(Point* current, int x, int y);
Point* move_to_next(Point* current);
int isConvex(Point* head);
void freeList(Point* head);
const char* pointLocation(Point* head, int px, int py);