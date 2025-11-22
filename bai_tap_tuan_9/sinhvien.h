#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <string>
#include <iostream>
class SV
{
public:
    std::string HoTen;
    std::string DOB;
    std::string MSSV;
    double GPA;
    SV();
    SV(std::string HoTen, std::string MSSV, std::string DOB, double GPA);
    void cpyData(SV *a);
    void print();
};
SV::SV(){
    HoTen = "";
    DOB = "";
    MSSV = "";
    GPA = 0.0;
}
SV::SV(std::string HoTen, std::string MSSV, std::string DOB, double GPA){
    this->HoTen = HoTen;
    this->MSSV = MSSV;
    this->DOB = DOB;
    this->GPA = GPA;
}
void SV::print(){
    std::cout<<"\nHọ và tên SV:\t"<<HoTen<<"\n";
    std::cout<<"\nNgày tháng năm sinh:\t"<<DOB<<"\n";
    std::cout<<"\nMSSV:\t"<<MSSV<<"\n";
    std::cout<<"\nGPA:\t"<<GPA<<"\n";
}
void SV::cpyData(SV*a){
    this->DOB = a->DOB;
    this->GPA = a->GPA;
    this->HoTen = a->HoTen;
    this->MSSV = a->MSSV;
}
#endif