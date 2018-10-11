#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include "deputado.h"

int randomInt(int from, int to);
void swapPtr(int *a, int *b);
void printVec(int *vec, int vecSize);
int minVec(int *vec, int vecSize);
int minVecPos(int *vec, int vecSize);
double minVec(double *vec, int vecSize);
int maxVec(int *vec, int vecSize);
void swapPtr(int *a, int *b);
void swapPtrDep(GastoDeputado *a, GastoDeputado *b);
bool ordenado(int *vec, int vecSize);
bool ordenado(GastoDeputado *vec, int vecSize);

#endif // UTIL_H_INCLUDED
