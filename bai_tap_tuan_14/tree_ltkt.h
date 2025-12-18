#ifndef TREE_LTKT_H
#define TREE_LTKT_H

#include <string>
#include <iostream>
#define MAXLENGTH 100
#define NIL -1 // Dấu hiệu chỉ con trỏ rỗng

class Tree{
public:
    std::string data[MAXLENGTH];
    int maxNode;
    Tree();
    Tree(std::string data);// Khoi tao cay voi goc
    int IsEmpty();
    int root();
    int leftChild(int p);
    int rightChild(int p);
    int addLeftChild(int p, std::string value);
    int addRightChild(int p, std::string value);
    void printTreeAsArray();
    int parent(int p);
    void NLR(int p); // Duyet NLR
    void LNR(int p); // Duyet LNR
    void LRN(int p); // Duyet LRN
};
#endif
Tree::Tree(std::string data){
    this->data[0] = data;
    this->maxNode = 1;
}
Tree::Tree(){
    maxNode = 0;
}
int Tree::IsEmpty(){
    return this->maxNode == 0;
}
int Tree::root(){
    if(this->IsEmpty()){
        return NIL;
    }
    return 0;
}
int Tree::leftChild(int p){
    int left = 2*p + 1;
    if(left >= this->maxNode){
        return NIL;
    }
    return left;
}
int Tree::rightChild(int p){
    int right = 2*p + 2;
    if(right >= this->maxNode){
        return NIL;
    }
    return right;
}
int Tree::parent(int p){
    if(p <= 0 || p >= this->maxNode){
        return NIL;
    }
    return (p - 1) / 2;
}
int Tree::addLeftChild(int p, std::string value){
    int left = this->leftChild(p);
    if(left != NIL){
        return 0; 
    }
    left = 2*p + 1;
    if(left >= MAXLENGTH){
        return 0; 
    }
    this->data[left] = value;
    if(left >= this->maxNode){
        this->maxNode = left + 1;
    }
    return 1; 
}
int Tree::addRightChild(int p, std::string value){
    int right = this->rightChild(p);
    if(right != NIL){
        return 0; 
    }
    right = 2*p + 2;
    if(right >= MAXLENGTH){
        return 0; 
    }
    this->data[right] = value;
    if(right >= this->maxNode){
        this->maxNode = right + 1;
    }
    return 1; 
}
void Tree::printTreeAsArray(){
    for(int i = 0; i < this->maxNode; i++){
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}

void Tree::NLR(int p){
    if(p == NIL){
        return;
    }
    std::cout << this->data[p] << "  ";
    NLR(this->leftChild(p));
    NLR(this->rightChild(p));
}

void Tree::LNR(int p){
    if(p == NIL){
        return;
    }
    LNR(this->leftChild(p));
    std::cout << this->data[p] << "  ";
    LNR(this->rightChild(p));
}

void Tree::LRN(int p){
    if(p == NIL){
        return;
    }
    LRN(this->leftChild(p));
    LRN(this->rightChild(p));
    std::cout << this->data[p] << "  ";
}