#include <iostream>
#include "../headers/libraries.h"

using namespace std;

No::No() {};
No::~No() {};
int No::getInfo()
{
    return info;
}
No* No::getProx()
{
    return Prox;
}
void No::setInfo(int novo)
{
    info = novo;
}
void No::setProx(No* novo)
{
    Prox = novo;
}
