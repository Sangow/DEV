#include <stdio.h>

int main() {
    struct Test {
        char y;
        int z;
        double x;
        
    };
    
    printf("%d\n", sizeof(struct Test));

    return 0;
}