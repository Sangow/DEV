// #include <stdio.h>

// int isPrime(int n) {
//     if ( n < 0 ) {
//         n *= -1;
//     }
//     if ( n == 2 || n == 3 ) {
//         return 1;
//     } else if ( n > 2 && n % 2 != 0 && n % 3 != 0 ) {
//         return 1;
//     }
    
//     return 0;
// }

// int main() {
//     int prime;
    
//     scanf("%d", &prime);
    
//     if (isPrime(prime)) {
//         printf("yes\n");
//     } else {
//         printf("no\n");
//     }
//     return 0;
// }

int isPrime(int x) {
    if ( x == 2 ) {
        return 1;
    }
    
    if ( x < 2 ) {
        return 0;
    }
    
    for ( int i = 2; i * i <= x; i++ ) {
        if ( x % i == 0 ) {
            return 0;
        }
    }
    
    return 1;
}
