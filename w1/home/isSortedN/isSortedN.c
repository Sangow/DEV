#include <stdio.h>

int main() {
    int length, num, count;
    int flag = 0;
    
    scanf("%d %d", &length, &num);
    
    for ( int i = 1; i < length; i++ ) {
        scanf("%d", &count);
        if ( num > count ) {
            flag = 1;
        }
        num = count;
    }
    
    if ( flag ) {
        printf("no\n");
    } else {
        printf("yes\n");
    }
    
    return 0;
}
