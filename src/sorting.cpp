#include "../headers/libraries.h"

int *partitionIt(int *left, int *right, int pivot, unsigned int *comp, unsigned int *copias) {
    int *leftPtr = left-1;
    int *rightPtr = right;

    while(true) {
        (*comp) += 1;
        while(*(++leftPtr) < pivot) {
            (*comp) += 1;
        }
        (*comp) += 1;
        while(rightPtr > 0 && *(--rightPtr) > pivot) {
            (*comp) += 1;
        }

        if(leftPtr >= rightPtr) {
            break;
        } else {
            swapPtr(leftPtr, rightPtr);
            (*copias) += 1;
        }
    } // end while(true)

    swapPtr(leftPtr, right);
    (*copias) += 1;
    return leftPtr;
} /// end partitionIt();

/*
int *partitionItMedian(int *left, int *right, int pivot, unsigned int *comp, unsigned int *copias) {
    int *leftPtr = left;
    int *rightPtr = right-1;

    while(true) {
        (*comp) += 1;
        while(*(++leftPtr) < pivot) {
            (*comp) += 1;
        }
        (*comp) += 1;
        while(*(--rightPtr) > pivot) {
            (*comp) += 1;
        }

        if(leftPtr >= rightPtr) {
            break;
        } else {
            swapPtr(leftPtr, rightPtr);
            (*copias) += 1;
        }
    } // end while(true)

    swapPtr(leftPtr, right-1);
    (*copias) += 1;
    return leftPtr;
} /// end partitionItMedian();
*/


/*
GastoDeputado *partitionItDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, int pivot) {
    GastoDeputado *leftPtr = leftDep-1; cout << "part: leftPtr" << endl;
    GastoDeputado *rightPtr = rightDep; cout << "part: rightPtr" << endl;

    while(true) { cout << "part: while(true)" << endl;
        while((*(++leftPtr)).getDeputyId() < pivot); cout << "part: while(leftPtr). rightPtr = " << rightPtr << endl;
        while(rightPtr > 0  && (*(--rightPtr)).getDeputyId() > pivot); cout << "part: while(rightPtr)" << endl;
        if(leftPtr >= rightPtr) {cout << "part: if(leftPtr >= rightPtr)" << endl;
            break;}
        else swapPtrDep(leftPtr, rightPtr); cout << "part: else" << endl;
    } // end while(true)

    swapPtrDep(leftPtr, rightDep); cout << "part: swap" << endl;
    return leftPtr;
} /// end partitionItDeputyId();
*/

GastoDeputado *partitionItDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, int pivot, unsigned int *comp, unsigned int *copias) {

    // pivot (Element to be placed at right position)
    //pivot = arr[high];

    //i = (low - 1)  // Index of smaller element
    GastoDeputado *leftPtr = leftDep-1;
    GastoDeputado *idx;

    for (idx = leftDep; idx <= rightDep-1; idx++) {
        (*comp) += 1;
        if((*idx).getDeputyId() <= pivot) { // If current element is smaller than or equal to pivot
            leftPtr++;    // increment index of smaller element
            swapPtrDep(leftPtr, idx);
            (*copias) += 1;
        }
    }

    swapPtrDep(leftPtr+1, rightDep);
    (*copias) += 1;
    return leftPtr+1;
} /// end partitionItDeputyId();


void manualSort(int *left, int *right, unsigned int *comp, unsigned int *copias) {
    int sizeVec = right-left+1;
    if(sizeVec <= 1)
        return; // no sorting necessary
    if(sizeVec == 2) {
        (*comp) += 1;
        if(*left > *right) {
            swapPtr(left, right);
            (*copias) += 1;
        }
    }
    else { // sizeVec = 3, center = right-1
        (*comp) += 1;
        if(*left > *(right-1)) {
            swapPtr(left, right-1);   //left, center
            (*copias) += 1;
        }
        (*comp) += 1;
        if(*left > *right) {
            swapPtr(left, right);     //left, right
            (*copias) += 1;
        }
        (*comp) += 1;
        if(*(right-1) > *right) {
            swapPtr(right-1, right);  //center, right
            (*copias) += 1;
        }
    } // end
} /// end manualSort();


/*
int medianOfK(int *left, int *right, int k, unsigned int *comp, unsigned int *copias) {           ///CERTO?? COMO ORDENAR OS K ELEMENTOS???

    if(k == 3) {
        int sizeAux = right-left;
        int *center = left + sizeAux/2;

        (*comp) += 1;
        if(*left > *center) {
            swapPtr(left, center);
            (*copias) += 1;
        }
        (*comp) += 1;
        if(*left > *right) {
            swapPtr(left, right);
            (*copias) += 1;
        }
        (*comp) += 1;
        if(*center > *right) {
            swapPtr(center, right);
            (*copias) += 1;
        }

        swapPtr(center, right-1);
        (*copias) += 1;

        return *(right-1);
    }


    int **idxPtrs = new int*[k];
    int *pivotPtr;
    int pivot, j;

    for(int i = 0; i < k; i++) { // Seleciona k índices aleatórios do vetor
        idxPtrs[i] = left + randomInt(0, right-left); // Vetor de k ponteiros para elementos do vetor a ser ordenado,
                                                      //   a partir do qual se calcula a mediana.

//        for(int j = 0; j < i; j++) {
//            if(idxs[i] == idxs[j]) { // Garante que não hajam 2 números iguais gerados
//                idxs[i] = randomInt(left + randomInt(0, right-left));
//                j = 0
//            }
//        }

    }

//    for(int i = 0; i < k; i++) {
//        pivotPtr = idxPtrs[i];  // Aqui, devemos ordenar um vetor de ponteiros
//        pivot = *pivotPtr;       // Com base na ordem dos elementos apontados
//        j = i-1;                 //
//        (*comp) += 1;
//        while(j >= 0 && *(idxPtrs[j]) > pivot) {
//            idxPtrs[j+1] = idxPtrs[j];
//            (*copias) += 1;
//            j--;                         // Desta maneira, podemos achar o endereço do elemento no vetor original
//            (*comp) += 1;
//        } // end while                   // igual à mediana dos k elementos aleatoriamente escolhidos
//        idxPtrs[j+1] = pivotPtr;
//        (*copias) += 1;
//
//    } // end for


    insertionSort(idxPtrs[0], k, comp, copias);

    swapPtr(idxPtrs[k/2], right-1); // e colocar esse elemento na extrema direita do vetor
    (*copias) += 1;

    delete idxPtrs;                // ficando com um vetor particionavel pela função partitionIt acima
    return *(right-1);

//    int *kElements = new int[k];
//    int i, j, aux, pivot;
//
//    for(i = 0; i < k; i++) {
//        kElements[i] = *(left + randomInt(0, right-left));
//    }
//
//    for(int i = 0; i < k; i++) {
//        pivot = kElements[i];
//        j = i-1;
//        (*comp) += 1;
//        while(j >= 0 && kElements[j] > pivot) {
//            kElements[j+1] = kElements[j];
//            (*copias) += 1;
//            j--;
//            (*comp) += 1;
//        } // end while
//        kElements[j+1] = pivot;
//        (*copias) += 1;
//
//    } // end for
//
//    aux = kElements[k/2];
//    delete kElements;
//    return aux;

} /// end medianOfK();
*/



void quickSort(int *left, int *right, unsigned int *comp, unsigned int *copias) {
    if(right - left <= 0)               // if size <= 1,
        return;                         // already Sorted
    else {                              // size is 2 or larger
        int pivot = *right;             // rightmost item as pivot
        int *part = partitionIt(left, right, pivot, comp, copias);
        quickSort(left, part-1, comp, copias);        // Sort left side
        quickSort(part+1, right, comp, copias);       // Sort right side
    }
} /// end quickSort();


void quickSortDeputyId(GastoDeputado *leftDep, GastoDeputado *rightDep, unsigned int *comp, unsigned int *copias) {
    if(rightDep - leftDep <= 0)                    // if size <= 1,
        return;                                    // already Sorted
    else {                                         // size is 2 or larger
        int pivot = (*rightDep).getDeputyId();     // rightmost item as pivot
        GastoDeputado *part = partitionItDeputyId(leftDep, rightDep, pivot, comp, copias);
        quickSortDeputyId(leftDep, part-1, comp, copias);        // Sort left side
        quickSortDeputyId(part+1, rightDep, comp, copias);       // Sort right side
    }
} /// end quickSortDeputyId();


/*
void quickSortMedian(int *left, int *right, int k, unsigned int *comp, unsigned int *copias) {
    int sizeVec = right-left+1;
    if(sizeVec <= k) { // manual Sort if small,
        if(k == 3)
            manualSort(left, right, comp, copias);
//        else if(k == 5)
//            quickSort(left, right, comp, copias);
    }
////
////    else if(k > sizeVec) {  // median of all elements if k > sizeVec
////        int median = medianOfK(left, right, sizeVec, comp, copias); // median of sizeVec elements
////        int *part = partitionItMedian(left, right, median, comp, copias);
////        quickSortMedian(left, part-1, sizeVec, comp, copias);        // Sort left side
////        quickSortMedian(part+1, right, sizeVec, comp, copias);       // Sort right side
////    }
//    else {                              // quickSortMedian if large
//        int median = medianOfK(left, right, k, comp, copias);
//        int *part = partitionItMedian(left, right, median, comp, copias);
//        quickSortMedian(left, part-1, k, comp, copias);        // Sort left side
//        quickSortMedian(part+1, right, k, comp, copias);       // Sort right side
//    }

    else {                              // size is 2 or larger
        int c = k;
        int sizeVec = right-left+1;
        if(c > sizeVec)
            c = sizeVec;

        int pivot = medianOfK(left, right, c, comp, copias);             // rightmost item as pivot
        int *part = partitionItMedian(left, right, pivot, comp, copias);
        quickSortMedian(left, part-1, c, comp, copias);        // Sort left side
        quickSortMedian(part+1, right, c, comp, copias);       // Sort right side
    }
} /// end quickSortMedian();
*/



int medianOfK(int *left, int *right, int k, unsigned int *comp, unsigned int *copias) {//(int vet[], int ini, int fim, int k) {

//    int *kElements = new int[k];
//    int aux;
//
//    //srand((unsigned)time(NULL));
//    for(int i = 0; i < k; i++) {
//        aux = rand()%(right-left+1);
//        kElements[i] = left[aux];
//    }
//
//    insertionSort(kElements, k, comp, copias);
//
//    aux = kElements[k/2];
//    delete [] kElements;
//    return aux;

    int i, pivot = 0;
    for(i = 0; i < k; i++) {
        pivot += *(left + randomInt(0, right-left));
    }
    return pivot/k;

} /// end medianOfK();



void quickSortMedian(int *left, int *right, int k, unsigned int *comp, unsigned int *copias) { //(int vet[],int ini,int fim)

    if(right - left <= 0) {
        return;
    }

    int pivot = medianOfK(left, right, k, comp, copias);
    int *iPtr, *jPtr;

    iPtr = left;
    jPtr = right;

    while(iPtr < jPtr) {

        (*comp) += 1;
        while(iPtr < right && *iPtr < pivot) {
            iPtr++;
            (*comp) += 1;
        }
        (*comp) += 1;
        while(jPtr > left && *jPtr > pivot) {
            jPtr--;
            (*comp) += 1;
        }

        if(iPtr < jPtr) {
            swapPtr(iPtr, jPtr);
            (*copias) += 1;
        }

        (*comp) += 1;
        if(*iPtr == *jPtr) {
            iPtr++;
        }
    }

    quickSortMedian(left, iPtr-1, k, comp, copias);
    quickSortMedian(iPtr, right, k, comp, copias);

} /// end quickSortMedian();


void quickSortInsertion(int *left, int *right, int m, unsigned int *comp, unsigned int *copias) {
    int sizeVec = right-left+1;
    if(sizeVec <= m)                    // manual Sort if small,
        insertionSort(left, sizeVec, comp, copias);
    else {                              // quickSort if large
        int pivot = *right;             // rightmost item as pivot
        int *part = partitionIt(left, right, pivot, comp, copias);
        quickSortInsertion(left, part-1, m, comp, copias);        // Sort left side
        quickSortInsertion(part+1, right, m, comp, copias);       // Sort right side
    }
} /// end quickSortInsertion();


void insertionSort(int *vec, int vecSize, unsigned int *comp, unsigned int *copias) {
    int pivot, i, j;
    for(i = 0; i < vecSize; i++) {
        pivot = *(vec+i);
        j = i-1;
        (*comp) += 1;
        while(j >= 0 && *(vec+j) > pivot) {
            *(vec+j+1) = *(vec+j);
            (*copias) += 1;
            j--;
            (*comp) += 1;
        } // end while
        *(vec+j+1) = pivot;
        (*copias) += 1;
    } // end for
} /// end insertionSort();


void mergeVec(int *vec, int l, int m, int r, unsigned int *comp, unsigned int *copias) {
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
        (*comp) += 1;
        if(L[i] <= R[j]) {
            vec[k] = L[i];
            (*copias) += 1;
            i++;
        } else {
            vec[k] = R[j];
            (*copias) += 1;
            j++;
        }
        k++;
    }

    while(i < n1) { // Copiando os elementos de L que faltam
        vec[k] = L[i];
        (*copias) += 1;
        i++;
        k++;
    }

    while(j < n2) { // Copiando os elementos de R que faltam
        vec[k] = R[j];
        (*copias) += 1;
        j++;
        k++;
    }
    delete [] L; // Liberando memória
    delete [] R;
} /// end mergeVec();


void mergeSort(int *vec, int l, int r, unsigned int *comp, unsigned int *copias) {
    int m;

    if(l < r) {
        m = l + (r-l)/2; // evitando overflow

        mergeSort(vec, l, m, comp, copias);
        mergeSort(vec, m+1, r, comp, copias);

        mergeVec(vec, l, m, r, comp, copias);
    }
} /// end mergeSort();


void selectionSort(int *vec, int vecSize, unsigned int *comp, unsigned int *copias) {
    int j, idxMin;

    for(int i = 0; i < vecSize-1; i++) {
        idxMin = i;
        for(int j = i+1; j < vecSize; j++) {
            (*comp) += 1;
            if(vec[j] < vec[idxMin])
                idxMin = j;
        }
        swapPtr(vec+idxMin, vec+i);
        (*copias) += 1;
    }
} /// end selectionSort();


void countingSort(int *vec, int vecSize, unsigned int *comp, unsigned int *copias) { // versão modificada do algoritmo countingSort
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
        (*copias) += 1;
        --countVec[vec[i]-minRange];
    }

    for(i = 0; i < vecSize; i++) { // copiando para vetor vec na ordem correta
        vec[i] = output[i];
        (*copias) += 1;
    }

    delete [] countVec; // Liberando memória
    delete [] output;
} /// end countingSort();


void HeapMax(int vet[], int filho, unsigned int *comp, unsigned int *copias)
{
    int pai, aux;
    pai = (filho-1)/2;

    (*comp) += 1;
    if(vet[filho]>vet[pai])
    {
        aux = vet[filho];
        vet[filho] = vet[pai];
        vet[pai] = aux;
        (*copias) += 1;
    }
} /// end HeapMax();


void heapSort(int vet[], int tamanho, unsigned int *comp, unsigned int *copias)
{
    int aux,tam = tamanho-1;
    for(int j=0; j<tamanho; j++)
    {
        for(int i=tam; i>0; --i)
        {
            HeapMax(vet, i, comp, copias); /// Chama a função para transformar o vetor em uma heap máxima
        }
        aux = vet[0]; /// Faz as trocas para deixar o maior elemento (encotrado com HeapMax) no final do vetor
        vet[0] = vet[tam];
        vet[tam] = aux;
        (*copias) += 1;
        tam--; /// Já que o maior elemento já está no final, não preciso trabalhar com ele novamente, está ordenado
    }
} /// end heapSort();

