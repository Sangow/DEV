#include <stdio.h>

int arrayUnique(int array[], int size) {
    // int newSize = size;

    // for ( int i = 0; i < newSize; i++ ) {
    //     for ( int j = i + 1; j < newSize; j++ ) {
    //         if ( array[j] == array[i] ) {
    //             for ( int k = i; k < newSize - 1; k++ ) {
    //                 array[k] = array[k+1];
    //             }
    //             printf("%d\n", newSize);
    //             newSize -= 1;
    //         }
    //     }
    // }

    // return newSize;


    // for ( int i = 0, j = i + 1; j < size; j++ ) {
    //     if ( array[i] == array[j] ) {
    //         for ( int k = i; k < size - 1; k++ ) {
    //             array[k] = array[k+1];
    //         }
    //         size -= 1;
    //         i += 1;
    //     }
    //     // i += 1;
    // }

//     return 0;

    // for ( int i = 0; i < newSize; i++ ) {
    //     for ( int j = newSize - 1; j > i; j-- ) {
    //         if ( array[j] == array[i] ) {
    //             int temp = array[j];

    //             array[j] = array[newSize-1];
    //             array[newSize-1] = temp;
    //             newSize -= 1;
    //         }
    //     }
    // }

    // return newSize;

    int index = 0;
    
    for ( int i = 1; i < size; i++ ) {
        int counter = 0;
        
        for ( int j = 0; j < i; j++ ) {
            if ( array[i] == array[j] ) {
                counter += 1;
            }
        }
        if ( counter == 0 ) {
            index += 1;
            array[index] = array[i];
        }
    }
    
    return index + 1;
}

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

void main() {
    int array[] = {0, 5, 8, 8, 5, 8, 4, 0};
    int size = 8;
    int length;

    arrayPrint(array, arrayUnique(array, size));
}