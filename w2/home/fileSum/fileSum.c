#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int a,b;
    
    fscanf(in, "%d %d", &a, &b);
    fprintf(out, "%d\n", a+b);

    return 0;
}
