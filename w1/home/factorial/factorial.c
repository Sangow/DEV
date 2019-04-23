#include <stdio.h>

int main() {
    int fact;
    int result = 1;
    
    scanf("%d", &fact);
    
    if ( fact < 0 ) {
        printf("-1\n");
    } else {
        for ( int i = 2; i <= fact; i++ ) {
            result *= i;
        }
        printf("%d\n", result);
    }
    
    return 0;
}
