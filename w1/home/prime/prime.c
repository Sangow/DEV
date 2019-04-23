#include stdio.h

int isPrime(int x) {
    if ( x == 2 ) {
        return 1;
    }
    if ( x  2 ) {
        return 0;
    }
    for ( int i = 2; i  i = x; i++ ) {
        if ( x % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, j;
    int prime = 2;
    
    scanf(%d, &n);
    
    if ( n  1 ) {
        j = -1;
    } else {
        for ( int i = 1; i = n; i++ ) {
            for ( j = prime; isPrime(j) == 0; j++ ) {
                prime = j + 1;
            }
            prime += 1;
        }
    }
    printf(%dn, j);
    
    return 0;
}
