#include <stdio.h>

int arrayScan(FILE *in, int array[], int limit) {
    int len = 0;
    
    for ( ; len < limit && fscanf(in, "%d", &array[len]) == 1; len++ );
    return len;
}


int main() {
    FILE *in = fopen("task.in", "r");
    int size = 10;
    int array[size];
    int limit = 5;
    printf("%d\n", arrayScan(in, array, limit));


    return 0;
}
