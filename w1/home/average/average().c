#include <stdio.h>

unsigned int average(unsigned int a, unsigned int b) {
    
    return (a / 2) + (b / 2);
}

int main() {
    unsigned int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d\n", average(a,b));
    
    return 0;
}
