//
// Created by Vo Ba Hoang Nhat on 16/03/2023.
//

#ifndef TH_BAI3_SINHVIEN_H
#define TH_BAI3_SINHVIEN_H
#include <fstream>
#include <iostream>
using namespace std;
class Sinhvien {
private:
    char* _hoten;
    char*_maso;
    char*_ngaysinh;
    float _diem[3];
public:
    Sinhvien();
    Sinhvien(char *hoten,char*maso,char*ngaysinh,float diem[]);
    Sinhvien(const Sinhvien &other);
    ~Sinhvien();
    Sinhvien Saochep(const Sinhvien& other);
    Sinhvien operator=(const Sinhvien &other);
    void Nhap_Sinh_Vien(ifstream &fin);
    void Xuat();
    void XuatFile(ofstream &fout);
    float Diem_Trung_Binh();
};


#endif //TH_BAI3_SINHVIEN_H
