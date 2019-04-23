#include <stdio.h>

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    
    if ( min < 0 ) {
        min -= min % 2;
    }
    if ( max < 0 ) {
        max += max % 2;
    }
    min += min % 2;
    max -= max % 2;
    
    for ( int i = min; i < max; i += 2 ) {
        printf("%d ", i*i);
    }
    printf("%d\n", max*max);
    
    return 0;
}
