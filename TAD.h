#ifndef HEADER_H
#define HEADER_H
#include "node.h"
class fila{
    private:
    Node *primeiro;
    Node *ultimo;
    int tam;
    public:
    int get_tamanho();
    void insere(int x,bool *ok);
    void retira(int *x, bool*ok);
    bool vazia();
    bool cheia();
    void destroi();
    fila();
    ~fila();
};

#endif