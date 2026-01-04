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

    ToC book1("Book2");
    book1.addChapter("A");
    book1.addChapter("B");
    book1.addChapter("C");
    book1.addSection(1, "1");
    book1.addSection(1, "2", 3);
    book1.addSection(2, "1", 3);
    book1.addSection(3, "1", 3);
    book1.addSection(3, "2", 3);
    book1.addSubsection(1, 1, "1.1", 4);
    NLR(book1.root);

    ToC book2("Book3");
    book2.addChapter("A");
    book2.addChapter("B");
    book2.addChapter("C");
    book2.addSection(1, "1");
    book2.addSection(1, "2", 3);
    // book2.addSection(2, "1", 3);
    book2.addSection(3, "1", 3);
    book2.addSection(3, "2", 3);
    book2.addSubsection(1, 1, "1.1", 4);
    NLR(book2.root);

    book1.isCopyOf(&book);
    book2.isCopyOf(&book);
}