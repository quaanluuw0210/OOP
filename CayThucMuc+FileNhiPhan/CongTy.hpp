#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


class NhanSu
{
    protected:
    string name;
    public:
    NhanSu();
    NhanSu(string name);
    virtual void Xuat(int depth);
     void Print();
     string GetName();
    virtual int TinhLuong();
    virtual int SoLuong();
    virtual NhanSu* TimBangTen(string name);
    virtual void Write(ofstream&of);
    virtual void Load(ifstream& is);
    virtual void Add(NhanSu*ns)=0;
};

class CongTy
{
    private:
    NhanSu*root;
    string name;
    CongTy();
    public:
    void SetName(string newName);
    static CongTy& getInstance();
    void ThemNhanSu(NhanSu* moi);
    void XuatDanhSach();
    NhanSu* TimBangTen(string name);
    NhanSu* TaoCongTyVoiFileText(istream&os);
    void GhiFileBin(ofstream&os);
    NhanSu*DocFileBin(ifstream&is);
};

