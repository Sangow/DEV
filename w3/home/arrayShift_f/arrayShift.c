#include <stdio.h>

void arrayShift(int array[], int size, int shift) {
    if ( shift < 0 ) {
        int sh = shift % size * (-1);
        int temp[sh];

        for ( int j = 0, i = 0; j < sh; i++, j++ ) {
            temp[j] = array[i];
        }

        for ( int i = 0, j = size - sh - 1; j < size; i++, j++ ) {
            array[i] = array[j];
        }

        for ( int i = 0, j = size - sh; j < size; i++, j++ ) {
            array[j] = temp[i];
        }

    } else {
        int sh = shift % size;
        int temp[sh];

        for ( int i = 0, lim = size - sh; i < sh ; i++, lim++ ) {
            temp[i] = array[lim];
        }

        for ( int i = size - 1, j = i - sh; i >= sh; i--, j-- ) {
            array[i] = array[j];
        }

        for ( int i = 0; i < sh; i++ ) {
            array[i] = temp[i];
        }
    }
}

void arrayPrint(int array[], int size) {
    int lim = size - 1;

    for ( int i = 0; i < lim; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[lim]);
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = 6;

    arrayShift(array, size, -2);
    arrayPrint(array, size);


    return 0;
}

// #include <stdio.h>

// #define SIZE 13

// void arrayShift(int array[], int size, int shift) {
//     int buffersize = size / 2;
//     int temp[buffersize];
    
//     shift %= size;
//     if ( shift < 0 ) {
//         shift += size;
//     }
//     if ( shift <= buffersize ) {
//         for ( int i = size - shift, j = 0; i < size; i++, j++ ) {
//             temp[j] = array[i];
//         }
//         for ( int i = size - 1, j = size - 1 - shift; i >= shift; i--, j-- ) {
//             array[i] = array[j];
//         }
//         for ( int i = 0; i < shift; i++ ) {
//             array[i] = temp[i];
//         }
//     } else {
//         for ( int i = size - 1 - shift; i >= 0; i-- ) {
//             temp[i] = array[i];
//         }
//         for ( int i = 0, j = size - shift; i < shift; i++, j++ ) {
//             array[i] = array[j];
//         }
//         for ( int i = size - 1, j = size - 1 - shift; j >= 0; i--, j-- ) {
//             array[i] = temp[j];
//         }
//     }
// }

// int main() {
//     int array[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//     int shift;

//     for ( int i = 0; i < SIZE; i++ ) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     scanf("%d", &shift);
//     arrayShift(array, SIZE, shift);
//     for ( int i = 0; i < SIZE; i++ ) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     return 0;
// }