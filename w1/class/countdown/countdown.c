#include <stdio.h>

int main() {
    int counter;
    
    scanf("%d", &counter);
    
    for ( ; counter > 0; counter-- ) {
        printf("%d ", counter);
    }
    printf("0\n");
    
    return 0;
}
