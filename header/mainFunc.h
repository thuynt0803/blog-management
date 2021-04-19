/*Tong hop luong xu ly chuc nang chinh*/

#pragma once
#include "./dataStruct.h"
#include "./auxiliaryFunc.h"
#include "./doc_ghi_file.h"

// ============= khai bao nguyen mau ham - them =============
void insertVatTu(DS_VAT_TU &ds_vt);
string createMaTV(DS_VAT_TU &ds_vt);
int checkDuplicateMaVT(string a, DS_VAT_TU &ds_vt);
// ============= khai bao nguyen mau ham - xuat =============
void outputDSVT(DS_VAT_TU ds_vt);
// ============= khai bao nguyen mau ham - xoa ==============
void deleteVT(DS_VAT_TU &ds_vt);
int checkMaVT(string a, DS_VAT_TU ds_vt);
// ============= khai bao nguyen mau ham - sua ==============
void editVT(DS_VAT_TU ds_vt);
// ============ khoi tao node - nhan vien ===============
nhan_vien *init_node_nhan_vien();
// ========== nhap nhan vien ===========
void inputNV(DS_NHAN_VIEN &ds_nv);
// ========== them 1 nhan vien =============
void insert1NV(tree &t, nhan_vien *p);
// ============= tao ma nhan vien ==========
int createMaNV(tree t);
bool checkDuplicateMaNV(tree t, int ma);

// ======================= MENU =======================
void menu()
{
    //========== khai bao bien ===========
    DS_VAT_TU ds_vt;
    DS_NHAN_VIEN ds_nv;
    bool kt = true;
    //========== load file ===============
    readFileDSVT(ds_vt);
    //========== xu ly menu ==============
    while (kt == true)
    {
        system("cls");
        cout << "1. Them vat tu." << endl;
        cout << "2. Xuat danh sach vat tu." << endl;
        cout << "3. Xoa vat tu." << endl;
        cout << "4. Chinh sua vat tu." << endl;
        cout << "5. Nhap nhan vien." << endl;
        cout << "6. ." << endl;
        cout << "0. Thoat." << endl;
        cout << "=====================================" << endl;

        int luachon;
        cout << "\n- Nhap lua chon: ";
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
        case 3:
        {
            if (ds_vt.sl == 0)
            {
                cout << "\nXoa khong thanh cong, data rong!" << endl;
                system("pause");
            }
            else
            {
                deleteVT(ds_vt);
            }
            break;
        }
        case 4:
        {
            if (ds_vt.sl == 0)
            {
                cout << "\nData rong!" << endl;
                system("pause");
            }
            else
            {
                editVT(ds_vt);
            }
            break;
        }
        case 5:
        {
            inputNV(ds_nv);
            break;
        }
        case 0:
        {
            kt = false;
            cout << "\tDONE!";
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
    cout << "\n\tNhap ten vat tu: ";
    cin.ignore();
    getline(cin, p->ten_vt);
    cout << "\tNhap don vi tinh: ";
    getline(cin, p->don_vi_tinh);
    cout << "\tNhap so luong ton: ";
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
    } while (checkDuplicateMaVT(a, ds_vt) >= 0);
    return a;
}

int checkDuplicateMaVT(string a, DS_VAT_TU &ds_vt)
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

// ======================= xoa vat tu =======================
void deleteVT(DS_VAT_TU &ds_vt)
{
    cout << "\n\t1. Neu vat tu da duoc lap hoa don thi khong the xoa." << endl;
    string a;
    cout << "\t2. Nhap ma vat tu: ";
    cin >> a;
    // viet ham chuan hoa ki tu sau khi nhap
    // chuan_hoa_ki_tu(a);
    //=========== xu ly xoa vat tu ===========
    int vt = checkMaVT(a, ds_vt);
    // ------ xoa -------
    // b1: di chuyen
    if (vt < 0)
    {
        cout << "\n\tNOTE: Vat tu khong ton tai hoac da duoc lap hoa don!" << endl;
        system("pause");
    }
    else
    {
        for (int i = vt; i < ds_vt.sl - 1; i++)
        {
            ds_vt.ds[i]->ma_vt = ds_vt.ds[i + 1]->ma_vt;
            ds_vt.ds[i]->ten_vt = ds_vt.ds[i + 1]->ten_vt;
            ds_vt.ds[i]->don_vi_tinh = ds_vt.ds[i + 1]->don_vi_tinh;
            ds_vt.ds[i]->so_luong_ton = ds_vt.ds[i + 1]->so_luong_ton;
            ds_vt.ds[i]->kt = ds_vt.ds[i + 1]->kt;
        }
        // b2: giam so luong
        VAT_TU *temp = ds_vt.ds[ds_vt.sl - 1];
        ds_vt.sl--;
        cout << "\tNOTE: Da xoa thanh cong!" << endl;
        system("pause");
    }
}

int checkMaVT(string a, DS_VAT_TU ds_vt)
{
    for (int i = 0; i < ds_vt.sl; i++)
    {
        // kiem tra mavt duoc nhap co ton tai trong danh sach khong?
        if (ds_vt.ds[i]->ma_vt == a)
        {
            // kiem tra xem mavt chua duoc lap hoa don
            if (ds_vt.ds[i]->kt == false)
            {
                return i;
            }
        }
    }
    return -1; // mavt khong ton tai hoac da duoc lap hoa don
}

// ============= hieu chinh (sua) vat tu =============
void editVT(DS_VAT_TU ds_vt)
{
    string a;
    cout << "\n\tNhap ma vat tu can sua: ";
    cin >> a;

    //========== kiem tra mavt ==========
    int vt = checkDuplicateMaVT(a, ds_vt);
    if (vt < 0)
    {
        cout << "\n\tNOTE: Ma vat tu khong ton tai!" << endl;
        system("pause");
    }
    else
    {
        //=========== hieu chinh ============
        cout << "\tTen vat tu thay doi: ";
        cin.ignore();
        getline(cin, ds_vt.ds[vt]->ten_vt);
        cout << "\tDon vi tinh thay doi: ";
        getline(cin, ds_vt.ds[vt]->don_vi_tinh);
        chuan_hoa_ki_tu(ds_vt.ds[vt]->ten_vt);
        chuan_hoa_ki_tu(ds_vt.ds[vt]->don_vi_tinh);
        cout << "\tNOTE: Da thay doi thong tin vat tu!" << endl;
        system("pause");
    }
}

// ========== khoi tao node nhan vien ===========
nhan_vien *init_node_nhan_vien()
{
    nhan_vien *p = new nhan_vien;
    p->pleft = NULL;
    p->pright = NULL;
    return p;
}

// ========== nhap nhan vien ===========
void inputNV(DS_NHAN_VIEN &ds_nv)
{
    nhan_vien *p = init_node_nhan_vien();
    cin.ignore();
    cout << "Nhap ho: ";
    getline(cin, p->ho);
    cout << "Nhap ten: ";
    getline(cin, p->ten);
    cout << "Nhap gioi tinh: ";
    getline(cin, p->gioitinh);
    // cin.ignore();
    p->ma_nv = createMaNV(ds_nv.TREE);
    insert1NV(ds_nv.TREE, p);
    ds_nv.sl++;
}

// ========== them 1 nhan vien =============
void insert1NV(tree &t, nhan_vien *p)
{
    if (t == NULL)
    {
        t = p;
    }
    else
    {
        if (p->ma_nv > t->ma_nv)
        {
            insert1NV(t->pright, p);
        }
        else if (p->ma_nv < t->ma_nv)
        {
            insert1NV(t->pleft, p);
        }
    }
}

// ============= tao ma nhan vien ==========
int createMaNV(tree t)
{
    int ma; // ma nam trong khoang tu 100 - 999
    do
    {
        ma = rand() % (999 - 100 + 1) + 100;
    } while (checkDuplicateMaNV(t, ma) == 1);
    return ma;
}

bool checkDuplicateMaNV(tree t, int ma)
{
    //su dung de quy
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        if (t->ma_nv == ma)
        {
            return 1;
        }
        else if (t->ma_nv < ma)
        {
            checkDuplicateMaNV(t->pright, ma);
        }
        else
        {
            checkDuplicateMaNV(t->pleft, ma);
        }
    }
    return 1;
}
