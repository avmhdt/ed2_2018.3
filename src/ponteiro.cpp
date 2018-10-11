#include "../headers/libraries.h"

ponteiro::ponteiro(){}

ponteiro::~ponteiro(){}

int ponteiro::getChave()
{
    return chave;
}

ponteiro* ponteiro::getProx()
{
    return prox;
}

void ponteiro::setChave(int val)
{
    chave = val;
}

void ponteiro::setProx(ponteiro* novo)
{
    prox = novo;
}

int ponteiro::getEnde()
{
    return endereco;
}

void ponteiro::setEnde(int val)
{
    endereco = val;
}
