#include <stdio.h>

int main() {
    int amount, time;
    
    scanf("%d %d", &amount, &time);
    
    for ( int i = 1; i <= time; i++ ) {
        amount *= 2;
        printf("%dh => %d amoeba(s)\n", i, amount);
    }
    
    return 0;
}
