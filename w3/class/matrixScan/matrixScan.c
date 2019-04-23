#include <stdio.h>

#define SIZE 3

void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int col = 0; col < size; col++ ) {
        for ( int row = 0; row < size; row++ ) {
            fscanf(in, "%d", &matrix[col][row]);
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

int main() {
    FILE *in = fopen("task.in", "r");
    int matrix[SIZE][SIZE];

    matrixScan(in, matrix, 3);
    matrixPrint(matrix, 3);



}