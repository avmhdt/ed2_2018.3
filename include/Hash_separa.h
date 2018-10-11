#ifndef HASH_SEPARA_H
#define HASH_SEPARA_H
#include "Lista_encadeada.h"

class Hash_separa
{
    public:
        Hash_separa(int tamanho);
        ~Hash_separa();
        int func_hash_separado(int valor);
        void insere_hash_separado (int valor);
        void imprimir();
        int comparacoes;
    private:
        int tam;
        ListaEncadeada ** lista;
};

#endif // HASH_SEPARA_H
