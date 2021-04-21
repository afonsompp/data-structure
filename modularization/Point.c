#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "Point.h"

struct point
{
	float x;
	float y;
};

Point *p_create(float x, float y)
{
	Point *p = malloc(sizeof(Point));

	if (p != NULL)
	{
		p->x = x;
		p->y = y;
	}

	return p;
}

void p_get(Point *p, float *x, float *y)
{
	*x = p->x;
	*y = p->y;
}

void p_add(Point *p, float x, float y)
{
	p->x = x;
	p->y = y;
}

float p_distance(Point *p1, Point *p2)
{
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;

	return sqrt((dx * dx) + (dy * dy));
}

void p_free(Point *p)
{
	free(p);
}
