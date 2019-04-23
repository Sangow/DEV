#include <stdio.h>

int increment2(int* a) {
    return *a += 1;
}

int main() {
    int a = 10;
    int b = 100;
    int* p = &a;
    
    printf("%d\n", a);
    printf("%d\n", b);
    printf("\n");
    
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("\n");
    
    printf("%p\n", p);
    printf("%p\n", &p);
    printf("\n");
    
    *p += 1;
    
    printf("%d\n", *p);
    
    printf("increment %d\n", increment2(p));
    printf("%d\n", a);
    
    printf("%d\n", a);
    printf("%d\n", b);
    printf("\n");
    
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("\n");
    
    printf("%p\n", p);
    printf("%p\n", &p);
    printf("\n");
    
    p -= 1;
    *p += 10;
    
    printf("%p\n", p);
    printf("%d\n", b);
    printf("%p\n", &b);
    
    p = &b;
    printf("%p\n", p);
    return 0;
}
