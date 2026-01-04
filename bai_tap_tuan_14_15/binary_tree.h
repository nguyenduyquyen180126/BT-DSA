#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <errno.h>
#include <stdio.h>
class Node{
public:
    int data;
    Node *L;
    Node *R;
    Node(int data);
    Node(int v, Node *l, Node *r);
    void print();
};
Node::Node(int v, Node *l, Node *r){
    this->data = v;
    this->L = l;
    this->R = r;
}
Node::Node(int data){
    this->data = data;
    this->L = nullptr;
    this->R = nullptr;
}
void Node::print(){
    std::cout<<data<<' ';
}
class BTree{
public:    
    Node *root = nullptr;
    BTree(int data);
    BTree() = default;
    int addLeftChild(Node *p, int data);
    int addRightChild(Node *p, int data);
    void printLRN(Node *p);
    void printNLR(Node *p);
    void printLNR(Node *p);
    ~BTree();
};
BTree::BTree(int data){
    this->root = new Node(data);
}
int BTree::addLeftChild(Node *p, int data){
    if(p->L != nullptr){
        fprintf(stderr, "This node has left child");
        return 0;
    }
    p->L = new Node(data);
    return 1;
}
int BTree::addRightChild(Node *p, int data){
    if(p->R != nullptr){
        fprintf(stderr, "This node has right child");
        return 0;
    }
    p->R = new Node(data);
    return 1;
}
void freeTree(Node *p){
    if(p == nullptr){
        return;
    }
    freeTree(p->L);
    freeTree(p->R);
    delete p;
}
BTree::~BTree(){
    freeTree(this->root);
}
void BTree::printLRN(Node *p){
    if(p == nullptr){
        return;
    }
    printLRN(p->L);
    printLRN(p->R);
    p->print();
}
void BTree::printNLR(Node *p){
    if(p == nullptr){
        return;
    }
    p->print();
    printNLR(p->L);
    printNLR(p->R);
}
void BTree::printLNR(Node *p){
    if(p == nullptr){
        return;
    }
    printLNR(p->L);
    p->print();
    printLNR(p->R);
}
void adjust(Node *root){
    if(root == nullptr){
        return;
    }
    Node *largest = root;
    if(root->L != nullptr && root->L->data > root->data){
        largest = root->L;
    }
    else if(root->R != nullptr && root->R->data > root->data){
        largest = root->R;
    }
    if(largest != root){
        int temp = root->data;
        root->data = largest->data;
        largest->data = temp;
        adjust(largest);
    }
}
void vunDong(Node *p){
    if(p == nullptr){
        return;
    }
    vunDong(p->L);
    vunDong(p->R);
    adjust(p);
}
bool isEqual(Node *p1, Node *p2){
    if(p1 == nullptr && p2 == nullptr){
        return true;
    }
    if(p1 == nullptr || p2 == nullptr){
        return false;
    }
    return (p1->data == p2->data) && isEqual(p1->L, p2->L) && isEqual(p1->R, p2->R);
}

class BSTree{
private:
    Node *root;
public:
    BSTree(){
        root = NULL;
    }
    ~BSTree(){

    }
    bool isEmpty(){
        if(root == nullptr){
            return true;
        }
        return false;
    }
    void makeEmpty(){
        makeEmpty(root);
        root = nullptr;
    }
    void insert(int val){
        return insert(val, root);
    }
    Node *search(int val){
        return search(val, root);
    }
    void makeEmpty(Node *& t){
        if(t == nullptr){
            return;
        }
        makeEmpty(t->L);
        makeEmpty(t->R);
        delete t;
    }
    void insert(int val, Node *& t){
        if(t == nullptr){
            t = new Node(val);
            return;
        }
        else{
            if(val >= t->data){
                insert(val, t->R);
            }
            else{
                insert(val, t->L);
            }
        }
    }
    Node* search(int val, Node *t){
        if(t != nullptr){
            if(t->data == val){
                return t;
            }
            if(t->data < val){
                return search(val, t->R);
            }
            else{
                return search(val, t->L);
            }
        }
        return nullptr;
    }
};
void PREORDER_travl(Node *t){
    if(t == nullptr){
        return;
    }
    t->print();
    PREORDER_travl(t->L);
    PREORDER_travl(t->R);
}
void INORDER_travl(Node *t){
    if(t == nullptr){
        return;
    }
    PREORDER_travl(t->L);
    t->print();
    PREORDER_travl(t->R);
}
void POSTORDER_travl(Node *t){
    if(t == nullptr){
        return;
    }
    PREORDER_travl(t->L);
    PREORDER_travl(t->R);
    t->print();
}
#endif