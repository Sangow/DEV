#include <stdio.h>

void arrayCopy(int destination[], int source[], int size) {
    for ( int i = 0; i < size; i++ ) {
        destination[i] = source[i];
    }
}

int main() {
    int size = 5;
    int source[] = {1, 2, 3, 4, 5};
    int destination[size];

    arrayCopy(destination,source,size);

    return 0;
}
