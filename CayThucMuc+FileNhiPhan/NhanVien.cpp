#include<iostream>
#include"NhanVien.hpp"
#include"CongTy.hpp"
#include<string>
#include<vector>
using namespace std;


NhanVien::NhanVien()
{

}
NhanVien::NhanVien(string name,int luong):NhanSu(name)
{
    this->luongCoBan=luong;
}
void NhanVien::Add(NhanSu*ns)
{
    return;
}
 void NhanVien::Xuat(int depth)
 {
    NhanSu::Xuat(depth);
 }
 int NhanVien::TinhLuong()
 {
    return 0;
 }
 int NhanVien::SoLuong()
 {
    return 0;
 }
NhanSu* NhanVien::TimBangTen(string name)
{
    if(this->name==name)
    {
        return this;
    }
    return nullptr;
}
void NhanVien::Write(ofstream&of)
{
return;
}
void NhanVien::Load(ifstream&is)
{
return;
}




NhanVienVanPhong::NhanVienVanPhong():NhanVien()
{

}
NhanVienVanPhong::NhanVienVanPhong(string name,int luong,int pc):NhanVien(name,luong)
{
    this->phuCap=pc;
}
void NhanVienVanPhong::Xuat(int depth)
{
    NhanVien::Xuat(depth);
    cout<<"NVVP: "<<this->name<<" "<<this->luongCoBan<<" "<<this->phuCap<<endl;
}
int NhanVienVanPhong::TinhLuong()
{
    return luongCoBan+phuCap;
}
int NhanVienVanPhong::SoLuong()
{
    return 1;
}
void NhanVienVanPhong::Write(ofstream&of)
{
    int type=1;
    of.write((char*)&type,sizeof(type));
    int len=this->name.size();
    of.write((char*)&len,sizeof(len));
    of.write(name.c_str(),len);
    of.write((char*)&luongCoBan,sizeof(luongCoBan));
    of.write((char*)&phuCap,sizeof(phuCap));
}
void NhanVienVanPhong::Load(ifstream&is)
{
    int len;
    is.read((char*)&len,sizeof(len));
    this->name.resize(len);
    is.read(&name[0],len);
    is.read((char*)&luongCoBan,sizeof(luongCoBan));
    is.read((char*)&phuCap,sizeof(phuCap));
}


NhanVienSanXuat::NhanVienSanXuat(string name,int Luong,int ssp,int dongia):NhanVien(name,Luong)
{
    this->soSanPham=ssp;
    this->donGia=dongia;
}
NhanVienSanXuat::NhanVienSanXuat():NhanVien()
{

}
void NhanVienSanXuat::Xuat(int depth)
{
    NhanVien::Xuat(depth);
    cout<<"NVXS: "<<this->name<<" "<<this->luongCoBan<<" "<<this->soSanPham<<" "<<this->donGia<<endl;
    
}
int NhanVienSanXuat::TinhLuong()
{
    return luongCoBan+soSanPham*donGia;
}
int NhanVienSanXuat::SoLuong()
{
    return 1;
}
void NhanVienSanXuat::Write(ofstream&of)
{
     int type=2;
    of.write((char*)&type,sizeof(type));
    int len=this->name.size();
    of.write((char*)&len,sizeof(len));
    of.write(name.c_str(),len);
    of.write((char*)&luongCoBan,sizeof(luongCoBan));
    of.write((char*)&soSanPham,sizeof(soSanPham));
    of.write((char*)&donGia,sizeof(donGia));
}
void NhanVienSanXuat:: Load(ifstream&is)
{
    int len;
    is.read((char*)&len,sizeof(len));
    this->name.resize(len);
    is.read(&name[0],len);
    is.read((char*)&luongCoBan,sizeof(luongCoBan));
    is.read((char*)&soSanPham,sizeof(soSanPham));
    is.read((char*)&donGia,sizeof(donGia));
}


NhanVienQuanLy::NhanVienQuanLy(string name,int luong,int thuong):NhanVien(name,luong)
{
    this->thuong=thuong;
}
NhanVienQuanLy::NhanVienQuanLy():NhanVien()
{
    thuong=0;
}
void NhanVienQuanLy::Xuat(int depth)
{
    NhanVien::Xuat(depth);
    cout<<"NVQL: "<<this->name<<" "<<this->luongCoBan<<" "<<this->thuong<<endl;

}
int NhanVienQuanLy::TinhLuong()
{
    return this->thuong+this->luongCoBan;
}
int NhanVienQuanLy::SoLuong()
{
    return 1;
}
void NhanVienQuanLy:: Write(ofstream&of)
{
     int type=3;
    of.write((char*)&type,sizeof(type));
    int len=this->name.size();
    of.write((char*)&len,sizeof(len));
    of.write(name.c_str(),len);
    of.write((char*)&luongCoBan,sizeof(luongCoBan));
    of.write((char*)&thuong,sizeof(thuong));
}
void NhanVienQuanLy::Load(ifstream&is)
{
     int len;
    is.read((char*)&len,sizeof(len));
    this->name.resize(len);
    is.read(&name[0],len);
    is.read((char*)&luongCoBan,sizeof(luongCoBan));
    is.read((char*)&thuong,sizeof(thuong));
}