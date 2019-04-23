#include <stdio.h>

#define MAX_SIZE 101

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[MAX_SIZE];
    int len = 0;
    
    fscanf(in, "%100s", str);
    fclose(in);
    for ( ; str[len] != '\0'; len++ );
    for ( int lo = 0, hi = len - 1; lo < hi; lo++, hi-- ) {
        char temp = str[lo];
        
        str[lo] = str[hi];
        str[hi] = temp;
    }
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}
