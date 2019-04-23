#include <stdio.h>

void arrayShiftRight(int array[], int size) {
    int last = size - 1;
    int temp = array[last];
    
    for ( int i = last; i > 0; i-- ) {
        array[i] = array[i-1];
    }
    array[0] = temp;
}

int main() {
    int size = 5;
    int array[] = {1, 2 , 3, 4, 5};

    arrayShiftRight(array,size);
    return 0;
}
