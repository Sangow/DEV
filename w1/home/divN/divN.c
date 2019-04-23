#include <stdio.h>

int main() {
    int min, max;
    int divisor;
    int rest;
    
    scanf("%d %d %d", &min, &max, &divisor);
    rest = min % divisor;
    if ( rest > 0 ) {
        min += divisor;
    }
    min -= rest;
    
    for ( int i = min; i <= max; i += divisor ) {
        printf("%d\n", i);
    }
    
    return 0;
}
