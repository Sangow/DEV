#include <stdio.h>

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != '\0'; len++ );
    return len;
}

int main() {
    char str[] = "Hello";

    printf("%d\n", strLen(str));

    return 0;
}
