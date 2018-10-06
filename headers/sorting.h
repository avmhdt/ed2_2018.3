#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include "deputado.h"

int *partitionIt(int *left, int *right, int pivot, int *comp, int *copias);
GastoDeputado *partitionItDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, int pivot, int *comp, int *copias);
int medianOfk(int *left, int *right, int k, int *comp, int *copias);
void manualSort(int *left, int *right, int *comp, int *copias);
void mergeVec(int *vec, int start, int mid, int finish, int *comp, int *copias);

void quickSort(int *left, int *right, int *comp, int *copias);
void quickSortDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, int *comp, int *copias); //Para ordenação de linhas da tabela, e não inteiros.
void quickSortMedian(int *left, int *right, int k, int *comp, int *copias);
void quickSortInsertion(int *left, int *right, int m, int *comp, int *copias);
void mergeSort(int *vec, int l, int r, int *comp, int *copias);
void heapSort(int *vec, int vecSize, int *comp, int *copias);
void insertionSort(int *vec, int vecSize, int *comp, int *copias);
void selectionSort(int *vec, int vecSize, int *comp, int *copias);
void countingSort(int *vec, int vecSize, int *comp, int *copias);

#endif // SORTING_H_INCLUDED
