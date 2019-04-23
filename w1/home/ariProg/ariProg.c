#include <stdio.h>

int main() {
    int first, step, amount;
    
    scanf("%d %d %d", &first, &step, &amount);
    
    for ( int i = 1; i < amount; i++ ) {
        printf("%d ", first);
        first += step;
    }
    printf("%d\n", first);
    
    return 0;
}
