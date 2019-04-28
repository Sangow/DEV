#include <stdio.h>

void arraySort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] < array[i] ) {
                int temp = array[i];
                
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    int array[] = {5, 3, 100, 0, -10, 25};
    int size = sizeof(array) / 4;

    arraySort(array, size);

    for ( int i = 0; i < size; i++ ) {
        printf("%d ", array[i]);
    }

    return 0;
}
