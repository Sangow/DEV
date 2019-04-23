#include <stdio.h>

int main() {
    int min, max, multiple;
    
    scanf("%d %d", &min, &max);
    
    if ( min % 2 == 0 ) {
        min += 1;
    }
    if ( max % 2 == 0 ) {
        max -= 1;
    }
    
    for ( ; min < max; min += 2 ) {
        multiple = min * min * min;
        printf("%d ", multiple);
    }
    multiple = max * max * max;
    printf("%d\n", multiple);
    
    return 0;
}
