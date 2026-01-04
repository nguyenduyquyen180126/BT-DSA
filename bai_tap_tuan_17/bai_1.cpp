#include "tree.h"
int main(){
    ToC book("Book1");
    book.addChapter("A");
    book.addChapter("B");
    book.addChapter("C");
    book.addSection(1, "1");
    book.addSection(1, "2", 3);
    book.addSection(2, "1", 3);
    book.addSection(3, "1", 3);
    book.addSection(3, "2", 3);
    book.addSubsection(1, 1, "1.1", 4);
    NLR(book.root);

    std::cout<<"Yeu cau 1:\n";
    std::cout<<"\nThe number of chapter "<<book.findNumOfChapter()<<std::endl;
    
    std::cout<<"Yeu cau 2:\n";
    std::cout<<"\nThe longest chapter "<<book.findLongestChapter()->header<<std::endl;
    
    std::cout<<"Yeu cau 3:\n";
    book.deleteElement(Section, 1, 2);
    std::cout<<"\nAfter delete\n";
    NLR(book.root);

    std::cout<<"Yeu cau 4:";
    std::cout<<"\nTim chuong va in de muc\n";
    book.printChapterInfo(book.findChapter(2));
}