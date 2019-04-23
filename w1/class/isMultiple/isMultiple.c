#include <stdio.h>

int main() {
    int number, divisor;
    
    scanf("%d %d", &number, &divisor);
    
    if ( number % divisor == 0 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
