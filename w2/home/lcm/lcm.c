#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int a, b, lcm;
    
    fscanf(in, "%d %d", &a, &b);
    
    lcm = a / gcd(a, b) * b ;
    fprintf(out, "%d\n", lcm);
    fclose(in);
    fclose(out);
    
    return 0;
}
