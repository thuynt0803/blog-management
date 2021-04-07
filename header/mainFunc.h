/*Tong hop luong xu ly chuc nang chinh*/

#pragma once
#include "./dataStruct.h"
#include "./auxiliaryFunc.h"

// ============= khai bao nguyen mau ham - them =============
void insertVatTu(DS_VAT_TU &ds_vt);
string createMaTV(DS_VAT_TU &ds_vt);
int checkDuplicate(string a, DS_VAT_TU &ds_vt);

// ============= khai bao nguyen mau ham - xuat =============
void outputDSVT(DS_VAT_TU ds_vt);

// ======================= menu =======================
void menu()
{
    DS_VAT_TU ds_vt;
    bool kt = true;
    while (kt == true)
    {
        system("cls");
        cout << "1. Them vat tu." << endl;
        cout << "2. Xuat danh sach vat tu." << endl;
        cout << "0. Thoat." << endl;

        int luachon;
        cout << "Nhap lua chon: ";
        cin >> luachon;

        switch (luachon)
        {
        case 1:
        {
            if (ds_vt.sl == 100)
            {
                cout << "\nKhong the them vat tu. Danh sach day!" << endl;
                system("pause");
            }
            else
            {
                insertVatTu(ds_vt);
            }

            break;
        }
        case 2:
        {
            cout << "\n\n\t\t\t===================== DANH SACH VAT TU =====================\n\n";
            outputDSVT(ds_vt);
            system("pause");
            break;
        }
        case 0:
        {
            kt = false;
            break;
        }
        }
    }
}

// ======================= them vat tu =======================
void insertVatTu(DS_VAT_TU &ds_vt)
{
    VAT_TU *p = new VAT_TU;
    p->ma_vt = createMaTV(ds_vt);
    cout << "\nNhap ten vat tu: ";
    cin.ignore();
    getline(cin, p->ten_vt);
    cout << "Nhap don vi tinh: ";
    getline(cin, p->don_vi_tinh);
    cout << "Nhap so luong ton: ";
    cin >> p->so_luong_ton;
    // ------ chuan hoa ki tu nhap --------------
    chuan_hoa_ki_tu(p->ma_vt);
    chuan_hoa_ki_tu(p->ten_vt);
    chuan_hoa_ki_tu(p->don_vi_tinh);
    ds_vt.ds[ds_vt.sl] = p; // them vao cuoi danh sach
    ds_vt.sl++;
}
// Ham sinh ma vat tu tu dong
string createMaTV(DS_VAT_TU &ds_vt)
{
    string a = "VT0000";
    do
    {
        for (int i = 2; i < a.length(); i++)
        {
            // rand() % (b - a + 1) + a ==> tao so rand trong khoang [a;b]
            // a co kieu string --> 1 phan tu trong a la 1 ki tu --> nhan gia tri character --> so 9 = 57, so 0 = 48 (ma ASCII)
            a[i] = rand() % (57 - 48 + 1) + 48;
        }
    } while (checkDuplicate(a, ds_vt) >= 0);
    return a;
}

int checkDuplicate(string a, DS_VAT_TU &ds_vt)
{
    for (int i = 0; i < ds_vt.sl; i++)
    {
        if (ds_vt.ds[i]->ma_vt == a)
        {
            return i; // duplicate ma_vt
        }
    }
    return -1; // ma_vt is not duplicated
}

// ======================= xuat danh sach vat tu =======================
void outputDSVT(DS_VAT_TU ds_vt)
{
    cout << "\tMA VT\t\t||\tTEN VAT TU\t||\t   DON VI\t||\tSO LUONG TON\t" << endl;
    for (int i = 0; i < ds_vt.sl; i++)
    {
        cout << "\t" << ds_vt.ds[i]->ma_vt << "\t\t\t  " << ds_vt.ds[i]->ten_vt << "\t\t   " << ds_vt.ds[i]->don_vi_tinh << "\t\t\t" << ds_vt.ds[i]->so_luong_ton << endl;
    }
}