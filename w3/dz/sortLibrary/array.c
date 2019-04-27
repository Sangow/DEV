#include "sortFuncs.h"

//=============BUBBLE SORT=============//
void bubbleSort(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        int limit = last - i;
        
        for ( int j = 0, next = j + 1; j < limit; j++, next++ ) {
            if ( array[j] > array[next] ) {
                int temp = array[j];
                
                array[j] = array[next];
                array[next] = temp;
            }
        }
    }
}
//=============INSERT SORT=============//
void insertSort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        for ( int j = i, prev = j - 1; j > 0 && array[j] < array[prev]; j--, prev-- ) {
            int temp = array[j];
            
            array[j] = array[prev];
            array[prev] = temp;
        }
    }
}
//=============MERGE SORT=============//
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
//=============QUICK SORT=============//
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
//=============SELECT SORT=============//
void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int min = i;
        
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] < array[min] ) {
                min = j;
            }
        }
        
        if ( min != i ) {
            int temp = array[min];
            
            array[min] = array[i];
            array[i] = temp;
        }
    }
}
