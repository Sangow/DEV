#include <stdio.h>

int main() {
    int a, b, c, d, e;
    int max;
    
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    max = a;
    if ( max < b ) {
        max = b;
    }
    if ( max < c ) {
        max = c;
    }
    if ( max < d ) {
        max = d;
    }
    if ( max < e ) {
        max = e;
    }
    
    printf("%d\n", max);
    
    return 0;
}
