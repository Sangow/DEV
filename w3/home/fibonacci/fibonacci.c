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

#include <stdio.h>

int main() {
    int num;
    int x = 1;
    int y = 1;
    
    scanf("%d", &num);
    
    if ( num == 0 ) {
        printf("0\n");
    } else if ( num == -1 || num == 1 ) {
        printf("1\n");
    } else if ( num > 1 ) {
        for ( int i = 2; i < num; i++ ) {
            y = x + y;
            x = y - x;
        }
        printf("%d\n", y);
    } else {
        for ( int i = num; i <= 0; i++ ) {
            y = x - y;
            x = x - y;
        }
        printf("%d\n", y);
    }
    
    return 0;
}
