//
// Created by Vo Ba Hoang Nhat on 16/03/2023.
//

#ifndef TH_BAI3_DSSINHVIEN_H
#define TH_BAI3_DSSINHVIEN_H
#include <iostream>
#include "Sinhvien.h"
#include <fstream>
using namespace std;
//class Sinhvien;
class DSSinhvien {
private:
    Sinhvien *_a;
    int _size;
    int _capacity;
    int** _xeploai;
    ./*mang xep loai voi:
        index 0: loai yeu (0 <= tb < 5)
        index 1: loai trung binh (5 <= tb < 6.5)
        index 2: loai kha (6.5 <= tb < 8)
        index 3: loai gioi (8 <= tb)
        moi mang tai index chua chi so cua cac hoc sinh mang xep loai do*/
public:
    DSSinhvien();
    ~DSSinhvien();
    void DocFile(const char *file_name_in);
    void GhiFile(const char *file_name_out);
    void CapNhapFile(const char*file_name);
    void ThemSinhVien(const Sinhvien);
    float DiemTBLop();
    void XepLoaiSinhVien();
    void XuatDSCoXepLoai(string xeploai);
    void DSCoCungNgaySinh();
    DSSinhvien DSDiemKem();
};


#endif //TH_BAI3_DSSINHVIEN_H
