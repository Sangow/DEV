#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int row = 1; row <= size; row++ ) {
        for ( int col = 1; col < size; col++ ) {
            printf("%d ", col);
        }
        printf("%d\n", size);
    }
    
    return 0;
}
