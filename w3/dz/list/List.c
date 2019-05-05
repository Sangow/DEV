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

int _increaseCapacity(List* list, int size) {
    if ( size == list->capacity + 1 ) {
        int* newArray = list->array;
        int newCapacity = list->capacity + list->capacity / 5;

        newArray = (int*)realloc(list->array, sizeof(int)*newCapacity);

        if ( newArray == NULL ) {
            printf("Memory reallocation error!\n");
            return 0;
        }
        printf("Memory reallocated!\n");
        list->array = newArray;
        list->capacity = newCapacity;
        return 1;
    }
    return 1;
}


int _reduceCapacity(List* list, int newCapacity) {
    int* newArray = list->array;

    newArray = (int*)realloc(list->array, sizeof(int)*newCapacity);

    if ( newArray == NULL ) {
        printf("Memory reallocation error!\n");
        return 0;
    }
    printf("Memory reallocated!\n");
    list->array = newArray;
    list->capacity = newCapacity;
    return 1;
}

//* добавление одного элемента в конец //
void addValue(List* list, int value) {
    int size = list->size + 1;

    if ( _increaseCapacity(list, size) ) {
        list->array[list->size] = value;
        list->size = size;
    }
}

// * добавление одного элемента по произвольном индексу (список при этом также расширяется) //
void indexAddValue(List* list, int value, int index) {
    int size = list->size + 1;

    if ( _increaseCapacity(list, size) ) {
        for ( int i = list->size; i > index; i-- ) {
            list->array[i] = list->array[i-1];
        }
        list->array[index] = value;
        list->size = size;
    }
}

// * добавление (копирование) заданного количества элементов из массива в конец списка //
void copyArrayToList(List* list, int array[], int arraySize) {
    for (int i = 0, j = list->size; i < arraySize; i++, j++ ) {
        indexAddValue(list, array[i], j);
    }
}

// * удаление последнего элемента //
void pop(List* list) {
    if ( list->size == 0 ) {
        printf("Cannot delete value out of empty list!\n");
        return;
    }
    list->size -= 1;

    int newCapacity = list->capacity - list->capacity / 5;

    if ( newCapacity >= list->size ) {
        _reduceCapacity(list, newCapacity);
    }
}

// * удаление заданного количества последних элементов //
void popValues(List* list, int countValues) {
    if ( countValues > list->size ) {
        printf("Error! You can pop only %d values!\n", list->size);
        return;
    } else if ( list->size == 0 ) {
        printf("Error! List is empty!\n");
        return;
    }

    list->size -= countValues;

    int newCapacity = list->capacity - list->capacity / 5;

    if ( newCapacity >= list->size ) {
        _reduceCapacity(list, newCapacity);
    }
}

// * "обрезание" списка до заданной длины //
void clipList(List* list, int clipCapacity) {
    if ( _reduceCapacity(list, clipCapacity) ) {
        if ( list->size > clipCapacity ) {
            list->size = clipCapacity;
        }
    }
}

void printListInfo(List* list) {
    if ( list->size == 0 ) {
        printf("List is empty!\n");
        return;
    }
    printf("List size = %d\n", list->size);
    printf("List capacity = %d\n", list->capacity);
    int last = list->size - 1;

    for (int i = 0; i < last; i++) {
        printf("%d ", list->array[i]);
    }
    printf("%d\n", list->array[last]);
}

void trace(List* list) {
    printf("List: %p, %d/%d\n", list->array, list->size, list->capacity);
}