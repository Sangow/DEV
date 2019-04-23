#include <stdio.h>

#define STEP 3

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


#include <stdio.h>

#define STEP 3

int main() {
    int max;
    
    scanf("%d", &max);
    
    max -= max % STEP;
    
    printf("0");
    for ( int i = STEP; i <= max; i += STEP ) {
        printf(" %d", i);
    }
    
    return 0;
}
