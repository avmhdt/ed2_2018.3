#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

int randomInt(int from, int to);
void swapPtr(int *a, int *b);
int *partitionIt(int *left, int *right, int pivot);
int medianOfk(int *left, int *right, int k);
void manualSort(int *left, int *right);
void mergeVec(int *vec, int start, int mid, int finish);

void quickSort(int *left, int *right);
///public void quicksortObject(int left, int right); Para ordenação de linhas da tabela, e não inteiros.
void quickSortMedian(int *left, int *right, int k);
void quickSortInsertion(int *left, int *right, int m);
void mergeSort(int *vec, int start, int finish);
void heapSort(int *vec, int sizeVec);
void insertionSort(int *vec, int sizeVec);

///public void meusort(); Fazer o meusort!

#endif // SORTING_H_INCLUDED
