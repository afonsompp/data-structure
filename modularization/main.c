#include <stdio.h>
#include "Point.c"

int main()
{
	Point *p = p_create(10, 10);
	Point *q = p_create(20, 20);

	float d = p_distance(p, q);

	printf("A distancia entre P e Q é %f\n", d);

	p_free(p);
	p_free(q);

	return 0;
}
