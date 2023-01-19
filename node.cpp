#include "node.h"

Node::Node(){
    this->elemento ='\0';
    this->ponteiro = NULL;
}
Node::~Node(){
    
}

Node *Node::getPointer(){
    return this->ponteiro;
}

int Node::getElemento(){
    return this->elemento;
}

void Node::setPointer(NodePtr n,bool *deucerto){
    this->ponteiro = n;
    *deucerto = true;
}


void Node::setElemento(int _elemento){
    this->elemento = _elemento;
}