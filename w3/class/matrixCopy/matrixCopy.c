#include <stdio.h>

#define SIZE 3

void matrixCopy(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            target[i][j] = source[i][j];
        }
    }
}

void matrixPrint(int matrix[SIZE][SIZE], int size) {
    int limit = size - 1;

    for ( int i = 0; i < size; i++ ) {
        for (int j = 0; j < limit; j++ ) {
            printf("%d ", matrix[i][j]);
        }
        printf("%d\n", matrix[i][limit]);
    }
}

void matrixFill(int matrix[SIZE][SIZE], int size) {
    int counter = 1;

    for ( int i = 0; i < SIZE; i++ ) {
        for ( int j = 0; j < SIZE; j++ ) {
            matrix[i][j] = counter;
            counter += 1;
        }
    }
}

int main() {
    int size = SIZE;
    int source[size][size];
    int target[size][size];

    matrixFill(source, size);
    matrixPrint(source, size);
    printf("------------------------------\n");
    matrixCopy(target, source, size);
    matrixPrint(target, size);

    return 0;
}