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
    int _n;
    const int _MAX=100;
public:
    DSSinhvien();
    void DocFile(const char *file_name_in);
    void GhiFile(const char *file_name_out);
};


#endif //TH_BAI3_DSSINHVIEN_H
