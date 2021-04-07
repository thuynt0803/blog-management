/*Tong hop cac ham xu ly phu tro*/

#pragma once
#include "./dataStruct.h"

void chuan_hoa_ki_tu(string &a)
{
    // |   Tu     laNH   |
    // ==> |Tu Lanh|
    // xoa khoang trang dau
    while (a[0] == ' ')
    {
        a.erase(a.begin() + 0);
    }
    // xoa khoang trang cuoi
    while (a[a.length() - 1] == ' ')
    {
        a.erase(a.begin() + a.length() - 1);
    }
    // xoa khoang trang giua
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ' && a[i + 1] == ' ')
        {
            a.erase(a.begin() + i);
            i--;
        }
    }
    // chuan hoa ki tu - chi viet hoa chu cai dau
    if (a[0] >= 97 && a[0] <= 122)
    {
        a[0] -= 32;
    }
    for (int i = 1; i < a.length(); i++)
    {
        if (a[i] == ' ') // chu hoa
        {
            i++;
            if (a[i] >= 97 && a[i] <= 122)
            {
                a[i] -= 32;
            }
        }
        else // viet chu thuong
        {
            if (a[i] >= 65 && a[i] <= 90)
            {
                a[i] += 32;
            }
        }
    }
}