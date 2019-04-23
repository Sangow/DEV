#include <stdio.h>

void insertSort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        for ( int j = i, prev = j - 1; j > 0 && array[j] < array[prev]; j--, prev-- ) {
            int temp = array[j];
            
            array[j] = array[prev];
            array[prev] = temp;
        }
    }
}

void main() {
    int array[] = {7, 2, 6, 1, 2};
    int size = 5;
}