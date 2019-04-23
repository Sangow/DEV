#include <stdio.h>

int main() {
    int a;
    int count = 1;
    
    scanf("%d", &a);
    
    if ( a < 0 ) {
        count += 1;
        a *= -1;
    }
    
    for ( ; a > 9; count++ ) {
        a /= 10;
    }
    
    printf("%d\n", count);
    return 0;
}
