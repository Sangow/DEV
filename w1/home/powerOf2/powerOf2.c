#include <stdio.h>

int main() {
    int power;
    int counter = 1;
    
    scanf("%d", &power);
    
    for ( int i = 0; i < power; i++ ) {
        printf("%d ", counter);
        counter *= 2;
    }
    printf("%d\n", counter);
    
    return 0;
}
