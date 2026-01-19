#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"CongTy.hpp"
using namespace std;


class NhanVien:public NhanSu
{
    protected:
    int luongCoBan;
    public:
    NhanVien(string name,int luong);
    NhanVien();
    void Add(NhanSu*ns);
    virtual void Xuat(int depth);
    virtual int TinhLuong();
    virtual int SoLuong();
    NhanSu* TimBangTen(string name);
    virtual void Write(ofstream&of);
    virtual void Load(ifstream&is);
};

class NhanVienVanPhong:public NhanVien{
    private:
    int phuCap;
    public:
    NhanVienVanPhong();
    NhanVienVanPhong(string name,int luong,int pc);
    void Xuat(int depth);
    int TinhLuong();
    int SoLuong();
    void Write(ofstream&of);
    void Load(ifstream&is);
};

class NhanVienSanXuat:public NhanVien
{
    private:
    int soSanPham;
    int donGia;
    public:
    NhanVienSanXuat(string name,int Luong,int ssp,int dongia);
    NhanVienSanXuat();
     void Xuat(int depth);
     int TinhLuong();
     int SoLuong();
     void Write(ofstream&of);
     void Load(ifstream&is);
};

class NhanVienQuanLy:public NhanVien
{
    private:
    int thuong;
    public:
    NhanVienQuanLy(string name,int luong,int thuong);
    NhanVienQuanLy();
    void Xuat(int depth);
    int TinhLuong();
    int SoLuong();
    void Write(ofstream&of);
    void Load(ifstream&is);
};