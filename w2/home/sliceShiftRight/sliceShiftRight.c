#include <stdio.h>

void sliceShiftRight(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[end];
        
        for ( int i = end; i > start; i-- ) {
            array[i] = array[i-1];
        }
        array[start] = temp;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    sliceShiftRight(array, 3, 10);

    for ( int i = 0; i < 15; i++ ) {
        printf("%d ", array[i]);
    }

    return 0;
}
