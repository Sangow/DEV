#include <stdio.h>

int factorial(int n) {
    if ( n <= 1 ) {
        if ( n < 0 ) {
            return -1;
        }
        return 1;
    }
    return factorial(n-1) * n;
}



int main() {
    int number;

    scanf("%d", &number);
    
    printf("%d\n", factorial(number));
    
    return 0;
}
