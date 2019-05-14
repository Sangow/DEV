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

    fprintf(out, "arraySum()\n");
    fprintf(out,"Sum = %d\n\n", arraySum(array, size));
    
    fprintf(out, "arrayMax()\n");
    fprintf(out,"Max = %d\n\n", arrayMax(array, size));

    fprintf(out, "arrayMin()\n");
    fprintf(out,"Min = %d\n\n", arrayMin(array, size));

    fprintf(out, "arraySearch()\n");
    fprintf(out,"Index of needle number = %d\n\n", arraySearch(array, size, 98));

    fprintf(out, "arrayReverse()\n");
    arrayReverse(array, size);
    arrayPrint(out, array, size);
    fprintf(out, "\n");

    fprintf(out, "arrayExchange()\n");
    arrayExchange(array, size);
    arrayPrint(out, array, size);
    fprintf(out, "\n");

    fprintf(out, "selectSort()\n");
    selectSort(array, size);
    arrayPrint(out, array, size);
    fprintf(out, "\n");

    fprintf(out, "arrayUnique()\n");
    arrayPrint(out, array, arrayUnique(array, size));
    fprintf(out, "\n");
}