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

//* добавление одного элемента в конец //
void addValue(List* list, int value) {
    int size = list->size + 1;

    if ( size == list->capacity + 1 ) {
        int* backupArray = list->array;
        int newCapacity = list->capacity + list->capacity / 5;

        list->array = (int*)realloc(list->array, sizeof(int)*newCapacity);

        if ( list->array == NULL ) {
            printf("Memory reallocation error!\n");
            list->array = backupArray;
            return;
        }
        printf("Memory reallocated!\n");
        list->capacity = newCapacity;
    }
    list->array[list->size] = value;
    list->size = size;
}

// * добавление одного элемента по произвольном индексу (список при этом также расширяется) //
void indexAddValue(List* list, int value, int index) {
    int size = list->size + 1;

    if ( size == list->capacity + 1 ) {
        int* backupArray = list->array;
        int newCapacity = list->capacity + list->capacity / 5;

        list->array = (int*)realloc(list->array, sizeof(int)*newCapacity);

        if ( list->array == NULL ) {
            printf("Memory reallocation error!\n");
            list->array = backupArray;
            return;
        }
        printf("Memory reallocated!\n");
        list->capacity = newCapacity;
    }

    for ( int i = list->size; i > index; i-- ) {
        list->array[i] = list->array[i-1];
    }
    list->array[index] = value;
    list->size = size;
}

// * удаление последнего элемента //
void pop(List* list) {
    if ( list->size == 0 ) {
        printf("Cannot delete value out of empty list!\n");
        return;
    }
    list->size -= 1;
}

// * удаление заданного количества последних элементов //
void popValues(List* list, int countValues) {
    if ( countValues > list->size ) {
        printf("Error! You can pop only %d values!\n", list->size);
        return;
    }
    list->size -= countValues;
}

void printListInfo(List* list) {
    printf("List size = %d\n", list->size);
    printf("List capacity = %d\n", list->capacity);
    int last = list->size - 1;

    for (int i = 0; i < last; i++) {
        printf("%d ", list->array[i]);
    }
    printf("%d\n", list->array[last]);
}

void clipList(List* list, int clipCapacity) {
    int* backupArray = list->array;

    list->array = (int*)realloc(list->array, sizeof(int)*clipCapacity);

    if ( list->array == NULL ) {
        printf("Memory reallocation error!\n");
        list->array = backupArray;
        return;
    }
    list->capacity = clipCapacity;

    if ( list->size > clipCapacity ) {
        list->size = clipCapacity;
    }
}

void trace(List* list) {
    printf("List: %p, %d/%d\n", list->array, list->size, list->capacity);
}