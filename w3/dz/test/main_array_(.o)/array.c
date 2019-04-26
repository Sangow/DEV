#include "array.h"

int arrayScan(FILE* in, int array[], int limit) {
    int len = 0;

    for ( ; len < limit && fscanf(in, "%d", &array[len]) == 1; len++ );
    return len;
}

void arrayReverse(int array[], int size) {
    for ( int lo = 0, hi = size - 1; lo < hi; lo++, hi-- ) {
        int buffer = array[lo];

        array[lo] = array[hi];
        array[hi] = buffer;
    }
}

void arrayPrint(FILE* out, int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}