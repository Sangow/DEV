#include <stdio.h>

#define MAX_SIZE 100

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int num;
    int len = 0;

    for ( ; len < MAX_SIZE && fscanf(in, "%d", &num) == 1; len++ );

    fprintf(out, "%d\n", len);
    fclose(in);
    fclose(out);

    return 0;
}
