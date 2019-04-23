#include <stdio.h>

int main() {
    int size, start, end;
    
    scanf("%d", &size);
    
    end = size * size;
    start = end - size + 1;
    
    for ( int row = 1; row <= size; row++ ) {
        for ( int row = 1; row < size; row++ ) {
            printf("%d ", start);
            start += 1;
        }
        printf("%d\n", end);
        end -= size;
        start = end - size + 1;
    }
    
    return 0;
}
