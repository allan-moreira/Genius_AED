#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
typedef struct Node* NodePtr;

class Node{
    private:
        int elemento;
        Node *ponteiro;
    public:
        Node();
        ~Node();
        void setPointer(NodePtr n,bool *deucerto);
        Node *getPointer();
        int getElemento();
        void setElemento(int elemento);
        
};




#endif