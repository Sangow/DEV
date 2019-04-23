// #include <stdio.h>

// #define SIZE 101

// void charCount(FILE *out, char str[], int len) {
//     char cache = str[0];
//     int counter = 0;
    
//     for ( int i = 0; cache != '\0'; i++, cache = str[i] ) {
//         if ( cache > 64 && cache < 91 ) {
//             str[i] = cache + 32;
//         }
//     }
    
//     for ( int i = 97; i < 123; i++ ) {
//         for ( int j = 0; j < len; j++ ) {
//             if ( str[j] == i ) {
//                 counter += 1;
//             }
//         }
//         if ( counter != 0 ) {
//             fprintf(out, "%c %d\n", i, counter);
//             counter = 0;
//         }
//     }
// }

// int main() {
//     FILE *in = fopen("task.in", "r");
//     FILE *out = fopen("task.out", "w");
//     char str[SIZE];
//     int len = 0;
    
//     fscanf(in, "%100s", str);
//     for ( ; str[len] != '\0'; len++ );
//     charCount(out, str, len);
//     fclose(in);
//     fclose(out);
    
//     return 0;
// }

#include <stdio.h>

#define ABC 26

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char character;
    int array[ABC];

    for ( int i = 'a'; i <= 'z'; i++ ) {
        array[i-97] = 0;
    }

    for ( ; fscanf(in, "%c", &character) == 1; ) {
        for ( int i = 'a'; i <= 'z'; i++ ) {
            if ( character == i || character == i - 32 ) {
                array[i-97] += 1;
            }
        }
    }

    for ( int i = 'a'; i <= 'z'; i++ ) {
        if ( array[i-97] != 0 ) {
            fprintf(out, "%c %d\n", i, array[i-97]);
        }
    }
    fclose(in);
    fclose(out);

    return 0;
}
