#include <stdio.h>

int main() {
    int max;
    int divisor;
    
    scanf("%d %d", &max, &divisor);
    if ( divisor < 0 ) {
        divisor = -divisor;
    }
    
    max -= max % divisor;
    
    for ( int i = 0; i < max; i += divisor ) {
        printf("%d ", i);
    }
    printf("%d\n", max);
    
    return 0;
}
