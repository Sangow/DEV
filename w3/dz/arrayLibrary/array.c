#include "array.h"

int arrayScan(FILE* in, int array[], int limit) {
    int len = 0;
    
    for ( ; len < limit && fscanf(in, "%d", &array[len]) == 1; len++ );
    return len;
}

void arrayPrint(FILE* out, int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

void arrayZeroFill(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        array[i] = 0;
    }
}

void arrayIncrement(int array[], int size, int increment) {
    for ( int i = 0; i < size; i++ ) {
        array[i] += increment;
    }
}

void arrayAbs(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
}

void arrayCopy(int destination[], int source[], int size) {
    for ( int i = 0; i < size; i++ ) {
        destination[i] = source[i];
    }
}

int arraySum(int array[], int size) {
    int sum = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        sum += array[i];
    }
    return sum;
}

int arrayMax(int array[], int size) {
    int max = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] > max ) {
            max = array[i];
        }
    }
    return max;
}

int arrayMin(int array[], int size) {
    int min = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] < min ) {
            min = array[i];
        }
    }
    return min;
}

int arraySearch(int array[], int size, int needle) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] == needle ) {
            return i;
        }
    }
    return -1;
}

void arrayReverse(int array[], int size) {
    for ( int lo = 0, hi = size - 1; lo < hi; lo++, hi-- ) {
        int buffer = array[lo];
        
        array[lo] = array[hi];
        array[hi] = buffer;
    }
}

void arrayShift(int array[], int size, int shift) {
    if ( shift < 0 ) {
        int sh = shift % size * (-1);
        int temp[sh];

        for ( int j = 0, i = 0; j < sh; i++, j++ ) {
            temp[j] = array[i];
        }

        for ( int i = 0, j = size - sh - 1; j < size; i++, j++ ) {
            array[i] = array[j];
        }

        for ( int i = 0, j = size - sh; j < size; i++, j++ ) {
            array[j] = temp[i];
        }

    } else {
        int sh = shift % size;
        int temp[sh];

        for ( int i = 0, lim = size - sh; i < sh ; i++, lim++ ) {
            temp[i] = array[lim];
        }

        for ( int i = size - 1, j = i - sh; i >= sh; i--, j-- ) {
            array[i] = array[j];
        }

        for ( int i = 0; i < sh; i++ ) {
            array[i] = temp[i];
        }
    }
}

void arrayExchange(int array[], int len) {
    for ( int i = 0, size = len - len % 2; i < size; i += 2 ) {
        int tmp = array[i];
        
        array[i] = array[i+1];
        array[i+1] = tmp;
    }
}

int arrayUnique(int array[], int size) {
    int index = 0;
    
    for ( int i = 1; i < size; i++ ) {
        int counter = 0;
        
        for ( int j = 0; j < i; j++ ) {
            if ( array[i] == array[j] ) {
                counter += 1;
            }
        }
        if ( counter == 0 ) {
            index += 1;
            array[index] = array[i];
        }
    }
    
    return index + 1;
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

void insertSort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        for ( int j = i, prev = j - 1; j > 0 && array[j] < array[prev]; j--, prev-- ) {
            int temp = array[j];
            
            array[j] = array[prev];
            array[prev] = temp;
        }
    }
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