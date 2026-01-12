#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H
#include <string>
#include <iostream>
class Node{
public:
    std::string name = "No name";
    Node *next = nullptr;
    Node() = default;
    Node(std::string name);
};
Node::Node(std::string name){
    this->name = name;
    this->next = nullptr;
}
class Graph{
public:
    int v;                          // Index để đặt tên
    int num_of_vertex;
    Node ** adjList;
    void addVertex(std::string name);
    void addEdge(std::string name1, std::string name2);
    int getIndex(std::string name);
    void printGraph();
    Graph(int v);
    ~Graph();
};
int Graph::getIndex(std::string name){
    for(int i = 0; i < this->num_of_vertex; i++){
        if(this->adjList[i]->name == name)
        return i;
    }
    return -1;
}
Graph::Graph(int v){
    this->num_of_vertex = v;
    this->adjList = new Node*[v];
    this->v = 0;
}
/* Hàm đặt tên cho các vertex*/
void Graph::addVertex(std::string name){
    this->adjList[this->v] = new Node(name);
    this->v++;
}

void Graph::addEdge(std::string name1, std::string name2){
    Node *newNode = new Node(name1);
    // Chèn lên đầu
    newNode->next = this->adjList[this->getIndex(name2)]->next;
    this->adjList[this->getIndex(name2)]->next = newNode;

    newNode = new Node(name2);
    newNode->next = this->adjList[this->getIndex(name1)]->next;
    this->adjList[this->getIndex(name1)]->next = newNode;
}
Graph::~Graph(){
    delete[] adjList;
}
void Graph::printGraph(){
    for(int i = 0; i < this->num_of_vertex; i++){
        Node *temp = this->adjList[i];
        while(temp != nullptr){
            if(temp->next == nullptr)
                std::cout<<temp->name;
            else
                std::cout<<temp->name<<" -> ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }
}
#endif