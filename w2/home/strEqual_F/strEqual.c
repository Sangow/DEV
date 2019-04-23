#include <stdio.h>

// 8 лишних иструкций
//---------------------------------------------//
// int strEqual(char str1[], char str2[]) {
//     for ( int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++ ) {
//         if ( str1[i] != str2[i] ) {
//             return 0;
//         }
//     }
//     return 1;
// }

// проверочный вариант
// ---------------------------------------------//
// int strEqual(char str1[], char str2[]) {
//     for ( ; *str1 == *str2 && *str1 != '\0'; str1++, str2++ ){
//         printf("%d %d\n", *str1, *str2);
//     }
//     printf("%d %d\n", *str1, *str2);
//     return *str2 == *str1;
// } 

// code works
// ---------------------------------------------//
// int strEqual(char str1[], char str2[]) {
//     for ( ; *str1 == *str2 && *str1 != '\0'; str1++, str2++ );
//     return *str1 == *str2;
// }

// almost win
// ---------------------------------------------//
int strEqual(char str1[], char str2[]) {
    for ( int i = 0; str1[i] == str2[i]; i++ ) {
        if ( str1[i] == 0 ) {
            return 1;
        }
    }
    return 0;
}


int main() {
    char str1[] = "abcdead";
    char str2[] = "abcdea";

    printf("%d\n", *str1);
    printf("%d\n", *str2);
    
    printf("%d\n", strEqual(str1,str2));

    return 0;
}
