#include <stdio.h>

//=============BUBBLE SORT=============//
void bubbleSort(int array[], int size);
//=============INSERT SORT=============//
void insertSort(int array[], int size);
//=============MERGE SORT=============//
void merge(int array[], int lo, int mid, int hi);
void mergeSort(int array[], int lo, int hi);
//=============QUICK SORT=============//
int partition(int array[], int start, int end);
void quickSort(int array[], int start, int end);
//=============SELECT SORT=============//
void selectSort(int array[], int size);