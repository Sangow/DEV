#include <stdio.h>

#define SIZE 200

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    long long maxJump, cell;
    long long array[SIZE];
    
    fscanf(in, "%lli %lli", &maxJump, &cell);
    
    for ( long long i = 0; i < maxJump; i++ ) {
        array[i] = 1 << i;
    }
    
    for ( long long i = maxJump, j = 0; i < cell; i++, j++ ) {
        array[i] = array[i-1];
        for ( long long k = i - 2; k >= j; k-- ) {
            array[i] += array[k];
        }
    }
    
    fprintf(out, "%lli\n", array[cell-1]);
    fclose(in);
    fclose(out);
    
    return 0;
}
