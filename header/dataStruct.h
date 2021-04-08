#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // rand, srand
#include <ctime>
#include <conio.h>
#include <fstream>

using namespace std;

// ========== DANH SACH VAT TU ==========
struct vat_tu
{
    string ma_vt;
    string ten_vt;
    string don_vi_tinh;
    float so_luong_ton;
    bool kt; // kiem tra vat tu da duoc lap hoa don hay chua: true - da duoc lap hoa don (khong the xoa); false - chua duoc lap hoa don (co the xoa)
};
typedef struct vat_tu VAT_TU;

struct ds_vat_tu
{
    VAT_TU *ds[100];
    int sl = 0;
};
typedef struct ds_vat_tu DS_VAT_TU;

// ========== DANH SACH CHI TIET HOA DON ==========
struct ct_hoa_don
{
    string ma_vt;
    float so_luong;
    int don_gia;
    float VAT;       // % thue
    bool trang_thai; // 1: khach mua - 0: khach tra
};
typedef struct ct_hoa_don CT_HOA_DON;

struct ds_chi_tiet_hd
{
    CT_HOA_DON ds[20];
    int sl = 0;
};
typedef struct ds_chi_tiet_hd DS_CHI_TIET_HD;

// ========== DANH SACH HOA DON ==========
struct hoa_don
{
    string so_hd;
    string ngay_lap_hd;
    char loai; // X: xuat - N: nhap
    //dschitiet hd
    DS_CHI_TIET_HD danh_sach_chi_tiet_hd;
    //pointer
    hoa_don *pnext;
};
typedef struct hoa_don HOA_DON;

struct ds_hoa_don
{
    HOA_DON *phead = NULL;
    int sl = 0;
};
typedef struct ds_hoa_don DS_HOA_DON;

// ========== DANH SACH NHAN VIEN ==========
struct nhan_vien
{
    int ma_nv;
    string ho;
    string ten;
    string gioitinh;
    // *dshd
    DS_HOA_DON danh_sach_hd;
    //pointer
    nhan_vien *pleft;
    nhan_vien *pright;
};
typedef struct nhan_vien *tree;

struct ds_nhan_vien
{
    tree ds = NULL;
    int sl = 0;
};
typedef struct ds_nhan_vien DS_NHAN_VIEN;
