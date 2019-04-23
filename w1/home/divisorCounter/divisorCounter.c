    printf("%d\n", divisor+1);
    printf("%d\n", divisor+1);
    printf("%d\n", divisor+1);
    printf("%d\n", divisor+1);
    printf("%d\n", divisor+1);
#include <stdio.h>

int main() {
    int dividend;
    int divisor = 1;
    
    scanf("%d", &dividend);
    
    for ( int i = 2; i <= dividend / 2; i++ ) {
        if ( dividend % i == 0 ) {
            divisor += 1;
        }
    }
    if( dividend != 1 ) {
        printf("%d\n", divisor+1);
    } else {
        printf("%d\n", divisor);
    }
    
    return 0;
}
