#include "binary_tree.h"
int main(){
    BTree tree1(1);
    tree1.addLeftChild(tree1.root, 2);
    tree1.addRightChild(tree1.root, 3);
    tree1.addLeftChild(tree1.root->L, 4);
    
    BTree tree2(1);
    tree2.addLeftChild(tree2.root, 2);
    tree2.addRightChild(tree2.root, 3);
    tree2.addLeftChild(tree2.root->L, 4);
    
    BTree tree3(1);
    tree3.addLeftChild(tree3.root, 2);
    tree3.addRightChild(tree3.root, 4);    
    tree3.addLeftChild(tree3.root->L, 4);

    std::cout<<"\ntree1 & tree2 post order travel and compare:\n";
    tree1.printNLR(tree1.root);
    std::cout<<"\n";
    tree2.printNLR(tree2.root);
    std::cout<<"\nis tree1 tree2 equal: "<<isEqual(tree1.root, tree2.root)<<std::endl;

    std::cout<<"\ntree1 & tree3 post order travel and compare:\n";
    tree1.printNLR(tree1.root);
    std::cout<<"\n";
    tree3.printNLR(tree3.root);
    std::cout<<"\nis tree1 tree3 equal: "<<isEqual(tree1.root, tree3.root)<<std::endl;
}