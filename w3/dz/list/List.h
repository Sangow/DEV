#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int* array;
} List;

void init(List* list, int capacity);
void append(List* list, int value);
void printList(List* list);
void printListInfo(List* list);