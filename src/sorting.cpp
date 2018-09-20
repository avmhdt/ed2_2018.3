#include "../headers/libraries.h"

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


void mergeVec(int *vec, int l, int m, int r) {
    int i, j, k; // índices
    int n1 = m-l+1, n2 = r-m; // tamanho dos subvetores esquerdo e direito
    int *L, *R;
    L = new int[n1]; // Alocando subvetores esquerdo
    R = new int[n2]; //  e direito

    for (i = 0; i < n1; i++) //preenchendo esquerdo
        L[i] = vec[l+i];
    for (j = 0; j < n2; j++) //preenchendo direito
        R[j] = vec[m+1+j];

    i = j = 0;
    k = l;

    while(i < n1 && j < n2) { // "Merging" os vetores L e R de volta para vec
        if(L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) { // Copiando os elementos de L que faltam
        vec[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) { // Copiando os elementos de R que faltam
        vec[k] = R[j];
        j++;
        k++;
    }
    delete L; // Liberando memória
    delete R;
} /// end mergeVec();


void mergeSort(int *vec, int l, int r) {
    int m;

    if(l < r) {
        m = l + (r-l)/2; // evitando overflow

        mergeSort(vec, l, m);
        mergeSort(vec, m+1, r);

        mergeVec(vec, l, m, r);
    }
} /// end mergeSort();


void selectionSort(int *vec, int vecSize) {
    int j, idxMin;

    for(int i = 0; i < vecSize-1; i++)
    {
        idxMin = i;
        for(int j = i+1; j < vecSize; j++) {
          if(vec[j] < vec[idxMin])
            idxMin = j;
        }
        swapPtr(vec+idxMin, vec+i);
    }
} /// end selectionSort();


void countingSort(int *vec, int vecSize) { // versão modificada do algoritmo countingSort
    int minRange, maxRange, range, i;
    minRange = minVec(vec, vecSize); // vecSize operações (O(n))
    maxRange = maxVec(vec, vecSize); // vecSize operações (O(n))

    range = maxRange - minRange + 1;

    int *countVec = new int[range](); // inicializando com 0
    int *output = new int[vecSize];

    for(i = 0; i < vecSize; i++) {
        ++countVec[vec[i]-minRange];
    }

    for(i = 1; i < range; i++) {
        countVec[i] += countVec[i-1];
    }

    for (i = vecSize-1; i >= 0; i--) { // montando o vetor output, na ordem correta
        output[countVec[vec[i]-minRange]-1] = vec[i];
        --countVec[vec[i]-minRange];
    }

    for(i = 0; i < vecSize; i++) { // copiando para vetor vec na ordem correta
        vec[i] = output[i];
    }

    delete countVec; // Liberando memória
    delete output;
} /// end countingSort();

/*
void heapSort(int *vec, int sizeVec)
*/
