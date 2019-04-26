#include "array.h"

int scanArray (FILE *in, int array[], int limit) {
    int length = 0;

    for ( ; length < limit && fscanf(in, "%d", array[length]) == 1; length++ );
    return length;
}

void arrayReverse (int array[], int size) {
    for ( int lo = 0, hi = size - 1; lo < hi; lo++, hi-- ) {
        int buffer = array[lo];

        array[lo] = array[hi];
        array[hi] = buffer;
    }
}

void printArray(FILE *out, int array[], int size) {
    int last = size - 1;

    for (int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

