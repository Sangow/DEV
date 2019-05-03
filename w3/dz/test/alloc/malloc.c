#include <stdio.h>
#include <stdlib.h>

void main() {
    int* int10 = (int*)malloc(sizeof(int)*10);

    if ( int10 != NULL ) {
        printf("Evrthng OK!\n");
    }
    
    for ( int i = 0; i < 10; i++ ) {
        int10[i] = i;
    }

    for ( int i = 0; i < 9; i++ ) {
        printf("%d ", int10[i]);
    }
    printf("%d\n", int10[9]);
}