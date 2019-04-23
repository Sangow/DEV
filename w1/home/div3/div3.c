#include <stdio.h>

#define DIVISOR 3

int main() {
    int min, max;
    int multiple;
    
    scanf("%d %d", &min, &max);
    multiple = min % DIVISOR;
    if ( multiple > 0 ) {
        min += DIVISOR;
    }
    min -= multiple;
    
    for ( int i = min; i <= max; i += DIVISOR ) {
        printf("%d\n", i);
    }
    
    return 0;
}
