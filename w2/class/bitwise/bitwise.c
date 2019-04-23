#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int a, b;
    
    fscanf(in, "%d %d", &a, &b);
    fclose(in);
    fprintf(out, "%d&%d=%d\n", a, b, a&b);
    fprintf(out, "%d|%d=%d\n", a, b, a|b);
    fprintf(out, "%d^%d=%d\n", a, b, a^b);
    fprintf(out, "%d<<%d=%d\n", a, b, a<<b);
    fprintf(out, "%d>>%d=%d\n", a, b, a>>b);
    fclose(out);
    return 0;
}
