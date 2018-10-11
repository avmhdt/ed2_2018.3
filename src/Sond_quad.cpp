#include <iostream>
#include <math.h>
#include "../headers/libraries.h"

Sond_quad::Sond_quad(int tam)
{
    tamanho = tam;
    vetor = new int[tamanho];
    for(int i=0;i<tamanho;++i)
    {
        vetor[i] = 0;
    }
}

Sond_quad::~Sond_quad()
{
    delete []vetor;
}

int Sond_quad::func_calc_hashing(int valor)
{
    return valor%tamanho;
}

void Sond_quad::inserir_func_quadratica(int valor)
{
    int f = func_calc_hashing(valor);
    comparacoes += 1;
    if (vetor[f]==0)
    {
        vetor[f] = valor;
    }
    else
    {
        int cont=1, aux;
        comparacoes += 1;
        while(vetor[f]!=0)
        {
            aux = pow(cont,2);
            f = ((func_calc_hashing(valor)+aux)%tamanho);
            cont++;
        }
        vetor[f] = valor;
    }
}

void Sond_quad::imprimir()
{
    for(int i=0;i<tamanho;++i)
    {
        cout << "Indice " << i << ": " << vetor[i] << endl;
    }
}
