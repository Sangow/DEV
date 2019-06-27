// Задача arithmetic
// Условие задачи
// Вывести результаты пяти разных арифметических действий над двумя введенными числами.

// Пример ввода
// 1 2
// 
// Пример вывода
// 1+2=3
// 1-2=-1
// 1*2=2
// 1/2=0
// 1%2=1

#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d%d", &a, &b);
    
    printf("%d+%d=%d\n", a, b, a+b);
    printf("%d-%d=%d\n", a, b, a-b);
    printf("%d*%d=%d\n", a, b, a*b);
    printf("%d/%d=%d\n", a, b, a/b);
    printf("%d%%%d=%d\n", a, b, a%b);
    
    return 0;
}
