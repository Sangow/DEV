#include <stdio.h>

int arrayMax(int array[], int size) {
    int max = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] > max ) {
            max = array[i];
        }
    }
    return max;
}

int main() {
    int size = 5;
    int array[] = {1, 200, 50, -100, 3};
    printf("%d\n", arrayMax(array, size));

    return 0;
}