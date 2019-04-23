#include <stdio.h>

int main() {
    int length, tmp;
    
    scanf("%d", &length);
    
    for ( int i = 0; i < length; i++ ) {
        scanf("%d", &tmp);
        printf("%d\n", tmp^42);
    }
    
    return 0;
}
