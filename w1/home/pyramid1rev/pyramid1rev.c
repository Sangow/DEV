#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = total; row > 0; row-- ) {
        for ( int col = 1; col < row; col++ ) {
            printf("%d ", col);
        }
        printf("%d\n", row);
    }
    
    return 0;
}
