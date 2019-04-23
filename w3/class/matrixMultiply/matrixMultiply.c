#include <stdio.h>

#define SIZE 3

void matrixMultiply(int matrix[SIZE][SIZE], int size, int multiplier) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[i][j] *= multiplier;
        }
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

void matrixPrint(int matrix[SIZE][SIZE]) {
    int limit = SIZE - 1;

    for ( int i = 0; i < SIZE; i++ ) {
        for ( int j = 0; j < limit; j++ ) {
            printf("%d\t", matrix[i][j]);
        }
        printf("%d\n", matrix[i][limit]);
    }
}

int main() {
    int matrix[SIZE][SIZE];

    matrixFill(matrix, SIZE);
    matrixPrint(matrix);
    printf("---------------------------\n");
    matrixMultiply(matrix, SIZE, 2);
    matrixPrint(matrix);

    return 0;
}