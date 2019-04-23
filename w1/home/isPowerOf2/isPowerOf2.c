#include <stdio.h>

int main() {
    int a, i;
    
    scanf("%d", &a);
    for ( i = 1; i <= a / 2; i *= 2 );
    if ( i == a ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
