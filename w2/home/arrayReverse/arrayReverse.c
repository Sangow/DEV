#include <stdio.h>

void arrayReverse(int array[], int size) {
    for ( int low = 0, high = size - 1; low < high; low++, high-- ) {
        int buffer = array[low];

        array[low] = array[high];
        array[high] = buffer;
    }
} //code works

void arrayReverse(int array[], int size) {
    for ( int lo = 0, hi = size - 1; lo < hi; lo++, hi-- ) {
        int buffer = array[lo];
        
        array[lo] = array[hi];
        array[hi] = buffer;
    }
} //epic


int main() {
    int size = 5;
    int array[] = {1, 2, 3, 4, 5};
    arrayReverse(array,size);
    return 0;
}