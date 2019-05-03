#include <stdio.h>

#include "List.h"

int main() {
    List list;

    init(&list, 10);
    for ( int i = 0; i < list.capacity; i++ ) {
        append(&list, i);
    }
    // append(&list, 9);
    // printList(&list);
    printListInfo(&list);
    append(&list, 111);
    printListInfo(&list);
    return 0;
}