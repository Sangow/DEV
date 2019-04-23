#include <stdio.h>

void sliceShiftLeft(int array[], int start, int end) {
    if ( start < end ) {
        int temp = array[start];
        
        for ( int i = start; i < end; i++ ) {
            array[i] = array[i+1];
        }
        array[end] = temp;
    }
}


int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    sliceShiftLeft(array, 3, 10);

    for (int i = 0; i < 15; i++) {
    printf("%d ", array[i]);
    }

    return 0;
}
