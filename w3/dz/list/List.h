#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int* array;
} List;

void init(List* list, int capacity);
void addValue(List* list, int value);
void indexAddValue(List* list, int index, int value);
void pop(List* list);
void popValues(List* list, int countValues);
void printListInfo(List* list);
void trace(List* list);
void clipList(List* list, int clipCapacity);