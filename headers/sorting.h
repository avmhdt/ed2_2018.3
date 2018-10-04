#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include "deputado.h"

int *partitionIt(int *left, int *right, int pivot, int *comp, int *trocas);
GastoDeputado *partitionItDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, int pivot, int *comp, int *trocas);
int medianOfk(int *left, int *right, int k, int *comp, int *trocas);
void manualSort(int *left, int *right, int *comp, int *trocas);
void mergeVec(int *vec, int start, int mid, int finish, int *comp, int *trocas);

void quickSort(int *left, int *right, int *comp, int *trocas);
void quickSortDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, int *comp, int *trocas); //Para ordenação de linhas da tabela, e não inteiros.
void quickSortMedian(int *left, int *right, int k, int *comp, int *trocas);
void quickSortInsertion(int *left, int *right, int m, int *comp, int *trocas);
void mergeSort(int *vec, int l, int r, int *comp, int *trocas);
void heapSort(int *vec, int vecSize, int *comp, int *trocas);
void insertionSort(int *vec, int vecSize, int *comp, int *trocas);
void selectionSort(int *vec, int vecSize, int *comp, int *trocas);
void countingSort(int *vec, int vecSize, int *comp, int *trocas);

#endif // SORTING_H_INCLUDED
