#include "../headers/libraries.h"

int randomInt(int from, int to) {
    return rand()%(to - from + 1) + from;
} ///end randomInt();


void swapPtr(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
} /// end swapPtr();


int *partitionIt(int *left, int *right, int pivot) {
    int *leftPtr = left-1;
    int *rightPtr = right;

    while(true) {
        while(*(++leftPtr) < pivot);
        while(rightPtr > 0  && *(--rightPtr) > pivot);
        if(leftPtr >= rightPtr)
            break;
        else swapPtr(leftPtr, rightPtr);
    } // end while(true)

    swapPtr(leftPtr, right);
    return leftPtr;
} /// end partitionIt();


void manualSort(int *left, int *right) {
    int sizeVec = right-left+1;
    if(sizeVec <= 1)
        return; // no sorting necessary
    if(sizeVec == 2) {
        if(*left > *right)
            swapPtr(left, right);
    }
    else { // sizeVec = 3, center = right-1
        if(*left > *(right-1))
            swapPtr(left, right-1);   //left, center
        if(*left > *right)
            swapPtr(left, right);     //left, right
        if(*(right-1) > *right)
            swapPtr(right-1, right);  //center, right
    } // end
} /// end manualSort();


int medianOfK(int *left, int *right, int k) {           ///CERTO?? COMO ORDENAR OS K ELEMENTOS???
    int **idxPtrs = new int*[k];
    int *pivotPtr;
    int pivot, j;

    for(int i = 0; i < k; i++) { // Seleciona k índices aleatórios do vetor
        idxPtrs[i] = left + randomInt(0, right-left); // Vetor de k ponteiros para elementos do vetor a ser ordenado,
                                                        //   a partir do qual se calcula a mediana.
        /*
        for(int j = 0; j < i; j++) {
            if(idxs[i] == idxs[j]) { // Garante que não hajam 2 números iguais gerados
                idxs[i] = randomInt(left + randomInt(0, right-left));
                j = 0
            }
        }
        */
    }

    for(int i = 0; i < k; i++) { // Similar ao Insertion Sort
        pivotPtr = idxPtrs[i];  // Aqui, devemos ordenar um vetor de ponteiros
        pivot = *pivotPtr;       // Com base na ordem dos elementos apontados
        j = i-1;                 //
        while(j >= 0 && *(idxPtrs[j]) > pivot) {
            idxPtrs[j+1] = idxPtrs[j]; // Diferença em relação ao Insertion Sort
            j--;                         // Desta maneira, podemos achar o endereço do elemento no vetor original
        } // end while                   // igual à mediana dos k elementos aleatoriamente escolhidos
        idxPtrs[j+1] = pivotPtr;
    } // end for

    swapPtr(idxPtrs[k/2], right-1); // e colocar esse elemento na extrema direita do vetor
    delete idxPtrs;                // ficando com um vetor particionavel pela função partitionIt acima
    return *(right-1);
} /// end medianOfK();


void quickSort(int *left, int *right) {
    if(right - left <= 0)               // if size <= 1,
        return;                         // already Sorted
    else {                              // size is 2 or larger
        int pivot = *right;             // rightmost item as pivot
        int *part = partitionIt(left, right, pivot);
        quickSort(left, part-1);        // Sort left side
        quickSort(part+1, right);       // Sort right side
    }
} /// end quickSort();


void quickSortMedian(int *left, int *right, int k) {
    int sizeVec = right-left+1;
    if(sizeVec <= 3)                    // manual Sort if small,
        manualSort(left, right);
    else {                              // quickSort if large
        int median = medianOfK(left, right, k);
        int *part = partitionIt(left, right, median);
        quickSort(left, part-1);        // Sort left side
        quickSort(part+1, right);       // Sort right side
    }
} /// end quickSortMedian();


void quickSortInsertion(int *left, int *right, int m) {
    int sizeVec = right-left+1;
    if(sizeVec <= m)                    // manual Sort if small,
        insertionSort(left, sizeVec);
    else {                              // quickSort if large
        int pivot = *right;             // rightmost item as pivot
        int *part = partitionIt(left, right, pivot);
        quickSort(left, part-1);        // Sort left side
        quickSort(part+1, right);       // Sort right side
    }
} /// end quickSortInsertion();


void insertionSort(int *vec, int vecSize) {
    int pivot, i, j;
    for(i = 0; i < vecSize; i++) {
        pivot = *(vec+i);
        j = i-1;
        while(j >= 0 && *(vec+j) > pivot) {
            *(vec+j+1) = *(vec+j);
            j--;
        } // end while
        *(vec+j+1) = pivot;
    } // end for
} /// end insertionSort();


void mergeVec(int *vec, int start, int mid, int finish) {
    int idxStart = start, idxMid = mid+1, idxAux = 0;
    int *vecAux = vec;

    while(idxStart < mid+1 || idxMid < finish+1) {
        if(idxStart == mid+1) {
            vecAux[idxAux] = vec[idxMid];
            idxMid++;
            idxAux++;
        } else if(idxMid == finish+1 || vec[idxStart] <= vec[idxMid]) {
            vecAux[idxAux] = vec[idxStart];
            idxStart++;
            idxAux++;
        } else {
            vecAux[idxAux] = vec[idxMid];
            idxMid++;
            idxAux++;
        }
    } // end while

    for(int i = start; i <= finish; i++) {
        vec[i] = vecAux[i-start];
    }
} /// end mergeVec();


void mergeSort(int *vec, int start, int finish) {
    int mid;
    if(start < finish) {
        mid = (start+finish)/2;
        mergeSort(vec, start, mid);
        mergeSort(vec, mid+1, finish);
        mergeVec(vec, start, mid, finish);
    }
} /// end mergeSort();


/*
void heapSort(int *vec, int sizeVec)
*/
