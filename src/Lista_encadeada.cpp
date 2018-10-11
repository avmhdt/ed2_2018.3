#include <iostream>
#include "../headers/libraries.h"

using namespace std;

ListaEncadeada::ListaEncadeada(){
    primeiro = NULL;
};
ListaEncadeada::~ListaEncadeada(){
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}
void ListaEncadeada::insereInicio(int val){
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    primeiro = p;
}
void ListaEncadeada::insere(int val){
    comparacoes+=1;
    if(primeiro==NULL)
    {
        insereInicio(val);
    }
    else{
        No* no = primeiro;
        comparacoes+=1;
        while(no->getProx() != NULL){
            no = no->getProx();
        }
        No* u = new No;
        u->setInfo(val);
        u->setProx(NULL);
        no->setProx(u);
    }
}
void ListaEncadeada::imprimir(){
    if(primeiro == NULL)
    {
        cout << "A lista esta vazia";
    }
    else
    {
        No* aux = primeiro;
        while(aux->getProx() != NULL)
        {
            cout << "[" << aux->getInfo() << "]->";
            aux = aux->getProx();
        }
        cout << "[" << aux->getInfo() << "]";
    }
}
