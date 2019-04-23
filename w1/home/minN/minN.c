#include <stdio.h>

int main() {
    int amount, counter, min;
    
    scanf("%d %d", &amount, &min);
    
    for ( int i = 1; i < amount; i++ ) {
        scanf("%d", &counter);
        if ( min > counter ) {
            min = counter;
        }
    }
    printf("%d\n", min);
    
    return 0;
}
