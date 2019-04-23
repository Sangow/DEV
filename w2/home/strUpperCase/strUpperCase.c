#include <stdio.h>

void strUpperCase(char str[]) {
    char cache = str[0];
    
    for ( int i = 0; cache != '\0'; i++, cache = str[i] ) {
        if ( cache > 96 && cache < 123 ) {
            str[i] = cache - 32;
        }
    }
}

int main() {
    char str[] = "HeLoooUUUU!!!opP{}.";
    strUpperCase(str);
    printf("%s\n", str);

    return 0;
}