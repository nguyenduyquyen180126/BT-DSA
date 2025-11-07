#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define PRINT_SORT_STEP
typedef struct
{
    int *p;
    int size;
}Array;
void initArray(Array *a, int size, const char *data);
void insertArray(Array *a, int var, int index);
void deleteEle(Array *p, int index);
void selectionSort(Array *p);
void insertSort(Array *p);
void bubbleSort(Array *p);
int partition(Array *p, int left, int right, int pivot);
void quickSort(Array *p, int left, int right);
void mergeSort(Array *p, int left, int right);
void merge(Array *p, int left, int center, int right);
void buildHeap(Array *p, int n, int i);
void heapSort(Array *p, int n);
int cmpArray(Array *a, Array *b);
void printArray(Array *a);
void freeArray(Array *a);
#endif