#include <stdio.h>

int main() {
    int pass;
    int flag = 1;
    
    for ( int i = 0; i < 5; i++ ) {
        scanf("%d", &pass);
        if ( pass == 1488 ) {
            printf("accepted\n");
            // flag = 0;
            return 0;
        } else {
            printf("incorrect password\n");
        }
    }
    if ( flag ) {
        printf("denied\n");
    }
    
    return 0;
}
