#include <stdio.h>

#define STEP 5

int main() {
    int min, max;
    int rest;
    
    scanf("%d %d", &min, &max);
    rest = min % STEP;
    
    if ( rest > 0 ) {
        min += STEP;
    }
    min -= rest;
    for ( int i = min; i <= max; i += STEP ) {
        printf("%d\n", i);
    }
    
    return 0;
}
