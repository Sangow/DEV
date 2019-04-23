#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b,a%b);
}

int main() {
    int min, max, m, n, lcm, rest;

    scanf("%d %d %d %d", &min, &max, &m, &n);
    lcm = m / gcd(m,n) * n;
    rest = min % lcm;
    if ( rest > 0 ) {
        min += lcm;
    }
    min -= rest;
    for ( int i = min; i <= max; i += lcm ) {
        printf("%d\n", i);
    }
}