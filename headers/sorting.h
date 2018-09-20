#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

int *partitionIt(int *left, int *right, int pivot);
int medianOfk(int *left, int *right, int k);
void manualSort(int *left, int *right);
void mergeVec(int *vec, int start, int mid, int finish);

void quickSort(int *left, int *right);
///public void quicksortObject(int left, int right); Para ordenação de linhas da tabela, e não inteiros.
void quickSortMedian(int *left, int *right, int k);
void quickSortInsertion(int *left, int *right, int m);
void mergeSort(int *vec, int l, int r);
void heapSort(int *vec, int vecSize);
void insertionSort(int *vec, int vecSize);
void selectionSort(int *vec, int vecSize);
void countingSort(int *vec, int vecSize);

#endif // SORTING_H_INCLUDED
