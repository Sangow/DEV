#include <stdio.h>

#define MAX_SIZE 101

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[MAX_SIZE];
    int len = 0;
    
    fscanf(in, "%101s", str);
    fclose(in);
    for ( ; str[len] != '\0'; len++ );
    fprintf(out, "%d\n", len);
    fclose(out);
    
    return 0;
}
