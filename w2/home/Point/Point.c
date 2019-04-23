#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

void pointPrint(Point a) {
    printf("(%g, %g)", a.x, a.y);
}

int pointEqual(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

double pointDistance(Point a, Point b) {
    return hypot(a.x-b.x, a.y-b.y);
}

int main() {
    Point t1 = {3, 3};
    Point t2 = {9, 9};
    pointPrint(t1);
    printf("%g", pointDistance(t1,t2));

    return 0;
}