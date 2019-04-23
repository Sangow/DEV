#include <stdio.h>

int main() {
    int number;
    int sign = 1;
    
    scanf("%d", &number);
    
    if ( number % 2 == 0 ) {
        printf("alpha\n");
        sign = 0;
    }
    if ( number % 3 == 0 ) {
        printf("bravo\n");
        sign = 0;
    }
    if ( number % 5 == 0 ) {
        printf("charlie\n");
        sign = 0;
    }
    if ( sign ) {
        printf("zulu\n");
    }
    
    return 0;
}
