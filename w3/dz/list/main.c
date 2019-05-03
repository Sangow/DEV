#include <stdio.h>

#include "List.h"

int main() {
    List list;

    init(&list, 10);
    for ( int i = 1; i <= 7; i++ ) {
        addValue(&list, i);
    }
    trace(&list);
    printf("\n");
    
    indexAddValue(&list, 100, 8);
    printListInfo(&list);
    trace(&list);
    // printf("\n");

    // pop(&list);
    // pop(&list);
    // pop(&list);
    // trace(&list);
    // printf("\n");

    // for ( int i = 1; i <= 7; i++ ) {
    //     addValue(&list, i);
    // }
    // trace(&list);
    // printf("\n");

    // popValues(&list, 10);
    // trace(&list);
    // printf("\n");

    //  clipList(&list,4);
    // trace(&list);
    // printf("\n");
    // trace(&list);
    // printListInfo(&list);

    return 0;
}