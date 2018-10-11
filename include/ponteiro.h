#ifndef PONTEIRO_H
#define PONTEIRO_H

class ponteiro
{
    public:
        ponteiro();
        ~ponteiro();
        int getChave();
        void setChave(int val);
        ponteiro* getProx();
        void setProx(ponteiro* novo);
        int getEnde();
        void setEnde(int val);
    private:
        ponteiro* prox;
        int chave;
        int endereco;
};

#endif // PONTEIRO_H
