#ifndef SOND_QUAD_H
#define SOND_QUAD_H

class Sond_quad {
public:
    Sond_quad(int tam);
    ~Sond_quad();
    void inserir_func_quadratica(int valor);
    void imprimir();
    int comparacoes;
private:
    int func_calc_hashing(int valor);
    int tamanho;
    int *vetor;

};

#endif // SOND_QUAD_H
