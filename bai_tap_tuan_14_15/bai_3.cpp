#include "binary_tree.h"
int main(){
    BSTree bst;
    // Chèn các node có giá trị dưới đây
    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);

    Node *root = bst.search(5);
    std::cout<<"duyet cay thu tu truoc"<<std::endl;
    PREORDER_travl(root);
    std::cout<<std::endl;
    // Tim 2 node co gia tri 4 va 9
    Node *n1 = bst.search(4);
    Node *n2 = bst.search(9);
    // In ket qua tim kiem
    if(n1 != nullptr){
        std::cout<<"Node co gia tri = 4 la "<<n1->data<<std::endl;
    }
    if(n2 == nullptr){
        std::cout << "Khong tim thay node co gia tri =9" <<std::endl;
    }
    // Lam rong cay
    bst.makeEmpty();
    if(bst.isEmpty()){
        std::cout<<"Cay da bi xoa"<<std::endl;
    }
    return 0;
}