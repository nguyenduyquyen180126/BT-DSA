// #include "tree_ltkt.h"
#include "tree_ltmn.h"   
int main(){
    // Test cay tao bang luu tru ke tiep
    // Tree tree("A");
    // tree.addLeftChild(tree.root(), "A.1");
    // tree.addRightChild(tree.root(), "A.2");
    // tree.addLeftChild(tree.leftChild(tree.root()), "A.1.1");
    // tree.addRightChild(tree.leftChild(tree.root()), "A.1.2");
    // tree.addLeftChild(tree.rightChild(tree.root()), "A.2.1");
    // tree.addRightChild(tree.rightChild(tree.root()), "A.2.2");
    // std::cout << "Duyet cay theo cac kieu: " << std::endl;
    // std::cout << "NLR: ";
    // tree.NLR(tree.root()); // Kieu duyet NLR
    // std::cout << std::endl;
    // std::cout << "LNR: ";
    // tree.LNR(tree.root()); // Kieu duyet LNR
    // std::cout << std::endl;
    // std::cout << "LRN: ";
    // tree.LRN(tree.root()); // Kieu duyet LRN
    // std::cout << std::endl;
    // std::cout << "Cay duoc luu tru trong mang: ";
    // tree.printTreeAsArray(); // In cay duoc luu tru trong mang
    // return 0;
    Tree A("A");
    A.addLeftChild(A.root, "A.1");
    A.addRightChild(A.root, "A.2");
    A.addLeftChild(A.root->left, "A.1.1");
    A.addRightChild(A.root->left, "A.1.2");
    A.addLeftChild(A.root->right, "A.2.1");
    A.addRightChild(A.root->right, "A.2.2");
    std::cout << "Duyet cay theo cac kieu: " << std::endl;
    std::cout << "NLR: ";
    A.NLR(A.root); // Kieu duyet NLR
    std::cout << std::endl;
    std::cout << "LNR: ";
    A.LNR(A.root); // Kieu duyet LNR
    std::cout << std::endl;
    std::cout << "LRN: ";
    A.LRN(A.root); // Kieu duyet LRN
    std::cout << std::endl;
    return 0;
}
/*
    KET QUA CAY CAI DAT VOI MANG LUU TRU KE TIEP:
    Duyet cay theo cac kieu: 
    NLR: A  A.1  A.1.1  A.1.2  A.2  A.2.1  A.2.2  
    LNR: A.1.1  A.1  A.1.2  A  A.2.1  A.2  A.2.2  
    LRN: A.1.1  A.1.2  A.1  A.2.1  A.2.2  A.2  A  
    Cay duoc luu tru trong mang: A A.1 A.2 A.1.1 A.1.2 A.2.1 A.2.2 
*/
/*
    Duyet cay theo cac kieu: 
    NLR: A A.1 A.1.1 A.1.2 A.2 A.2.1 A.2.2 
    LNR: A.1.1 A.1 A.1.2 A A.2.1 A.2 A.2.2 
    LRN: A.1.1 A.1.2 A.1 A.2.1 A.2.2 A.2 A 
*/