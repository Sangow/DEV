#include <stdio.h>

void strLowerCase(char str[]) {
    char cache = str[0];

    for ( int i = 0; cache != '\0'; i++, cache = str[i] ){
        if ( cache > 64 && cache < 91 ){
            str[i] = cache + 32;
        }
    }
}

int main() {
    char str[] = "HeosavHHHDHSKHD!!...L";
    strLowerCase(str);
    printf("%s\n", str);

    return 0;
}