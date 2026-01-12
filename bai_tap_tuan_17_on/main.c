// #include "graph_list.h"
#include "graph_matrix.h"
int main(){
    // Graph graph(11);
    // graph.addVertex("Ha Noi");
    // graph.addVertex("Hai Duong");
    // graph.addVertex("Hai Phong");
    // graph.addVertex("Uong bi");
    // graph.addVertex("Bac Giang");
    // graph.addVertex("Bac Ninh");
    // graph.addVertex("Thai Nguyen");
    // graph.addVertex("Son Tay");
    // graph.addVertex("Hoa Binh");
    // graph.addVertex("Phu Ly");
    // graph.addVertex("Hung Yen");
    // graph.addEdge("Ha Noi", "Bac Ninh");
    // graph.addEdge("Ha Noi", "Hai Duong");
    // graph.addEdge("Ha Noi", "Thai Nguyen");
    // graph.addEdge("Ha Noi", "Hoa Binh");
    // graph.addEdge("Phu Ly", "Hung Yen");
    // graph.printGraph();
    Graph graph(11);
    graph.addVertex("Ha Noi");
    graph.addVertex("Hai Duong");
    graph.addVertex("Hai Phong");
    graph.addVertex("Uong bi");
    graph.addVertex("Bac Giang");
    graph.addVertex("Bac Ninh");
    graph.addVertex("Thai Nguyen");
    graph.addVertex("Son Tay");
    graph.addVertex("Hoa Binh");
    graph.addVertex("Phu Ly");
    graph.addVertex("Hung Yen");
    
    graph.addEdge("Ha Noi", "Hai Duong");
    graph.addEdge("Ha Noi", "Thai Nguyen");
    graph.addEdge("Ha Noi", "Hoa Binh");
    graph.addEdge("Phu Ly", "Hung Yen");

    graph.printMatrix();
}