#include <stdio.h>

#define SIZE 3

void matrixPrint(FILE *out, int matrix[SIZE][SIZE], int size) {
    int limit = size - 1;
    
    for ( int col = 0; col < size; col++ ) {
        for ( int row = 0; row < limit; row++ ) {
            fprintf(out, "%d ", matrix[row][col]);
        }
        fprintf(out, "%d\n", matrix[limit][col]);
    }
}

// void matrixPrint(FILE *out, int matrix[SIZE][SIZE], int size) {
//     for ( int col = 0; col < size; col++ ) {
//         for ( int row = 0; row < size - 1; row++ ) {
//             fprintf(out, "%d ", matrix[row][col]);
//         }
//         fprintf(out, "%d\n", matrix[size-1][col]);
//     }
// }

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
    FILE *out = fopen("task.out", "w");
    int matrix[SIZE][SIZE];

    matrixFill(matrix, SIZE);
    matrixPrint(out, matrix, SIZE);

    return 0;

}