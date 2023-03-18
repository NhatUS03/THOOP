//
// Created by Vo Ba Hoang Nhat on 16/03/2023.
//
#include <iostream>
#include "Sinhvien.h"
#include "string.h"
using namespace std;
Sinhvien::Sinhvien()
{
   _hoten=new char[100];
   _maso=new char[20];
   _ngaysinh=new char[20];
   _diem[0]=_diem[1]=_diem[2]=0;
}
Sinhvien::Sinhvien(char *hoten,char*maso,char*ngaysinh,float diem[])
{
    _hoten=new char[100];
    _maso=new char[20];
    _ngaysinh=new char[20];
    memcpy(_hoten,hoten, strlen(hoten)+1);
    memcpy(_maso,maso, strlen(maso)+1);
    memcpy(_ngaysinh,ngaysinh, strlen(ngaysinh)+1);
    for(int i=0;i<3;i++){ _diem[i]=diem[i];}
}
Sinhvien::Sinhvien(const Sinhvien &other)
{
    _hoten=new char[100];
    _maso=new char[20];
    _ngaysinh=new char[20];
    memcpy(_hoten,other._hoten, strlen(other._hoten)+1);
    memcpy(_maso,other._maso, strlen(other._maso)+1);
    memcpy(_ngaysinh,other._ngaysinh, strlen(other._ngaysinh)+1);
    for(int i=0;i<3;i++){ _diem[i]=other._diem[i];}
}
Sinhvien::~Sinhvien()
{
    delete[]_hoten;
    delete[]_maso;
    delete[]_ngaysinh;
}
void Sinhvien::Xuat() {
    cout<<_hoten<<","<<_maso<<","<<_ngaysinh<<","<<_diem[0]<<" "<<_diem[1]<<" "<<_diem[2];
}
Sinhvien Sinhvien::Saochep(const Sinhvien& other)
{
    _hoten=new char[100];
    _maso=new char[20];
    _ngaysinh=new char[20];
    memcpy(_hoten,other._hoten, strlen(other._hoten)+1);
    memcpy(_maso,other._maso, strlen(other._maso)+1);
    memcpy(_ngaysinh,other._ngaysinh, strlen(other._ngaysinh)+1);
    for(int i=0;i<3;i++){ _diem[i]=other._diem[i];}
    return *this;
}
Sinhvien Sinhvien::operator=(const Sinhvien &other)
{
    _hoten=new char[100];
    _maso=new char[20];
    _ngaysinh=new char[20];
    memcpy(_hoten,other._hoten, strlen(other._hoten)+1);
    memcpy(_maso,other._maso, strlen(other._maso)+1);
    memcpy(_ngaysinh,other._ngaysinh, strlen(other._ngaysinh)+1);
    for(int i=0;i<3;i++){ _diem[i]=other._diem[i];}
    return *this;
}
void Sinhvien::Nhap_Sinh_Vien(ifstream &fin) {
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