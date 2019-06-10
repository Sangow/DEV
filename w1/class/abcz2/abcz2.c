#include <stdio.h>

int main() {
    int value;
    int isZulu = 1;
    
    scanf("%d", &value);
    
    if ( value % 2 == 0 ) {
        printf("alpha\n");
        isZulu = 0;
    }
    if ( value % 3 == 0 ) {
        printf("bravo\n");
        isZulu = 0;
    }
    if ( value % 5 == 0 ) {
        printf("charlie\n");
        isZulu = 0;
    }
    if ( isZulu ) {
        printf("zulu\n");
    }
    
    return 0;
}
