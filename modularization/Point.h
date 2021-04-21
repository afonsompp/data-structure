typedef struct point Point;

Point *p_create(float x, float y);

void p_free(Point *p);

void p_get(Point *p, float *x, float *y);

void p_add(Point *p, float x, float y);

float p_distance(Point *p1, Point *p2);
