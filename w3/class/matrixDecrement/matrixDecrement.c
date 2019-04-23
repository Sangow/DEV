#include <stdio.h>

#define SIZE 3

void matrixDecrement(int matrix[SIZE][SIZE], int decrement[SIZE][SIZE], int size) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[i][j] -= decrement[i][j];
        }
    }
}


void matrixFill(int matrix[SIZE][SIZE]) {
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
    int decrement[SIZE][SIZE];

    matrixFill(matrix);
    matrixFill(decrement);
    printf("______matrix_____\n");
    matrixPrint(matrix);
    printf("_____decrement_____\n");
    matrixPrint(decrement);
    matrixDecrement(matrix, decrement,SIZE);
    printf("_____matrix decremented_____\n");
    matrixPrint(matrix);


}