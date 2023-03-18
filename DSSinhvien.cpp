//
// Created by Vo Ba Hoang Nhat on 16/03/2023.
//

#include "DSSinhvien.h"

DSSinhvien::DSSinhvien()
{
    _a=new Sinhvien[_capacity];
    _size=0;
}
void DSSinhvien::DocFile(const char *file_name_in) {
    this->~DSSinhvien(); // Delete old data before input new data
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

