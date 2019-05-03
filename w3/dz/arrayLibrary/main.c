#include <stdio.h>

#include "array.h"

#define MAX_SIZE 100

void main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[MAX_SIZE];
    int size = arrayScan(in, array, MAX_SIZE);

    fprintf(out, "arrayPrint()\n");
    arrayPrint(out, array, size);
    fprintf(out, "\n");

    fprintf(out, "arrayIncrement()\n");
    arrayIncrement(array, size, 2);
    arrayPrint(out, array, size);
    fprintf(out, "\n");

    fprintf(out, "arrayAbs()\n");
    arrayAbs(array, size);
    arrayPrint(out, array, size);
    fprintf(out, "\n");

    fprintf(out, "arrayShift()\n");
    arrayShift(array, size, 3);
    arrayPrint(out, array, size);
    fprintf(out, "\n");
}