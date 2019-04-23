#include <stdio.h>

int main() {
    int last;
    
    scanf("%d", &last);
    
    if ( last % 2 != 0 ) {
        last -= 1;
    }
    
    for ( int i = 0; i < last; i += 2 ) {
        printf("%d ", i);
    }
    printf("%d\n", last);
    
    return 0;
}
