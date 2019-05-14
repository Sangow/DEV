#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int* array;
} List;

void init(List* list, int capacity);

int _resize(List* list, int newCapacity);

//* добавление одного элемента в конец //
void addValue(List* list, int value);

// * добавление одного элемента по произвольном индексу (список при этом также расширяется) //
void indexAddValue(List* list, int value, int index);

// * добавление (копирование) заданного количества элементов из массива в конец списка //
void copyArrayToList(List* list, int array[], int arraySize);

// * удаление последнего элемента //
void pop(List* list);

// * удаление заданного количества последних элементов //
void popValues(List* list, int countValues);

// * "обрезание" списка до заданной длины //
void clipList(List* list, int clipCapacity);

void trace(List* list);

void printListInfo(List* list);

void release(List* list);