//
// Created by Vo Ba Hoang Nhat on 16/03/2023.
//
#include <iostream>
#include "Sinhvien.h"
#include "string.h"
using namespace std;
Sinhvien::Sinhvien()
{
    // doi sang khoi tao bang null vi:
    // khi khoi tao DSSinhvien co bien _a = new Sinhvien[_capacity]
    // se tu dong khoi tao tat ca cac sinh vien trong _a, va 1 so sinh
    // vien ko su dung nhung van cap phat bo nho --> lang phi
   _hoten = nullptr;
   _maso = nullptr;
   _ngaysinh = nullptr;
   _diem[0]=_diem[1]=_diem[2]=0;
}
// tach viec khoi tao ra khoi cac ham de tranh truong hop mang da khoi tao
// roi ma ta lai su dung cac ham sao chep hay operator = se cap phat lai
// bo nho moi --> leaf memory
void Sinhvien::KhoiTao(int nten, int nma, int nngay){
    _hoten=new char[nten];
    _maso=new char[nma];
    _ngaysinh=new char[nngay];
}
Sinhvien::Sinhvien(char *hoten,char*maso,char*ngaysinh,float diem[])
{
    if(_hoten == nullptr) KhoiTao(100, 20, 20);

    memcpy(_hoten,hoten, strlen(hoten)+1);
    memcpy(_maso,maso, strlen(maso)+1);
    memcpy(_ngaysinh,ngaysinh, strlen(ngaysinh)+1);
    for(int i=0;i<3;i++){ _diem[i]=diem[i];}
}
Sinhvien::Sinhvien(const Sinhvien &other)
{
    if(_hoten == nullptr) KhoiTao(100, 20, 20);

    memcpy(_hoten,other._hoten, strlen(other._hoten)+1);
    memcpy(_maso,other._maso, strlen(other._maso)+1);
    memcpy(_ngaysinh,other._ngaysinh, strlen(other._ngaysinh)+1);
    for(int i=0;i<3;i++){ _diem[i]=other._diem[i];}
}
Sinhvien::~Sinhvien()
{
    if(_hoten != nullptr){
        delete[] _hoten;
        delete[] _maso;
        delete[] _ngaysinh;
        _hoten = _maso = _ngaysinh = nullptr;
    }
}
void Sinhvien::Xuat() {
    cout<<"\tHo ten: "<<_hoten<< endl;
    cout <<"\tMa so:"<<_maso<<endl;
    cout <<"\tNgay sinh: "<<_ngaysinh<<endl;
    cout <<"\tDiem: "<<_diem[0]<<" "<<_diem[1]<<" "<<_diem[2] << endl;
}

Sinhvien Sinhvien::Saochep(const Sinhvien& other)
{
;
    if(_hoten == nullptr) KhoiTao(100, 20, 20);

    memcpy(_hoten,other._hoten, strlen(other._hoten)+1);
    memcpy(_maso,other._maso, strlen(other._maso)+1);
    memcpy(_ngaysinh,other._ngaysinh, strlen(other._ngaysinh)+1);

    for(int i=0;i<3;i++){ _diem[i]=other._diem[i];}
    return *this;
}

 Sinhvien& Sinhvien::operator=(const Sinhvien &other)
 {
     if(_hoten == nullptr) KhoiTao(100, 20, 20);

     memcpy(_hoten,other._hoten, strlen(other._hoten)+1);
     memcpy(_maso,other._maso, strlen(other._maso)+1);
     memcpy(_ngaysinh,other._ngaysinh, strlen(other._ngaysinh)+1);
     for(int i=0;i<3;i++){ _diem[i]=other._diem[i];}
     return *this;
}
void Sinhvien::Nhap_Sinh_Vien(ifstream &fin) {

    if(_hoten == nullptr) KhoiTao(100, 20, 20);

    char temp[200];
    fin.getline(temp,200);
    char *token = strtok(temp, ",");
    memcpy(_hoten,token,strlen(token)+1);
    token=strtok(NULL,",");
    memcpy(_maso,token,strlen(token)+1);
    token=strtok(NULL,",");
    memcpy(_ngaysinh,token,strlen(token)+1);
    int count=0;
    for(int i=0;i<3;i++)
    {
       token=strtok(NULL," ");
       _diem[i]=stof(token);
    }
}
void Sinhvien::XuatFile(ofstream &fout) {
    fout<<_hoten<<","<<_maso<<","<<_ngaysinh<<","<<_diem[0]<<" "<<_diem[1]<<" "<<_diem[2];
}

float Sinhvien::Diem_Trung_Binh(){
    return (_diem[0] + _diem[1] + _diem[2])/3;
}

string Sinhvien::Xep_Loai(){
    float diemTB = Diem_Trung_Binh();
    string xeploai;

    if(diemTB < 5) xeploai = "Yeu";
    else if(diemTB < 6.5) xeploai = "Trung binh";
    else if(diemTB < 8) xeploai = "Kha";
    else xeploai = "Gioi";
    return xeploai;
}

bool Sinhvien::laSinhNhat(){
     // get the current time
    time_t now = time(0);
    
    // convert it to the local time
    tm* ltm = localtime(&now);
    
    // extract the day, month, and year from the local time
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;

    char temp[5];
    strncpy(temp, _ngaysinh, 2);
    int birday = stoi(temp);
    strncpy(temp, _ngaysinh + 3, 2);
    int birmonth = stoi(temp);

    return day == birday && month == birmonth;
}

istream& operator >> (istream& in, Sinhvien& src){
    if(src._hoten == nullptr) src.KhoiTao(100, 20, 20);
    in.ignore();
    cout << "Nhap ho ten: ";
    in.getline(src._hoten, 100);
    cout << "Nhap ma so: ";
    in.getline(src._maso, 20);
    cout << "Nhap ngay sinh: ";
    in.getline(src._ngaysinh, 20);
    cout << "Nhap diem 3 mon: ";
    in >> src._diem[0] >> src._diem[1] >> src._diem[2];
    return in;
};

