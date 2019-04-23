#include <stdio.h>

void strCopy(char target[], char source[]) {
    int last = 0;
    
    for ( ; source[last] != '\0'; last++ ) {
        target[last] = source[last];
    }
    target[last] = '\0';
}


int main() {
    char str1[] = "Hello";
    char str2[10];
    strCopy(str2, str1);

    printf("%s\n", str2);

    return 0;
}