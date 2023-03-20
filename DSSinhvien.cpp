//
// Created by Vo Ba Hoang Nhat on 16/03/2023.
//

#include "DSSinhvien.h"

DSSinhvien::DSSinhvien()
{
    _capacity = 1;
    _a = new Sinhvien[_capacity];
    _size=0;
}
DSSinhvien::~DSSinhvien(){
    delete[] _a;
    _a = nullptr;
    _size = 0;
}
void DSSinhvien::DocFile(const char *file_name_in) {
    ifstream fin;
    fin.open(file_name_in,ios::in);
    if(fin.fail())
    {
        cout<<"Can't open file!"<<endl;
        return ;
    }
    int count=0;
    while(fin.peek()!=EOF){  
        _a[count].Nhap_Sinh_Vien(fin);
        count++;
        _size++;
        if(_size >= _capacity) tangCapacity();
    }
    fin.close();
}
void DSSinhvien::GhiFile(const char *file_name_out) {
    ofstream fout;
    fout.open(file_name_out,ios::out);
    if(fout.fail())
    {
        cout<<"Can't open file!"<<endl;
        return ;
    }
    int count=0;
    for(int i=0;i<_size;i++)
    {
        _a[i].XuatFile(fout);
        fout<<endl;
    }
    fout.close();
}

float DSSinhvien::DiemTBLop(){
    float res = 0;
    for(int i = 0; i < _size; i++)
        res += _a[i].Diem_Trung_Binh();
    return res/_size;
}

void DSSinhvien::ThemSinhVien(const Sinhvien& sv){
    _a[_size] = sv;
    _size += 1;
    if(_size >= _capacity) tangCapacity();
};

void DSSinhvien::DSDiemKem(const char* fileName){
    DSSinhvien res;
    float tbLop = DiemTBLop();
    for(int i = 0; i < _size; i++){
        if(_a[i].Diem_Trung_Binh() < tbLop)
            res.ThemSinhVien(_a[i]);
    }
    res.GhiFile(fileName);
}

void DSSinhvien::tangCapacity(){
    Sinhvien* temp = new Sinhvien[_capacity*2];
    for(int i = 0; i < _size; i++){
        // copy 
        temp[i] = _a[i];
    }
    delete[] _a;
    _a = temp;
    _capacity *= 2;
}

void DSSinhvien::XuatDSCoXepLoai(){
    for(int i = 0; i < _size; i++){
        _a[i].Xuat();
        cout << "\t-->Xep loai: " << _a[i].Xep_Loai() << endl;
    }
};

void DSSinhvien::xuatDSSVSinhNhatHomNay(){
    for(int i = 0; i < _size; i++){
        if(_a[i].laSinhNhat())
            _a[i].Xuat();
    }
};