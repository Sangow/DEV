#include <stdio.h>

int main() {
    int amount, count, max;
    
    scanf("%d %d", &amount, &max);
    
    for ( int i = 1; i < amount; i++ ) {
        scanf("%d", &count);
        if ( max < count ) {
            max = count;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
