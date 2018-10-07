#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include "deputado.h"

int *partitionIt(int *left, int *right, int pivot, unsigned int *comp, unsigned int *copias);
GastoDeputado *partitionItDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, int pivot, unsigned int *comp, unsigned int *copias);
int medianOfK(int *left, int *right, int k, unsigned int *comp, unsigned int *copias);
void manualSort(int *left, int *right, unsigned int *comp, unsigned int *copias);
void mergeVec(int *vec, int start, int mid, int finish, unsigned int *comp, unsigned int *copias);
void HeapMax(int vet[], int filho, unsigned int *comp, unsigned int *copias);

void quickSort(int *left, int *right, unsigned int *comp, unsigned int *copias);
void quickSortDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, unsigned int *comp, unsigned int *copias); //Para ordenação de linhas da tabela, e não inteiros.
void quickSortMedian(int *left, int *right, int k, unsigned int *comp, unsigned int *copias);
void quickSortInsertion(int *left, int *right, int m, unsigned int *comp, unsigned int *copias);
void mergeSort(int *vec, int l, int r, unsigned int *comp, unsigned int *copias);
void heapSort(int *vec, int vecSize, unsigned int *comp, unsigned int *copias);
void insertionSort(int *vec, int vecSize, unsigned int *comp, unsigned int *copias);
void selectionSort(int *vec, int vecSize, unsigned int *comp, unsigned int *copias);
void countingSort(int *vec, int vecSize, unsigned int *comp, unsigned int *copias);

#endif // SORTING_H_INCLUDED
