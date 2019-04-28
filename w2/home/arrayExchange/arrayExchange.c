#include <stdio.h>

void arrayExchange(int array[], int len) {
    for ( int i = 0, size = len - len % 2; i < size; i += 2 ) {
        int tmp = array[i];
        
        array[i] = array[i+1];
        array[i+1] = tmp;
    }
}

void arrayPrint(int array[], int size) {
    int last = size - 1;

    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / 4;
    arrayExchange(array,size);
    arrayPrint(array, size);
    return 0;
}
