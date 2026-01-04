#include "binary_tree.h"
int main(){
    BTree tree(4);
    tree.addLeftChild(tree.root, 1);
    tree.addRightChild(tree.root, 3);
    
    tree.addLeftChild(tree.root->L, 2);
    tree.addRightChild(tree.root->L, 16);

    tree.addLeftChild(tree.root->R, 9);
    tree.addRightChild(tree.root->R, 10);
    
    tree.addLeftChild(tree.root->L->L, 14);
    tree.addRightChild(tree.root->L->L, 8);

    tree.addLeftChild(tree.root->L->R, 7);

    std::cout<<"\nYeu cau 1:\n";
    std::cout<<"LRN"<<std::endl;
    tree.printLRN(tree.root);
    std::cout<<"\n";
    std::cout<<"LNR"<<std::endl;
    tree.printLNR(tree.root);
    std::cout<<"\n";
    std::cout<<"NLR"<<std::endl;
    tree.printNLR(tree.root);
    std::cout<<"\n";

    std::cout<<"\nYeu cau 2:\n";
    
    std::cout<<"Vun cay\n";
    vunDong(tree.root);
    tree.printNLR(tree.root);
    std::cout<<'\n';
}