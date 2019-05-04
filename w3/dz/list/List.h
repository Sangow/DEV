#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int* array;
} List;

void init(List* list, int capacity);
int _increaseCapacity(List* list, int size);
int _reduceCapacity(List *list, int newCapacity);
void addValue(List* list, int value);
void indexAddValue(List* list, int index, int value);
void copyArrayToList(List* list, int array[], int arraySize);
void pop(List* list);
void popValues(List* list, int countValues);
void printListInfo(List* list);
void trace(List* list);
void clipList(List* list, int clipCapacity);
void release(List* list);