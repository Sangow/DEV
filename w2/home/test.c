#include <stdio.h>

int scann(FILE *in, int array[]) {
    for (int i = 0; i < 3; i++){
        array[i] = fscanf(in, "%d", "")
    }
}

int main() {
    FILE *in = fopen("txt.in", "r");
    int a, b;
    fscanf(in, "%d%d", &a, &b);
    // printf("%d %d\n", a, b);
    printf("%d\n", count);
}