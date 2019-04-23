#include <stdio.h>

int main() {
    char c;
    int zeros = 0;
    int exchanges = 0;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    for ( ; fscanf(in, "%c", &c) == 1; ) {
        if ( c == '0' ) {
            zeros += 1;
        }
    }
    fclose(in);
    in = fopen("task.in", "r");
    for ( int i = 0; i < zeros; i++ ) {
        fscanf(in, "%c", &c);
        if ( c != '0' ) {
            exchanges += 1;
        }
    }
    fclose(in);
    fprintf(out, "%d\n", exchanges);
    fclose(out);
    
    return 0;
}
