#include <stdio.h>

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

void main() {
    int array[] = {7, 1, 5, 7, 2, 3};
    int size = 6;

}