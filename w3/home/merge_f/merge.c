#include <stdio.h>

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

void merge(int array[], int lo, int mid, int hi) {
    int len = hi - lo;
    int i = lo;
    int j = mid;
    int index = 0;
    int tmp[len];

    for (  ; i < mid && j < hi; index++ ) {
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
    arrayPrint(array,hi);

    if ( mid > lo ) {
        mergeSort(array, lo, mid);
        mergeSort(array, mid, hi);
        merge(array, lo, mid, hi);
    }
}

int main() {
    int array[] = {98, 42, 1, 23, 7, 81, 3, 34, 15};
    int size = 9;
    int lo = 0;
    int hi = size;
    // int mid = (hi + lo) / 2;

    // printf("lo = %d\nhi = %d\nmid = %d\n", lo, hi, mid);

    // arrayPrint(array, size);
    mergeSort(array, lo, hi);
    arrayPrint(array, size);

    return 0;
}