#include "../headers/libraries.h"


int randomInt(int from, int to) {
    return rand()%(to - from + 1) + from;
} /// end randomInt();


void printVec(int *vec, int vecSize) {
    for(int i = 0; i < vecSize; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << endl;
} /// end printVec();


int minVec(int *vec, int vecSize) {
    int m = vec[0];
    for(int i=1; i < vecSize; i++) {
        if(vec[i] < m)
            m = vec[i];
    }
    return m;
} /// end minVec();


int minVecPos(int *vec, int vecSize) {
    int m = 0;
    for(int i=1; i < vecSize; i++) {
        if(vec[i] < vec[m])
            m = i;
    }
    return m;
} /// end minVecPos();


double minVec(double *vec, int vecSize) {
    double m = vec[0];
    for(int i=1; i < vecSize; i++) {
        if(vec[i] < m)
            m = vec[i];
    }
    return m;
} /// end minVec();



int maxVec(int *vec, int vecSize) {
    int m = vec[0];
    for(int i=1; i < vecSize; i++) {
        if(vec[i] > m)
            m = vec[i];
    }
    return m;
} /// end maxVec();


void swapPtr(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
} /// end swapPtr();


void swapPtrDep(GastoDeputado *a, GastoDeputado *b) {
    GastoDeputado aux = *a;
    *a = *b;
    *b = aux;
} /// end swapPtrDep();


bool ordenado(int *vec, int vecSize) {
    for(int i = 1; i < vecSize; i++) {
        if(vec[i] < vec[i-1])
            return false;
    }
    return true;
} /// end ordenado();


bool ordenado(GastoDeputado *vec, int vecSize) {
    for(int i = 1; i < vecSize; i++) {
        if(vec[i].getDeputyId() < vec[i-1].getDeputyId())
            return false;
    }
    return true;
} /// end ordenado();







