#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Vector;

void vectorIncrement(Vector *this, Vector other) {
    this->x += other.x;
    this->y += other.y;
}

void vectorDecrement(Vector *this, Vector other) {
    this->x -= other.x;
    this->y -= other.y;
}

int vectorEqual(Vector a, Vector b) {
    return a.x == b.x && a.y == b.y;
}

Vector vectorSum(Vector a, Vector b) {
    Vector sum = a;

    vectorIncrement(&sum, b);
    return sum;
}

Vector vectorDiff(Vector a, Vector b) {
    Vector diff = a;

    vectorDecrement(&diff, b);
    return diff;
}

double vectorLen(Vector this) {
    return hypot(this.x, this.y);
}

void vectorPrint(Vector this) {
    printf("(%g, %g)", this.x, this.y);
}

int main() {
    Vector v1 = {9,9};
    Vector v2 = {1,1};

    vectorPrint(v1);
    vectorIncrement(&v1,v2);
    vectorPrint(v1);
    vectorPrint(vectorDiff(v1,v2));

    return 0;
}