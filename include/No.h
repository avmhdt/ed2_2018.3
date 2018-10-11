#ifndef NO_H
#define NO_H

class No
{
public:
    No();
    ~No();
    int getInfo();
    No* getProx();
    void setInfo(int novo);
    void setProx(No* novoNo);
private:
    int info;
    No *Prox;
};


#endif // NO_H
