
#pragma once
#include "./dataStruct.h"

// ======================== doc file danh sach vat tu ========================
void readFileDSVT(DS_VAT_TU &ds_vt)
{
    ifstream filein;
    filein.open("../ds_vt.txt", ios_base::in); // doc file
    while (filein.eof() != true)               // doc den cuoi file
    {
        ds_vt.ds[ds_vt.sl] = new VAT_TU;
        getline(filein, ds_vt.ds[ds_vt.sl]->ma_vt, ',');
        getline(filein, ds_vt.ds[ds_vt.sl]->ten_vt, ',');
        getline(filein, ds_vt.ds[ds_vt.sl]->don_vi_tinh, ',');
        filein >> ds_vt.ds[ds_vt.sl]->so_luong_ton;
        filein.ignore();
        filein >> ds_vt.ds[ds_vt.sl]->kt;
        filein.ignore();
        ds_vt.sl++;
    }

    filein.close();
}