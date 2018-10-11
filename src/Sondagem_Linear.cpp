#include <iostream>
#include "../headers/libraries.h"

Sondagem_Linear::Sondagem_Linear(int tam)
{
    tamanho = tam;
    vetor = new int[tam];
    for(int i=0;i<tam;++i)
    {
        vetor[i]=0;
    }
}

Sondagem_Linear::~Sondagem_Linear()
{
    delete []vetor;
}

int Sondagem_Linear::func_sond_linear(int valor)
{
    return valor%tamanho;
}

void Sondagem_Linear::insere_sond_linear(int valor)
{
    int f = func_sond_linear(valor);
    comparacoes+=1;
    if(vetor==0)
    {
        vetor[f] = valor;
    }
    else
    {
        comparacoes+=1;
        while(vetor[f]!=0)
        {
            if(f<tamanho-1)
            {
                f++;
            }
            else
            {
                f=0;
            }
        }
        vetor[f]=valor;
    }
}

void Sondagem_Linear::imprimir()
{
    for(int i=0;i<tamanho;++i)
    {
        cout << "Indice " << i << ": " << vetor[i] << endl;
    }
}
