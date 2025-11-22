#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "sinhvien.h"
class Node{
public:
    SV data;
    Node *next;
    Node();
    Node(SV data, Node*next);
};
Node::Node(){
    this->next = NULL;
}
Node::Node(SV data, Node*next){
    this->data = data;
    this->next = next;
}
class DSSV{
public:
    Node *head;
    DSSV();
    ~DSSV();
    void insertToMid(Node *preNode, SV data);
    void insertToHead(SV data);
    void insertToLast(SV data);
    void deleteHead();
    void deleteLast();
    void deleteMid(Node *preNode);
    void print();
    int count();
    int countGPAOver3_2();
    void sortWithGPA();
    void insertWithOrder(SV data);
    int isSorted();
};


DSSV::DSSV(){
    this->head = NULL;
}
DSSV::~DSSV(){
    while(this->head != NULL){
        deleteHead();
    }
}

void DSSV::insertToMid(Node *preNode, SV data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = preNode->next;
    preNode->next = newNode;
}

void DSSV::insertToHead(SV data){
    Node *newNode = new Node;
    newNode->data = data;
    if(this->head == NULL){
        newNode->next = NULL;
        this->head = newNode;
        return;
    }
    newNode->next = this->head;
    this->head = newNode;
}

void DSSV::insertToLast(SV data){
    Node *newNode = new Node;
    Node *tempNode;
    tempNode = this->head;
    newNode->data = data;
    newNode->next = NULL;
    if(this->head == NULL){
        this->head = newNode;
        return;
    }
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void DSSV::deleteHead(){
    if(this->head == NULL){
        return;
    }
    Node *tempNode = this->head->next;
    delete this->head;
    this->head = tempNode;
}

void DSSV::deleteLast(){
    if(this->head == NULL){
        return;
    }
    Node *tempNode = this->head;
    Node *preNode;
    while(tempNode->next != NULL){
        preNode = tempNode;
        tempNode = tempNode->next;
    }
    preNode->next = NULL;
    delete tempNode;
}

void DSSV::deleteMid(Node *preNode){
    if(this->head == NULL){
        return;
    }
    Node *tempNode = preNode->next;
    preNode->next = tempNode->next;
    delete tempNode;    
}

void DSSV::print(){
    Node*tempNode;
    tempNode = this->head;
    while(tempNode != NULL){
        printf("\n______________________");
        printf("\nNode address:\t%p\n", tempNode);
        tempNode->data.print();
        tempNode = tempNode->next;
        printf("______________________\n");
    }
}
int DSSV::count(){
    Node *tempNode = this->head;
    int i = 0;
    while(tempNode != NULL){
        i++;
        tempNode = tempNode->next;
    }
    return i;
}
int DSSV::countGPAOver3_2(){
    Node *tempNode = this->head;
    int i = 0;
    while(tempNode != NULL){
        if(tempNode->data.GPA > 3.2)i++;
        tempNode = tempNode->next;
    }
    return i;
}
void DSSV::sortWithGPA(){
    Node *node_I;
    Node *node_J;
    int i,j;
    int n = this->count();
    for(i=0, node_I = this->head; i<n; i++, node_I = node_I->next){
        for(j=0, node_J = this->head; j<n-i-1; j++, node_J = node_J->next){
            if(node_J->data.GPA > node_J->next->data.GPA){
                SV temp;
                temp.cpyData(&(node_J->data));
                node_J->data.cpyData(&(node_J->next->data));
                node_J->next->data.cpyData(&(temp));
            }
        }
    }
}

void DSSV::insertWithOrder(SV data){
    if(this->isSorted() == 0){
        this->sortWithGPA();
    }
    Node *temp = this->head;
    while(temp->next != NULL){
        if(temp->next->data.GPA <= data.GPA)
            temp = temp->next;
        else{
            insertToMid(temp, data);
            return;
        }
    }
    insertToMid(temp, data);
    return;
}
int DSSV::isSorted(){
    int n = this->count();
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return 1;
    }
    Node *temp1, *temp2;
    temp1 = this->head;
    temp2 = this->head->next;
    while(temp2 != NULL){
        if(temp1->data.GPA > temp2->data.GPA){
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}
#endif