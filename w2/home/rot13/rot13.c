#include <stdio.h>

#define MAX_SIZE 101

void rot13(FILE *out, char str[]) {
    char cache = str[0];
    
    for ( int i = 0; str[i] != '\0'; i++, cache = str[i] ) {
        if ( cache > 64 && cache < 91 ) {
            if ( cache <= 77 ) {
                str[i] = cache + 13;
            } else {
                str[i] = cache - 13;
            }
        } else if ( cache > 96 && cache < 123 ) {
            if ( cache <= 109 ) {
                str[i] = cache + 13;
            } else {
                str[i] = cache - 13;
            }
        }
    }
    fprintf(out, "%s\n", str);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[MAX_SIZE];
    
    fscanf(in, "%100s", str);
    rot13(out, str);
    fclose(in);
    fclose(out);
    
    return 0;
}
