// #include <stdio.h>

// int main() {
//     int dividend, divisor, rest;
    
//     scanf("%d %d", &dividend, &divisor);
    
//     if ( divisor < 0 ) {
//         divisor = -divisor;
//     }
//     rest = dividend % divisor;
//     if ( rest > 0 ) {
//         dividend += divisor - rest;
//     } else {
//         dividend -= rest;
//     }
//     printf("%d\n", dividend);
    
//     return 0;
// }


// #include <stdio.h>

// int main() {
//     int dividend, divisor, nextMultiple;
    
//     scanf("%d %d", &dividend, &divisor);
    
//     if ( divisor < 0 ) {
//         divisor *= -1;
//     }
    
//     nextMultiple = dividend - dividend % divisor;
    
//     if ( nextMultiple <= dividend ) {
//         nextMultiple += divisor;
//     }
    
//     printf("%d\n", nextMultiple);
    
//     return 0;
// }


#include <stdio.h>

int main() {
    int dividend, divisor, nextMultiple;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor *= -1;
    }
    nextMultiple = dividend - dividend % divisor;

    printf("%d\n", nextMultiple);
    
    if ( nextMultiple < dividend ) {
        nextMultiple += divisor;
    }
    
    printf("%d\n", nextMultiple);
    
    return 0;
}
