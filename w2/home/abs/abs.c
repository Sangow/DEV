#include <stdio.h>

void arrayScanAndPrint(FILE *in, FILE *out, int size) {
    int array[size];
    int last = size - 1;
    
    for ( int i = 0; fscanf(in, "%d", &array[i]) != EOF; i++ ) {
        if ( array[i] < 0 ) {
            array[i] *= -1;
        }
    }
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int length;
    
    fscanf(in, "%d", &length);
    arrayScanAndPrint(in, out, length);
    fclose(in);
    fclose(out);
    
    return 0;
}
