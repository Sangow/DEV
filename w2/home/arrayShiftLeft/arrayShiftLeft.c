#include <stdio.h>

void arrayShiftLeft(int array[], int size) {
    int tmp = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        array[i-1] = array[i];
    }
    array[size-1] = tmp;
}


int main() {
    int array[] = {1, 2, 3 ,4, 5};
    int size = sizeof(array)/4;

    arrayShiftLeft(array, size);

    return 0;
}
