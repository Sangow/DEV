#include <stdio.h>

void strRot13(char str[]) {
    char cache = str[0];
    
    for ( int i = 0; str[i] != '\0'; i++, cache = str[i] ) {
        if ( cache > 64 && cache < 91 ) {
            if ( cache <= 77 ) {
                str[i] = cache + 13;
            } else {
                str[i] = cache - 13;
            }
        } else if ( cache > 96 && cache < 123 ) {
            if ( cache <= 109 ) {
                str[i] = cache + 13;
            } else {
                str[i] = cache - 13;
            }
        }
    }
}

int main() {
    char str[] = "balk.11.onyx..!!!.BAlk>OnyX.StyX";
    strRot13(str);
    printf("%s\n", str);
    return 0;
}
