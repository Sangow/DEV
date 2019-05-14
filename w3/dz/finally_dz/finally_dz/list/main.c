#include <stdio.h>
#include "List.h"

int main() {
    List list;
    int array[] = {1, 2, 3};

    init(&list, 10000);
    for ( int i = 1; i <= 10000; i++ ) {
        addValue(&list, i);
    }
    trace(&list);
    printf("\n");

    addValue(&list, 455);
    trace(&list);
    printf("\n");

    clipList(&list, 10);
    printListInfo(&list);

    indexAddValue(&list, 100, 10);
    printListInfo(&list);

    indexAddValue(&list, 1000, 100);
    printListInfo(&list);

    pop(&list);
    printListInfo(&list);

    popValues(&list, 3);
    printListInfo(&list);

    copyArrayToList(&list, array, 3);
    printListInfo(&list);

    release(&list);
    printListInfo(&list);

    return 0;
}