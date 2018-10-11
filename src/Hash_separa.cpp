#include <iostream>
#include "../headers/libraries.h"

using namespace std;

Hash_separa::Hash_separa(int tamanho)
{
    tam = tamanho;
    lista = new ListaEncadeada*[tam];
    for(int i=0;i<tam;++i)
    {
        lista[i] = new ListaEncadeada;
    }
}

Hash_separa::~Hash_separa()
{
    for(int i=0;i<tam;++i)
    {
        delete [] lista[i];
    }
    delete []lista;
}

int Hash_separa::func_hash_separado(int valor){
    return valor%tam;
}
void Hash_separa::insere_hash_separado(int valor){
    int f = func_hash_separado(valor);
    lista[f]->insere(valor);
    comparacoes = lista[f]->comparacoes;
}
void Hash_separa::imprimir()
{
    for(int i=0;i<tam;i++)
    {
       cout << "Posicao " << i << ": ";
       lista[i]->imprimir();
       cout << endl;
    }
}
