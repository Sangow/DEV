// #include <stdio.h>

// int main() {
//     int divident, divisor;
//     int rest;
    
//     scanf("%d %d", &divident, &divisor);
    
//     if ( divisor < 0 ) {
//         divisor *= -1;
//     }
    
//     rest = divident % divisor;
    
//     if ( rest > 0 ) {
//         divident -= rest;
//     } else {
//         divident -= divisor + rest;
//     }
    
//     printf("%d\n", divident);
    
//     return 0;
// }


// #include <stdio.h>

// int main() {
//     int dividend, divisor;
//     int prevMultiple;
    
//     scanf("%d %d", &dividend, &divisor);
    
//     if ( divisor < 0 ) {
//         divisor *= -1;
//     }
    
//     prevMultiple = dividend - dividend % divisor;
    
//     if ( prevMultiple >= dividend ) {
//         prevMultiple -= divisor;
//     }
    
//     printf("%d\n", prevMultiple);
    
//     return 0;
// }


#include <stdio.h>

int main() {
    int dividend, divisor, prevMultiple;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor *= -1;
    }
    prevMultiple = dividend - dividend % divisor;
    
    if ( prevMultiple > dividend ) {
        prevMultiple -= divisor;
    }
    
    printf("%d\n", prevMultiple);
    
    return 0;
}
