#ifndef HASH_COALESC_H
#define HASH_COALESC_H
#include "ponteiro.h"

class Hash_coalesc{
    public:
        Hash_coalesc(int tam);
        ~Hash_coalesc();
        void insere_hashCoalescido(int valor);
        void imprimir();
        int comparacoes;
    private:
        int func_hashCoalescido(int valor);
        int tamanho;
        ponteiro ** vetor;
};

#endif // HASH_COALESC_H
