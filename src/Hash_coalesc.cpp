#include <iostream>
#include "../headers/libraries.h"

using namespace std;

Hash_coalesc::Hash_coalesc(int tam)
{
    tamanho = tam;
    vetor = new ponteiro*[tam];
    for(int i=0; i<tam; i++)
    {
        vetor[i] = new ponteiro();
        vetor[i]->setChave(NULL);
        vetor[i]->setEnde(-2); /// Define a chave de todos os elementos do vetor como -2(Ou seja, vazias)
    }
}

Hash_coalesc::~Hash_coalesc()
{
    delete []vetor;
}

void Hash_coalesc::imprimir()
{
    for(int i=0; i<tamanho; i++)
    {
        cout << "Posicao " << i << " ["  << vetor[i]->getChave() << "] " << "[" << vetor[i]->getEnde() << "]" << endl;
    }
}

int Hash_coalesc::func_hashCoalescido(int valor)
{
    return valor%tamanho;
}

void Hash_coalesc::insere_hashCoalescido(int val)
{
    int f = func_hashCoalescido(val);
    comparacoes+=1;
    if(vetor[f]->getEnde()==-2)
    {
        vetor[f]->setChave(val);
        vetor[f]->setEnde(-1);
    }
    else
    {
        for(int i=tamanho-1; i>=0; --i)
        {
            comparacoes+=1;
            if(vetor[i]->getEnde()==-2)
            {
                vetor[i]->setChave(val);
                vetor[f]->setProx(vetor[i]);
                vetor[f]->setEnde(i);
                vetor[i]->setEnde(-1);
            }
        }
    }
}
