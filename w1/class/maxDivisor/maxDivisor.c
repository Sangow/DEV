#include <stdio.h>

int main() {
    int a;
    int b = 0;
    
    scanf("%d", &a);
    
    for ( int i = a / 2; i >= 2; i-- ) {
        if ( a % i == 0 ) {
            b = a / i;
        }
    }
    printf("%d\n", b);
    
    return 0;
}
