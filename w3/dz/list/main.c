#include <stdio.h>

#include "List.h"

int main() {
    List list;
    int array[] = {1, 2, 3};

    init(&list, 10);
    for ( int i = 1; i <= 10; i++ ) {
        addValue(&list, i);
    }
    trace(&list);
    printf("\n");
    printListInfo(&list);
    
    
    // indexAddValue(&list, 100, 8);
    // addValue(&list, 999);

    // printListInfo(&list);
    addValue(&list, 99);
    trace(&list);
    copyArrayToList(&list, array, 3);
    printListInfo(&list);
    trace(&list);
    printf("\n");

    // addValue(&list, 99);
    // addValue(&list, 999);
    // addValue(&list, 9999);
    // addValue(&list, 99999);
    // addValue(&list, 999999);
    // addValue(&list, 9999999);
    // indexAddValue(&list, 4545, 14);

    // trace(&list);
    // printf("\n");
    // pop(&list);
    // pop(&list);
    // pop(&list);
    // pop(&list);
    // addValue(&list, 99);
    // trace(&list);
    // printListInfo(&list);
    // printf("\n");

    // for ( int i = 1; i <= 7; i++ ) {
    //     addValue(&list, i);
    // }
    // trace(&list);
    // printf("\n");

    // popValues(&list, 16);
    // trace(&list);
    // printf("\n");

    // clipList(&list,1);
    // trace(&list);
    // printf("\n");
    // trace(&list);
    // printListInfo(&list);
    // release(&list);
    // printListInfo(&list);

    return 0;
}