// #include <stdio.h>

// #define MAX_SIZE 101

// void strEqual(FILE *out, char str1[], char str2[]) {
//     for ( ; *str1 == *str2 && *str1 != '\0'; str1++, str2++ );
//     if ( *str1 == *str2 ) {
//         fprintf(out, "yes\n");
//     } else {
//         fprintf(out, "no\n");
//     }
// }

// int main() {
//     FILE *in = fopen("task.in", "r");
//     FILE *out = fopen("task.out", "w");
//     char str1[MAX_SIZE];
//     char str2[MAX_SIZE];
    
//     fscanf(in, "%101s%101s", str1, str2);
//     fclose(in);
//     strEqual(out, str1, str2);
//     fclose(out);
    
//     return 0;
// }

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    
    fscanf(in, "%101s%101s", str1, str2);
    fclose(in);
    strEqual(out, str1, str2);
    fclose(out);
    
    return 0;
}