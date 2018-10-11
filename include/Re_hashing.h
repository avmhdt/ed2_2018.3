#ifndef RE_HASHING_H
#define RE_HASHING_H

class Re_hashing
{
public:
    Re_hashing(int tam);
    ~Re_hashing();
    void inserir_rehashing(int valor);
    void imprimir();
    int comparacoes;
private:
    int func_calc_hashing(int valor);
    int func2_calc_hashing(int valor);
    int tamanho;
    int *vetor;

};

#endif // RE_HASHING_H
