#include <stdio.h>

int scanLen(FILE *in) {
    int len;
    
    fscanf(in, "%d", &len);
    return len;
}

void merge(int array[], int lo, int mid, int hi) {
    int len = hi - lo;
    int i = lo;
    int j = mid;
    int index = 0;
    int tmp[len];
    
    for ( ; i < mid && j < hi; index++ ) {
        if ( array[i] < array[j] ) {
            tmp[index] = array[i];
            i += 1;
        } else {
            tmp[index] = array[j];
            j += 1;
        }
    }
    
    for ( ; i < mid; i++, index++ ) {
        tmp[index] = array[i];
    }
    for ( ; j < hi; j++, index++ ) {
        tmp[index] = array[j];
    }
    
    for ( int k = lo, m = 0; k < hi && m < len; k++, m++ ) {
        array[k] = tmp[m];
    }
}

void mergeSort(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;
    
    if ( mid > lo ) {
        mergeSort(array, lo, mid);
        mergeSort(array, mid, hi);
        merge(array, lo, mid, hi);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = scanLen(in);
    int array[len];
    int last = len - 1;
    
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
    
    mergeSort(array, 0, len);
    
    for (int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
    fclose(in);
    fclose(out);
    
    return 0;
}
