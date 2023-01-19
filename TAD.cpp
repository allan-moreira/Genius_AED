#include "TAD.h"

fila::fila(){
    this->primeiro = NULL;
    this->ultimo = NULL;
    this->tam = 0;
}

fila::~fila(){
    int x=0;
    bool ok = true;
    while(ok==true){
        this->retira(&x,&ok);
    }
}

int fila::get_tamanho(){
    return this->tam;
}

bool fila::vazia(){
    if(this->primeiro==NULL){
        return true;
    }
    return false;
}

bool fila::cheia(){
    return false;
    //Não sei checar memória em cpp
}


void fila::insere(int x,bool *ok){
    this->tam++;
    if(this->vazia()){
        NodePtr n1;
        n1 = new Node;
        this->primeiro = n1;
        this->ultimo = n1;
        *ok = true;
        n1->setElemento(x);
    }
    else{
        NodePtr n1;
        bool a;
        n1 = new Node;
        this->ultimo->setPointer(n1,&a);
        this->ultimo = n1;
        n1->setElemento(x);
        *ok = true;
    }
}


void fila::retira(int *x, bool* ok){
    NodePtr anterior;
    if(this->vazia()==false){
        this->tam--;
        if(this->primeiro==this->ultimo){
            *x = this->primeiro->getElemento();
            delete this->primeiro;
            this->primeiro = NULL;
            this->ultimo = NULL;
        }
        else{
            *x = this->primeiro->getElemento();
            anterior = this->primeiro;
            this->primeiro=this->primeiro->getPointer();
            delete anterior;
        }
    }
    else{
        *ok = false;
    }
}

void fila::destroi(){
    int valor;
    bool ok;
    while(this->vazia() == false){
        this->retira(&valor, &ok);
    }
}

