#include <stdio.h>

int main() {
    int num, base, maxPower;
    
    scanf("%d %d", &num, &base);
    
    for ( maxPower = 1; maxPower <= num / base; maxPower *= base );
    
    for ( ; maxPower >= base; num %= maxPower, maxPower /= base ) {
        printf("%d", num/maxPower);
    }
    printf("%d\n", num/maxPower);
    
    return 0;
}
