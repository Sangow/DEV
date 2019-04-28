#include <stdio.h>

//========arrayScan()========//
int arrayScan(FILE* in, int array[], int limit);
//========arrayPrint()========//
void arrayPrint(FILE* out, int array[], int size);
//========arrayZeroFill()========//
void arrayZeroFill(int array[], int size);
//========arrayIncrement()========//
void arrayIncrement(int array[], int size, int increment);
//========arrayAbs()========//
void arrayAbs(int array[], int size);
//========arrayCopy()========//
void arrayCopy(int destination[], int source[], int size);
//========arraySum()========//
int arraySum(int array[], int size);
//========arrayMax()========//
int arrayMax(int array[], int size);
//========arrayMin()========//
int arrayMin(int array[], int size);
//========arraySearch()========//
int arraySearch(int array[], int size, int needle);
//========arrayReverse()========//
void arrayReverse(int array[], int size);
//========arrayShift()========//
void arrayShift(int array[], int size, int shift);
//========arrayExchange()========//
void arrayExchange(int array[], int len);
//========arrayUnique()========//
int arrayUnique(int array[], int size);
//========quickSort========//
int partition(int array[], int start, int end);
void quickSort(int array[], int start, int end);
//========bubbleSort========//
void bubbleSort(int array[], int size);
//========selectSort========//
void selectSort(int array[], int size);
//========insertSort========//
void insertSort(int array[], int size);
//========mergeSort========//
void merge(int array[], int lo, int mid, int hi);
void mergeSort(int array[], int lo, int hi);