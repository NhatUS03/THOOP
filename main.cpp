#include <iostream>
#include "Sinhvien.h"
#include "DSSinhvien.h"
int main() {
//    float diem[3]={1,2,3};
//    char hoten[100]="Vo Ba Hoang Nhat";
//    char maso[20]="21120516";
//    char ngaysinh[20]="04/03/2003";
//    Sinhvien a(hoten,maso,ngaysinh,diem);
//   // a.Xuat();
//    Sinhvien b=a;
//
    DSSinhvien ds;
    const char filein[100]="input.txt";
    ds.DocFile(filein);
    const char fileout[100]="output.txt";
    ds.GhiFile(fileout);
    return 0;
}
