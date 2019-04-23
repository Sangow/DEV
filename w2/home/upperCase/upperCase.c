#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( char symbol; fscanf(in, "%c", &symbol) != EOF; ) {
        if ( symbol > 96 && symbol < 123 ) {
            symbol -= 32;
        }
        fprintf(out, "%c", symbol);
    }
    fprintf(out, "\n");
    fclose(in);
    fclose(out);
    
    return 0;
}
