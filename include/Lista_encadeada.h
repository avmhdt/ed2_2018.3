#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include "Lista_encadeada.h"
#include "No.h"

class ListaEncadeada{
public:
    ListaEncadeada();
    ~ListaEncadeada();
    void insereInicio(int val);
    void insere(int val);
    void imprimir();
    int comparacoes;
private:
    No* primeiro;
};

#endif // LISTA_ENCADEADA_H
