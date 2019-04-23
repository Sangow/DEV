#include <stdio.h>

void arrayAbs(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
}

int main() {
    int size = 5;
    int array[] = {-1, 2, -200, 200, 9};

    arrayAbs(array,size);

    return 0;
}
