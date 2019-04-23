#include <stdio.h>

#define SIZE 3

void matrixRotate90(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0, cot = size - 1; col < size; col++, cot-- ) {
            target[col][row] = source[row][cot];
        }
    }
}

void matrixFill(int matrix[SIZE][SIZE]) {
    for ( int row = 0, counter = 1; row < SIZE; row++ ) {
        for ( int col = 0; col < SIZE; col++ ) {
                matrix[col][row] = counter;
                counter += 1;
        }
    }
}

void matrixFillZero(int matrix[SIZE][SIZE]) {
    for ( int row= 0; row < SIZE; row++ ) {
        for ( int col = 0; col < SIZE; col++ ) {
                matrix[col][row] = 0;
        }
    }
}

void matrixPrint(int matrix[SIZE][SIZE]) {
    int limit = SIZE - 1;

    for ( int row = 0; row < SIZE; row++ ) {
        for ( int col = 0; col < limit; col++ ) {
            printf("%d ", matrix[col][row]);
        }
        printf("%d\n", matrix[limit][row]);
    }
}

int main() {
    int source[SIZE][SIZE];
    int target[SIZE][SIZE];

    matrixFill(source);
    matrixFillZero(target);
    matrixRotate90(target, source, SIZE);
    matrixPrint(target);

    return 0;
}