#include <stdlib.h>
#include "List.h"

void init(List* list, int capacity) {
    list->size = 0;
    list->array = (int*)malloc(sizeof(int) * capacity);
    if ( list->array == NULL ) {
        printf("Memory allocation error!\n");
        list->capacity = 0;
        return;
    }
    list->capacity = capacity;
}

void append(List* list, int value) {
    int size = list->size + 1;
    list->array[list->size] = value;
    list->size = size;
}

void printList(List* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }

    int last = list->size - 1;

    for (int i = 0; i < last; i++) {
        printf("%d ", list->array[i]);
    }
    printf("%d\n", list->array[last]);
}

void printListInfo(List* list) {
    printf("List size = %d\n", list->size);
    printf("List capacity = %d\n", list->capacity);
    printList(list);
}
