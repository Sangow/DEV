#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 1; row <= total; row++ ) {
        for ( int col = 1; col < total; col++) {
            printf("%d ", col);
        }
        printf("%d\n", total);
    }
    
    return 0;
}
