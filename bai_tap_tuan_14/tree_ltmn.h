#ifndef TREE_LTMN_H
#define TREE_LTMN_H
#include <string>
#include <iostream>
class Node{
public:
    std::string data;
    Node* left;
    Node* right;
    Node(std::string value);
    void printNode();

};
Node::Node(std::string value){
    this->data = value;
    this->left = nullptr;
    this->right = nullptr;
}
void Node::printNode(){
    std::cout << this->data << " ";
}
class Tree{
public:
    Node* root;
    Tree();
    Tree(std::string data);
    int IsEmpty();
    void addLeftChild(Node* parent, std::string value);
    void addRightChild(Node* parent, std::string value);
    void NLR(Node* p); // Duyet NLR
    void LNR(Node* p); // Duyet LNR
    void LRN(Node* p); // Duyet LRN
    ~Tree();
};
Tree::Tree(){
    this->root = nullptr;
}
Tree::Tree(std::string data){
    this->root = new Node(data);
}
Tree::~Tree(){

}
int Tree::IsEmpty(){
    return this->root == nullptr;
}
void Tree::addLeftChild(Node* parent, std::string value){
    if(parent->left != nullptr){
        return;
    }
    parent->left = new Node(value);
}
void Tree::addRightChild(Node* parent, std::string value){
    if(parent->right != nullptr){
        return;
    }
    parent->right = new Node(value);
}
void Tree::NLR(Node* p){
    if(p == nullptr){
        return;
    }
    p->printNode();
    NLR(p->left);
    NLR(p->right);
}
void Tree::LNR(Node* p){
    if(p == nullptr){
        return;
    }
    LNR(p->left);
    p->printNode();
    LNR(p->right);
}
void Tree::LRN(Node* p){
    if(p == nullptr){
        return;
    }
    LRN(p->left);
    LRN(p->right);
    p->printNode();
}
#endif