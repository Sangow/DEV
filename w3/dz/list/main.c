#include <stdio.h>

#include "List.h"

int main() {
    List list;
    int array[] = {1, 2, 3};

    init(&list, 10);
    for ( int i = 1; i <= 10; i++ ) {
        addValue(&list, i);
    }
    

    return 0;
}