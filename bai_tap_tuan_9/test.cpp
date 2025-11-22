#include <iostream>
#include "sinhvien.h"
#include "list.h"
int main(){
    SV a("Nguyen Van A", "2313314", "12/2/2000", 3.7);
    SV b("Nguyen Van B", "2324313", "12/3/2000", 3.6);
    SV c("Nguyen Van C", "2323413", "12/4/2000", 3.1);
    SV d("Nguyen Van D", "2344331", "14/5/2000", 3.8);
    SV e("Nguyen Van E", "2346631", "15/5/2000", 2.7);
    SV f("Nguyen Van F", "2366331", "16/5/2000", 1.8);
    SV g("Nguyen Van G", "2388331", "17/5/2000", 1.9);
    SV h("Nguyen Van H", "2224331", "18/5/2000", 3.0);
    // Khai báo danh sách
    DSSV ds;
    ds.insertToHead(a);
    ds.insertToHead(b);
    ds.insertToHead(c);
    ds.insertToHead(d);
    ds.insertToLast(e);
    ds.insertToHead(f);
    ds.insertToLast(g);
    ds.insertToHead(h);
    std::cout<<"\nIn danh sách\n";
    ds.print();
    std::cout<<"\nSố sinh viên trong danh sách là:"<<ds.count()<<"\n";
    std::cout<<"\nSố sinh viên trong danh sách có GPA > 3.2 là:"<<ds.countGPAOver3_2()<<"\n";
    ds.sortWithGPA();
    std::cout<<"\n_______________After sort_______________\n";
    ds.print();
    std::cout<<"\n_______________Insert 2.4 GPA_______________\n";
    SV k("Nguyen Van K", "3324331", "18/5/2001", 2.4);
    ds.insertWithOrder(k);
    ds.print();
}