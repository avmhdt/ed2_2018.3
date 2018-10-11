#include <iostream>
#include "../headers/libraries.h"

Re_hashing::Re_hashing(int tam)
{
    tamanho = tam;
    vetor = new int[tamanho];
    for(int i=0; i<tamanho; ++i)
    {
        vetor[i] = 0;
    }
}

Re_hashing::~Re_hashing()
{
    delete []vetor;
}

int Re_hashing::func_calc_hashing(int valor)
{
    return valor%tamanho;
}

int Re_hashing::func2_calc_hashing(int valor)
{
    return ((2*valor)-1)%tamanho;
}

void Re_hashing::inserir_rehashing(int valor)
{
    int f = func_calc_hashing(valor);
    comparacoes+=1;
    if(vetor[f]==0)
    {
        vetor[f] = valor;
        cout << valor << " adicionado no indice " << f << endl;
    }
    else
    {
        int cont=1;
        comparacoes+=1;
        while(vetor[f]!=0)
        {
            f = (func_calc_hashing(valor)+(cont*(func2_calc_hashing(valor))));
            comparacoes+=1;
            if(f>=tamanho)
            {
                f = f%tamanho;
            }
            cont++;
        }
        vetor[f] = valor;
    }
}

void Re_hashing::imprimir()
{
    for(int i=0; i<tamanho; ++i)
    {
        cout << "Indice " << i << ": " << vetor[i] << endl;
    }
}
