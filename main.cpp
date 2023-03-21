
#include "DSSinhvien.h"

void Menu(DSSinhvien &ds)
{
    int choice = -1;
    while (choice != 0)
    {
        cout << "--------- Quan ly Sinh Vien ---------" << endl << endl;
        cout << "Cac lua chon: " << endl;

        cout << "[1] Doc danh sach sinh vien tu 'input.txt' " << endl;
        cout << "[2] Ghi danh sach sinh vien ra 'output.txt'" << endl;
        cout << "[3] Ghi cac sinh vien co diem trung binh nho hon diem trung binh cua lop, vao tap tin 'DSDiemkem.txt'" << endl;
        cout << "[4] Them mot sinh vien moi vao tap tin 'output.txt'" << endl;
        cout << "[5] Xuat danh sach sinh vien co thong tin xep loai" << endl;
        cout << "[6] In ra tat ca cac sinh vien co sinh nhat la hom nay" << endl;
        cout << "[7] Thoat chuong trinh." << endl << endl;

        cout << "Hay nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ds.DocFile("input.txt");
            break;
        }
        case 2:
        {
            ds.GhiFile("output.txt");
            break;
        }
        case 3:
        {
            ds.DSDiemKem("DSDiemkem.txt");
            break;
        }
        case 4:
        {
            Sinhvien sv;
            cin >> sv;
            ds.ThemSinhVien(sv);
            ds.GhiFile("output.txt");
            break;
        }
        case 5:
        {
            ds.XuatDSCoXepLoai();
            break;
        }
        case 6:
        {
            ds.xuatDSSVSinhNhatHomNay();
            break;
        }
        
        case 7:
            return;
            break;
        default:
            cout << "Khong co lua chon phu hop. Hay nhap lai." << endl
                 << endl;
            break;
        }
        cout << "-----------------------------------------------------" << endl
             << endl;

    }
}

int main()
{
    DSSinhvien ds;
    Menu(ds);
    return 0;
}