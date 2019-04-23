#include <stdio.h>

int arrayMin(int array[], int size) {
    int min = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] < min ) {
            min = array[i];
        }
    }
    return min;
}

int main() {
    int size = 5;
    int array[] = {1, 200, 50, -100, 3};
    printf("%d\n", arrayMin(array, size));

    return 0;
}