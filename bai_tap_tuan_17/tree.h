#ifndef TREE_H
#define TREE_H
#include <string>
#include <iostream>
/*
    Mục lục được lưu trữ bằng cây nhị phân được chuyển từ 1 cây cơ bản
    root chỉ cuốn sách->chapter->...
*/
enum NodeType{
    Root,
    Chapter,
    Section,
    Subsection,
    Subsubsection
};
class Node{
public:
    int index = 0;
    NodeType type;
    std::string header = "";
    int startPape = 0;
    int endPape = 0;
    int papeNum = 0;
    Node *R = nullptr; // Xuống cấp thấp hơn
    Node *L = nullptr; // Đi sang cấp tương đương
    Node(int index, NodeType type, std::string header, int startPape, int endPape);
    Node(int index, NodeType type, std::string header, int papeNum);
    Node(int index, NodeType type, std::string header);
    Node(std::string header);
};
// Table of Content
class ToC{
public: 
    Node *root = nullptr;
    ToC(std::string header);
    ~ToC();
    void addChapter(std::string header);
    void addSection(int indexChapter, std::string header, int papeNum = 0);
    Node* findChapter(int index);
    void update();
    Node* findSection(int indexChapter, int indexSection);
    void addSubsection(int indexChapter, int indexSection, std::string header, int papeNum = 0);
    Node* findSubsection(int indexChapter, int indexSection, int indexSubsection);
    void addSubsubsection(int indexChapter, int indexSection, int indexSubsection, std::string header, int papeNum);
    Node* findLongestChapter();
    int findNumOfChapter();
    void deleteElement(NodeType type, int index1 = 0, int index2 = 0, int index3 = 0, int index4 = 0);
    Node* findSubsubsection(int indexChapter, int indexSection, int indexSubsection, int indexSubsubsection);
    void printChapterInfo(Node *chapter);
    void isCopyOf(ToC *other);
};
Node::Node(int index, NodeType type, std::string header, int startPape, int endPape){
    this->index = index;
    this->type = type;
    this->header = header;
    this->startPape = startPape;
    this->endPape = endPape;
}
Node::Node(int index, NodeType type, std::string header, int papeNum){
    this->index = index;
    this->type = type;
    this->header = header;
    this->papeNum = papeNum;
}
Node::Node(std::string header){
    this->type = Root;
    this->header = header;
}
Node::Node(int index, NodeType type, std::string header){
    this->index = index;
    this->type = type;
    this->header = header;
}
ToC::ToC(std::string header){
    this->root = new Node(header);
}
void ToC::addChapter(std::string header){
    if(this->root->L == nullptr){
        this->root->L = new Node(1, Chapter, header);
        this->update();
        return;
    }
    Node *temp = this->root->L;
    int index = 1;
    while(temp->R != nullptr){
        temp = temp->R;
        index++;
    }
    temp->R = new Node(index + 1, Chapter, header);
    this->update();
}
void ToC::addSection(int indexChapter, std::string header, int papeNum){
    Node *p = this->findChapter(indexChapter);
    if(p == nullptr){
        printf("Khong the add section vao %d\n", indexChapter);
        return;
    }
    if(p->L == nullptr){
        p->L = new Node(1, Section, header, papeNum);
        this->update();
        return;
    }
    Node *temp = p->L;
    int index = 1;
    while(temp->R != nullptr){
        temp = temp->R;
        index++;
    }
    temp->R = new Node(index + 1, Section, header, papeNum);
    this->update();

}
Node *ToC::findChapter(int index){
    Node *temp = root;
    while(temp != nullptr && temp->type != Chapter){
        temp = temp->L;
    }
    while(temp != nullptr && temp->index != index){
        temp = temp->R;
    }
    return temp;
}
Node *ToC::findSection(int indexChapter, int indexSection){
    Node *temp = findChapter(indexChapter);
    while(temp != nullptr && temp->type != Section){
        temp = temp->L;
    }
    while(temp != nullptr && temp->index != indexSection){
        temp = temp->R;
    }
    return temp;
}
void ToC::addSubsection(int indexChapter, int indexSection, std::string header, int papeNum){
    Node *p = this->findSection(indexChapter, indexSection);
    if(p == nullptr){
        printf("Khong the add Subsection vao %d/%d\n", indexChapter, indexSection);
        return;
    }
    if(p->L == nullptr){
        p->L = new Node(1, Subsection, header, papeNum);
        this->update();
        return;
    }
    Node *temp = p->L;
    int index = 1;
    while(temp->R != nullptr){
        temp = temp->R;
        index++;
    }
    temp->R = new Node(index + 1, Subsection, header, papeNum);
    this->update();

}
Node* ToC::findSubsection(int indexChapter, int indexSection, int indexSubsection){
    Node *temp = findSection(indexChapter, indexSection);
    while(temp != nullptr && temp->type != Subsection){
        temp = temp->L;
    }
    while(temp != nullptr && temp->index != indexSubsection){
        temp = temp->R;
    }
    return temp;
}
void ToC::addSubsubsection(int indexChapter, int indexSection, int indexSubsection, std::string header, int papeNum){
    Node* p = findSubsection(indexChapter, indexSection, indexSubsection);
    if(p == nullptr){
        printf("Khong the Subsubsection vao %d/%d/%d\n", indexChapter, indexSection, indexSubsection);
        return;
    }
    if(p->L == nullptr){
        p->L = new Node(1, Subsubsection, header, papeNum);
        this->update();
        return;
    }
    Node *temp = p->L;
    int index = 1;
    while(temp->R != nullptr){
        temp = temp->R;
        index++;
    }
    temp->R = new Node(index + 1, Subsection, header, papeNum);
    this->update();

}
void NLR(Node *p){
    if(p == nullptr){
        return;
    }
    if(p->type == Root){
        std::cout<<'\"'<<p->header<<'\"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    else if(p->type == Chapter){
        std::cout<<"\tChuong "<<p->index<<": "<<'\"'<<p->header<<'\"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    else if(p->type == Section){
        std::cout<<"\t\t"<<p->index<<". "<<'\"'<<p->header<<'\"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    else if(p->type == Subsection){
        std::cout<<"\t\t\t"<<p->index<<". "<<'\"'<<p->header<<'\"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    else if(p->type == Subsubsection){
        std::cout<<"\t\t\t\t"<<p->index<<". "<<'\"'<<p->header<<'\"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    NLR(p->L);
    NLR(p->R);
}

void deleteNodes(Node* node){
    if(node == nullptr) return;
    
    deleteNodes(node->L);
    deleteNodes(node->R);
    
    delete node;
}

ToC::~ToC(){
    deleteNodes(root);
    root = nullptr;
}


void updateNodeRecursive(Node* node, int& currentPage){
    if(node == nullptr) return;
    

    node->startPape = currentPage;
    
    if(node->L != nullptr){

        updateNodeRecursive(node->L, currentPage);

        node->papeNum = currentPage - node->startPape;
        node->endPape = currentPage - 1;
    } 
    else{
        if(node->papeNum > 0){
            currentPage += node->papeNum;
            node->endPape = currentPage - 1;
        } 
        else{
            node->endPape = node->startPape;
        }
    }
    
    updateNodeRecursive(node->R, currentPage);
}

void ToC::update(){
    if(root == nullptr || root->L == nullptr) return;
    
    int currentPage = 1;
    
    updateNodeRecursive(root->L, currentPage);

    root->startPape = 1;
    root->endPape = currentPage - 1;
    root->papeNum = currentPage - 1;
}
Node *ToC::findLongestChapter(){
    Node *temp = this->root->L;
    Node *longest = temp;
    if(temp == nullptr){
        return nullptr;
    }
    while(temp->R != nullptr){
        temp = temp->R;
        if(longest->papeNum < temp->papeNum){
            longest = temp;
        }
    }
    return longest;
}
int ToC::findNumOfChapter(){
    Node *temp = this->root->L;
    if(temp == nullptr){
        return 0;
    }
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->R;
    }
    return count;
}


void reindexNodes(Node* start, int startIndex = 1){
    Node* temp = start;
    int idx = startIndex;
    while(temp != nullptr){
        temp->index = idx++;
        temp = temp->R;
    }
}

void ToC::deleteElement(NodeType type, int index1, int index2, int index3, int index4){
    if(type == Chapter){
        Node *delNode = this->findChapter(index1);
        if(delNode == nullptr){
            printf("Chapter %d not found\n", index1);
            return;
        }
        std::cout<<"Xoa chapter co index "<<index1<<": "<<'\"'<<delNode->header<<'\"'<<std::endl;
        if(index1 == 1){
            this->root->L = delNode->R;
        } 
        else{
            Node *prev = this->findChapter(index1 - 1);
            if(prev != nullptr){
                prev->R = delNode->R;
            }
        }
        
        delNode->R = nullptr; 
        deleteNodes(delNode);
        reindexNodes(this->root->L, 1);
        this->update();
    }
    else if(type == Section){
        Node *parent = this->findChapter(index1);
        if(parent == nullptr || parent->L == nullptr){
            printf("Section %d/%d not found\n", index1, index2);
            return;
        }
        
        Node *delNode = this->findSection(index1, index2);
        if(delNode == nullptr){
            printf("Section %d/%d not found\n", index1, index2);
            return;
        }
        std::cout<<"Xoa section "<<index1<<'.'<<index2<<": "<<'\"'<<delNode->header<<'\"'<<std::endl;

        if(index2 == 1){
            parent->L = delNode->R;
        } 
        else{
            Node *prev = this->findSection(index1, index2 - 1);
            if(prev != nullptr) {
                prev->R = delNode->R;
            }
        }
        
        delNode->R = nullptr;
        deleteNodes(delNode);
        reindexNodes(parent->L, 1);
        this->update();
    }
    else if(type == Subsection){
        Node *parent = this->findSection(index1, index2);
        if(parent == nullptr || parent->L == nullptr){
            printf("Subsection %d/%d/%d not found\n", index1, index2, index3);
            return;
        }
        
        Node *delNode = this->findSubsection(index1, index2, index3);
        if(delNode == nullptr) {
            printf("Subsection %d/%d/%d not found\n", index1, index2, index3);
            return;
        }
        std::cout<<"Xoa subsection "<<index1<<'.'<<index2<<'.'<<index3<<": "<<'\"'<<delNode->header<<'\"'<<std::endl;
        
        if(index3 == 1) {
            parent->L = delNode->R;
        } 
        else{
            Node *prev = this->findSubsection(index1, index2, index3 - 1);
            if(prev != nullptr) {
                prev->R = delNode->R;
            }
        }
        
        delNode->R = nullptr;
        deleteNodes(delNode);
        reindexNodes(parent->L, 1);
        this->update();
    }
    else if(type == Subsubsection){
        Node *parent = this->findSubsection(index1, index2, index3);
        if(parent == nullptr || parent->L == nullptr){
            printf("Subsubsection %d/%d/%d/%d not found\n", index1, index2, index3, index4);
            return;
        }
        
        Node *delNode = this->findSubsubsection(index1, index2, index3, index4);
        if(delNode == nullptr){
            printf("Subsubsection %d/%d/%d/%d not found\n", index1, index2, index3, index4);
            return;
        }
        std::cout<<"Xoa subsubsection "<<index1<<'.'<<index2<<'.'<<index3<<'.'<<index4<<": "<<'\"'<<delNode->header<<'\"'<<std::endl;
        if(index4 == 1){
            parent->L = delNode->R;
        } 
        else{
            Node *prev = this->findSubsubsection(index1, index2, index3, index4 - 1);
            if(prev != nullptr){
                prev->R = delNode->R;
            }
        }
        
        delNode->R = nullptr;
        deleteNodes(delNode);
        reindexNodes(parent->L, 1);
        this->update();
    }
}
Node* ToC::findSubsubsection(int indexChapter, int indexSection, int indexSubsection, int indexSubsubsection){
    Node *temp = findSubsection(indexChapter, indexSection, indexSubsection);
    while(temp != nullptr && temp->type == Subsubsection){
        temp = temp->L;
    }
    while(temp->index != indexSubsubsection && temp != nullptr){
        temp = temp->R;
    }
    return temp;
}


void printChapterRecursive(Node *p, int index){
    if(p == nullptr || (p->type == Chapter && p->index != index)){
        return;
    }
    if(p->type == Chapter){
        std::cout<<p->index<<". "<<'"'<<p->header<<'"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    else if(p->type == Section){
        std::cout<<"\t"<<p->index<<". "<<'"'<<p->header<<'"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    else if(p->type == Subsection){
        std::cout<<"\t\t"<<p->index<<". "<<'"'<<p->header<<'"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    else if(p->type == Subsubsection){
        std::cout<<"\t\t\t"<<p->index<<". "<<'"'<<p->header<<'"'<<" | "<<p->papeNum<<" pages (tr"<<p->startPape<<"-tr"<<p->endPape<<")"<<std::endl;
    }
    printChapterRecursive(p->L, index);
    printChapterRecursive(p->R, index);
}

void ToC::printChapterInfo(Node *chapter){
    if(chapter->type != Chapter){
        std::cout<<"\nKhong phai chapter de in thong tin\n";
        return;
    }
    std::cout<<"In thong tin chapter: "<<chapter->index<<": \""<<chapter->header<<"\""<<std::endl;
    printChapterRecursive(chapter, chapter->index);
}
bool isEqualRecursive(Node *p1, Node *p2){
    if(p1 == nullptr && p2 == nullptr){
        return true;
    }
    else if(p1 == nullptr || p2 == nullptr){
        return false;
    }
    if(p1->index != p2->index || p1->header != p2->header){
        return false;
    }
    return isEqualRecursive(p1->L, p2->L) && isEqualRecursive(p1->R, p2->R);
}
void ToC::isCopyOf(ToC *other){
    if(this->root == nullptr && other->root == nullptr){
        std::cout<<"\nHai cay rong\n";
    }
    if(this->root == nullptr || other->root == nullptr){
        std::cout<<"\nMot trong 2 cay rong\n";
    }
    if(isEqualRecursive(this->root->L, other->root->L)){
        std::cout<<this->root->header<<" va "<<other->root->header<<" Hai cuon sach la ban copy cua nhau"<<std::endl;
    }
    else{
        std::cout<<this->root->header<<" va "<<other->root->header<<" Hai cuon sach khong phai ban copy cua nhau"<<std::endl;
    }
}
#endif