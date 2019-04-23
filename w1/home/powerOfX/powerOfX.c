#include <stdio.h>

int main() {
    int base, power;
    int counter = 1;
    
    scanf("%d %d", &base, &power);
    
    for ( int i = 0; i < power; i++ ) {
        printf("%d ", counter);
        counter *= base;
    }
    printf("%d\n", counter);
    return 0;
}
