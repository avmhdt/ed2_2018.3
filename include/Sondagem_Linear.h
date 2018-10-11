#ifndef SONDAGEM_LINEAR_H
#define SONDAGEM_LINEAR_H

class Sondagem_Linear
{
    public:
        Sondagem_Linear(int tam);
        ~Sondagem_Linear();
        void insere_sond_linear(int valor);
        void imprimir();
        int comparacoes;
    private:
        int func_sond_linear(int valor);
        int tamanho;
        int *vetor;
};

#endif // SONDAGEM_LINEAR_H
