#include <stdio.h>

#include "array.h"

#define MAX_SIZE 100

int main() {
    FILE* in = fopen("task.in", "r");
    FILE* out = fopen("task.out", "w");
    int array[MAX_SIZE];
    int size;

    size = arrayScan(in, array, MAX_SIZE);
    fclose(in);

    arrayReverse (array, size);
    arrayPrint (out, array, size);
    fclose (out);

    return 0;
}