#include <stdio.h>

// int fibonacci(int n) {
//     if ( n == 0 ) {
//         return 0;
//     }
//     if ( n == 1 ) {
//         return 1;
//     }
//     if ( n > 1 ) {
//         return fibonacci(n-2) + fibonacci(n-1);
//     } else {
//         return fibonacci(n+2) - fibonacci(n+1);
//     }
// }

int main() {
    int num, result;
    int x = 1, y = 1;
    
    scanf("%d", &num);

    if ( num < 0 ) {
        num *= -1;
    }
    
    if ( num == 0 ) {
        printf("0\n");
    } else if ( num == -1 || num == 1) {
        printf("1\n");
    } else {
        for ( int i = 2; i < num; i++ ) {
            y = x + y;
            x = y - x;
        }
        printf("%d\n", y);
    }
    
    return 0;
}
