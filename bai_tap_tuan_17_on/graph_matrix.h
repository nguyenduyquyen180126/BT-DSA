#ifndef GRAPH_H
#define GRAPH_H
#include <string>
class Graph{
public:
    int v = 0;             // Biến để đặt tên
    int numOfVertex = 0;
    int **adjMatrix = nullptr;
    std::string *indexToName = nullptr;
    void addVertex(std::string name);
    void addEdge(std::string name1, std::string name2);
    int getIndex(std::string name);
    Graph(int numOfVertex);
    void printMatrix();
    ~Graph();
};
Graph::Graph(int numOfVertex){
    this->numOfVertex = numOfVertex;
    this->adjMatrix = new int *[numOfVertex];
    for(int i = 0; i < numOfVertex; i++){
        adjMatrix[i] = new int [numOfVertex];
        for(int j = 0; j < numOfVertex; j++){
            adjMatrix[i][j] = 0;
        }
    }
    this->indexToName = new std::string[numOfVertex];
}
Graph::~Graph(){
    for(int i = 0; i < numOfVertex; i++){
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] indexToName;
}
/*Hàm đặt tên cho các đỉnh*/
void Graph::addVertex(std::string name){
    this->indexToName[v++] = name;
}
void Graph::addEdge(std::string name1, std::string name2){
    this->adjMatrix[this->getIndex(name1)][this->getIndex(name2)] = 1;
    this->adjMatrix[this->getIndex(name2)][this->getIndex(name1)] = 1;
}
int Graph::getIndex(std::string name){
    for(int i = 0; i < numOfVertex; i++){
        if(indexToName[i] == name){
            return i;
        }
    }
    return -1;
}
void Graph::printMatrix() {
    printf("Ma tran ke:\n");
    for (int i = 0; i < numOfVertex; i++) {
        for (int j = 0; j < numOfVertex; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
#endif