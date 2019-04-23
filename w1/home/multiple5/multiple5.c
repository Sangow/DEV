#include <stdio.h>

#define STEP 5

int main() {
    int max;
    
    scanf("%d", &max);
    
    max -= max % STEP;
    
    for ( int i = 0; i < max; i += STEP ) {
        printf("%d ", i);
    }
    printf("%d\n", max);
    
    return 0;
}
