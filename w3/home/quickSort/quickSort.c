#include <stdio.h>

int scanLen(FILE *in) {
    int len;
    
    fscanf(in, "%d", &len);
    return len;
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

void quickSort(int array[], int start, int end) {
    int pivot;
    
    if ( end - start > 0 ) {
        pivot = partition(array, start, end);
        
        quickSort(array, start, pivot-1);
        quickSort(array, pivot+1, end);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = scanLen(in);
    int array[len];
    int start = 0;
    int end = len - 1;
    int last = len - 1;
    
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
    quickSort(array, start, end);
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
    fclose(in);
    fclose(out);
    
    return 0;
}
