#include <stdio.h>

int scanLen(FILE *in) {
    int len;
    fscanf(in, "%d", &len);
    return len;
}

void scanArray(FILE *in, int array[], int len) {
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d", array[i]);
    }
}

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

int partition(int array[], int start, int end) {
    int mid = (start + end) / 2;
    int pivot = array[mid];
    int tail = start;
    
    array[mid] = array[end];
    array[end] = pivot;
    
    for ( ; array[tail] < array[end]; tail++ );
    for ( int i = tail + 1; i < end; i++ ) {
        if ( array[i] < array[end] ) {
            pivot = array[tail];
            array[tail] = array[i];
            array[i] = pivot;
            tail += 1;
        }
    }
    
    pivot = array[tail];
    array[tail] = array[end];
    array[end] = pivot;
    
    return tail;
}

void main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = scanLen(in);
    int array[len];

    scanArray(in, array, len);
    

    printf("%d\n", partition(array, start, end));
    arrayPrint(array, 6);
}