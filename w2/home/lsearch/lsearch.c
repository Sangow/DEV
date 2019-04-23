#include <stdio.h>

#define MAX_SIZE 100

int arrayScan(FILE *in, int array[], int limit) {
    int len = 0;
    
    for ( ; len < limit && fscanf(in, "%d", &array[len]) == 1; len++ );
    return len;
}

void searchNeedle(FILE *out, int array[], int size, int needle) {
    int flag = 1;

    for ( int i = 0; i < size; i++ ) {
        if ( array[i] == needle ) {
            fprintf(out, "%d\n", i);
            flag = 0;
        }
    }
    if ( flag ) {
        fprintf(out, "-1\n");
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[MAX_SIZE];
    int needle;
    int size;
    
    fscanf(in, "%d", &needle);
    size = arrayScan(in, array, MAX_SIZE);
    fclose(in);
    searchNeedle(out, array, size, needle);
    fclose(out);
    
    return 0;
}
