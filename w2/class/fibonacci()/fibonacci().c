#include <stdio.h>

int fibonacci(int n) {
    if ( n == 0 ) {
        return 0;
    }
    if ( n == 1 ) {
        return 1;
    }
    if ( n > 1 ) {
        return fibonacci(n-2) + fibonacci(n-1);
    } else {
        return fibonacci(n+2) - fibonacci(n+1);
    }
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d",fibonacci(a));

    return 0;
}
