//
// Created by Vo Ba Hoang Nhat on 16/03/2023.
//

#ifndef TH_BAI3_DSSINHVIEN_H
#define TH_BAI3_DSSINHVIEN_H

#include "Sinhvien.h"

using namespace std;
//class Sinhvien;
class DSSinhvien {
private:
    Sinhvien *_a;
    int _size;
    int _capacity;
    void tangCapacity();
public:
    DSSinhvien();
    ~DSSinhvien();
    void DocFile(const char *file_name_in);
    void GhiFile(const char *file_name_out);
    void ThemSinhVien(const Sinhvien&);
    float DiemTBLop();
    void XuatDSCoXepLoai();
    void DSDiemKem(const char*);
    void xuatDSSVSinhNhatHomNay();
};


#endif //TH_BAI3_DSSINHVIEN_H
