#include <stdio.h>

int intScan(FILE *in) {
    int value;
    
    fscanf(in, "%d", &value);
    return value;
}

int main() {
    FILE *in = fopen("task.in", "r");
    printf("%d\n", intScan(in));
    return 0;
}