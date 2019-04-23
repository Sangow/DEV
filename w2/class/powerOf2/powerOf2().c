#include <stdio.h>

int powerOf2(int exponent) {
    return 2 << exponent;
}

int main() {
    int num;
    scanf("%d", &num);
    printf("%d", powerOf2(num));
    return 0;
}
