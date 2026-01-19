#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<sstream>
#include"CongTy.hpp"
#include"PhongBan.hpp"
#include"NhanVien.hpp"
using namespace std;

NhanSu::NhanSu()
{
    this->name="";
}
NhanSu::NhanSu(string name)
{
    this->name=name;
}
 void NhanSu::Xuat(int depth)

 {
    for(int i=0;i<depth;i++)
    {
        cout<<"  ";
    }
 }
void NhanSu::Print()
{
    this->Xuat(0);
}
string NhanSu::GetName()
{
    return this->name;
}
 int NhanSu::TinhLuong()
 {
    return 0;
 }
 int NhanSu::SoLuong()
 {
    return 0;
 }
 NhanSu* NhanSu::TimBangTen(string name)
 {
    return nullptr;
 }
 void NhanSu::Write(ofstream&of)
 {  
    return;

 }
 void NhanSu::Load(ifstream&is)
 {
    return;
 }




CongTy::CongTy()
{
    this->name="";
}
void CongTy::SetName(string newName)
{
    this->name=name;
}
CongTy& CongTy::getInstance()
{
    static CongTy newCop;
    return newCop;
}
void CongTy::ThemNhanSu(NhanSu* moi)
{
   this->root=moi;
}
void CongTy::XuatDanhSach()
{
    root->Xuat(0);
}
NhanSu* CongTy::TimBangTen(string name)
{
    NhanSu* temp=NULL;
    temp=root->TimBangTen(name);
    return nullptr;
}   
NhanSu* CongTy::TaoCongTyVoiFileText(istream& is)
{
    string line;
    stack<PhongBan*> st;
    PhongBan* root = nullptr;

    while (getline(is, line))
    {
        if (line.empty()) continue;

        stringstream ss(line);
        string type;
        ss >> type;

        // ---- PHONG BAN ----
        if (type == "PhongBan")
        {
            string ten;
            ss >> ten;

            PhongBan* pb = new PhongBan(ten);

            if (st.empty())
                root = pb;
            else
                st.top()->Add(pb);

            st.push(pb);
        }

        // ---- NV VAN PHONG ----
        else if (type == "NVVP")
        {
            string ten;
            int luong, phuCap;
            ss >> ten >> luong >> phuCap;

            st.top()->Add(new NhanVienVanPhong(ten, luong, phuCap));
        }

        // ---- NV QUAN LY ----
        else if (type == "NVQL")
        {
            string ten;
            int luong, thuong;
            ss >> ten >> luong >> thuong;

            st.top()->Add(new NhanVienQuanLy(ten, luong, thuong));
        }

        // ---- NV SAN XUAT ----
        else if (type == "NVSX")
        {
            string ten;
            int luong, sp, donGia;
            ss >> ten >> luong >> sp >> donGia;

            st.top()->Add(new NhanVienSanXuat(ten, luong, sp, donGia));
        }

        // ---- KET THUC PHONG BAN ----
        else if (type == "..")
        {
            if (st.empty())
                throw runtime_error("Du dau ..");

            st.pop();
        }
    }

    if (!st.empty())
        throw runtime_error("Thieu .. dong phong ban");

    return root;
}

void CongTy::GhiFileBin(ofstream&os)
{
  root->Write(os);
}
NhanSu* CongTy::DocFileBin(ifstream& is)
{
    int type;
    if (!is.read((char*)&type, sizeof(type)))
        throw runtime_error("Khong doc duoc type tu file binary");

    NhanSu* ns = nullptr;

    switch (type)
    {
        case 0:
            ns = new PhongBan();
            break;
        case 1:
            ns = new NhanVienVanPhong();
            break;
        case 2:
            ns = new NhanVienSanXuat();
            break;
        case 3:
            ns = new NhanVienQuanLy();
            break;
        default:
            throw runtime_error("Type nhan su khong hop le");
    }

    ns->Load(is);
    return ns;
}
