#include<iostream>
#include<vector>
#include<string>
#include"Ghe.hpp"
using namespace std;

PhienDatVe::PhienDatVe()
{
    this->loaiGhe=nullptr;
    this->loaiDoAn=nullptr;
    this->loaiThanhVien=nullptr;
    this->loaiVe=nullptr;
    this->soLuongGhe=0;
}
void PhienDatVe::XuatThongTin()
{
    if(this->loaiVe!=nullptr)
    {
        this->loaiVe->XuatThongTin();
    }
    if(this->loaiGhe!=nullptr)
    {
        this->loaiGhe->XuatThongTin();
    }
    if(this->soLuongGhe!=0)
    {
        cout<<"So luong ghe: "<<this->soLuongGhe<<endl;
    }
    if(this->loaiThanhVien!=nullptr)
    {
        this->loaiThanhVien->XuatThongTin();
    }
    if(this->loaiDoAn!=nullptr)
    {
        this->loaiDoAn->XuatThongTin();
    }
    
}
float PhienDatVe::TinhTongHoaDon()
{
    float total=0;
    if(this->loaiVe!=nullptr)
    {
        total+=this->loaiVe->LayGiaVe()*soLuongGhe;
    }
    
    if(this->loaiGhe!=nullptr)
    {
        total+=this->loaiGhe->TinhGiaGhe(this->soLuongGhe);
    }
    
    if(this->loaiDoAn!=nullptr)
    {
        total+=this->loaiDoAn->TinhGia(loaiVe);
    }
    
    if(this->loaiThanhVien!=nullptr)
    {
        total==this->loaiThanhVien->TinhTongGiaHoaDon(total);
    }
    
   return total;
}
void PhienDatVe::ChonLoaiGhe(Seat* loaighe)
{       
    if(loaighe!=nullptr)
    {
        this->loaiGhe=loaighe;
    }

}
void PhienDatVe::ChonLoaiVe(TicKet* loaive)
{
    if(loaive!=nullptr)
    {
        this->loaiVe=loaive;
    }
}
void PhienDatVe::ChonLoaiDoAn(Food* loaiFood)
{
    if(loaiFood!=nullptr)
    {
        this->loaiDoAn=loaiFood;
    }
}
void PhienDatVe::ChonloaiThanhVien(MemberShip* loaiMember)
{
    if(loaiMember!=nullptr)
    {
        this->loaiThanhVien=loaiMember;
    }
}
void PhienDatVe::ChonSoGhe(int ghe)
{
    if(ghe>0)
    {
        this->soLuongGhe=ghe;
    }
}


Seat::Seat(float g)
{
    this->giaGhe=g;
}

void Seat::SetGiaGhe(float newPrice)
{
    this->giaGhe=newPrice;
}

NormalSeat::NormalSeat(float g)
{
    this->giaGhe=g;
}
float NormalSeat::TinhGiaGhe(int soLuong)
{
    return this->giaGhe*soLuong;
}
void NormalSeat::XuatThongTin()
{
    cout<<"Ghe thuong, gia: "<<this->giaGhe<<endl;
}


VipSeat::VipSeat(float g,float p)
{
    this->giaGhe=g;
    this->phiPhuThu=p;
}
float VipSeat::TinhGiaGhe(int soLuong)
{
    return this->giaGhe*soLuong+phiPhuThu;
}
void VipSeat::XuatThongTin()
{
    cout<<"Ghe vip, gia: "<<this->giaGhe<<endl;
}


SweetBox::SweetBox(float g)
{
    this->giaGhe=g;
}
float SweetBox::TinhGiaGhe(int soLuong)
{
    if(soLuong%2!=0)
    {
        soLuong+=1;// lam tron len so chan gan nhat lon hon
    }
    return this->giaGhe*soLuong;
}
void SweetBox::XuatThongTin()
{
    cout<<"Ghe sweetbox, gia: "<<this->giaGhe<<endl;
}


DieuKhienGia::DieuKhienGia()
{
    this->ve2d=nullptr;
    this->ve3d=nullptr;
    this->veimaxl=nullptr;
}
void DieuKhienGia::ThemVe2D(Ve2D* new2D)
{
    this->ve2d=new2D;
}
void DieuKhienGia::ThemVe3D(Ve3D* new3D)
{
    this->ve3d=new3D;
}
void DieuKhienGia::ThemVeIMax(VeIMax* newImax)
{
    this->veimaxl=newImax;
}
void DieuKhienGia::DieuChinhGiaVe(float newPrice)
{
    float value=newPrice;
    this->ve2d->CapNhatGiaVe(value);
    this->ve3d->CapNhatGiaVe(value+20000); // ve 3d luon dat hon 20k VND
    this->veimaxl->CapNhatGiaVe(value*0.5+value); // ve imax luon cao hon 50%
};

TicKet::TicKet(float g)
{
    this->giaVe=g;
}
float TicKet::LayGiaVe()
{
    return giaVe;
}
void TicKet::ThemControl(DieuKhienGia* dk)
{
    if(dk!=nullptr)
    {
        this->control=dk;
    }
}

Ve2D::Ve2D(float g):TicKet(g)
{

}
int Ve2D::LoaiVe()
{
    return 1;
}
void Ve2D::CapNhatGiaVe(float newPrice) 
{
    this->giaVe=newPrice;
    
}
void Ve2D::XuatThongTin() 
{
    cout<<"Ve 2d, gia: "<<this->giaVe<<endl;
}


Ve3D::Ve3D(float g)
{
    this->giaVe=g;
}
int Ve3D::LoaiVe()
{
    return 2;
}
void Ve3D::CapNhatGiaVe(float newPrice)
{
    this->giaVe=newPrice;
}
void Ve3D::XuatThongTin() 
{
    cout<<"Ve 3d, gia: "<<this->giaVe<<endl;
}

VeIMax::VeIMax(float g)
{
    this->giaVe=g;
}
int VeIMax::LoaiVe()
{
    return 3;
}
void VeIMax::CapNhatGiaVe(float newPrice)
{
    this->giaVe=newPrice;
}
void VeIMax::XuatThongTin()
{
    cout<<"Ve IMAX, gia: "<<this->giaVe<<endl;
}


Food::Food(string name,float v)
{
    this->foodvalue=v;
    this->nameFood=name;
}
float Food::TinhGia(TicKet* ticket)
{
    return this->foodvalue;
}
void Food::XuatThongTin()
{
    cout<<"Loai do an: "<<this->nameFood<<" , gia: "<<this->foodvalue<<endl;
}


ComBo::ComBo(Food* f,Food* s)
{
    this->first=f;
    this->second=s;
}
float ComBo::TinhGia(TicKet* ticket)
{
    float total=this->first->TinhGia(ticket)+this->second->TinhGia(ticket);
    if(ticket->LoaiVe()==3)
    {
        return total*0.8;
    }
    return total;
}
void ComBo::XuatThongTin()
{
    cout<<"Combo\n";
    cout<<"\t";
    this->first->XuatThongTin();
    cout<<"\t";
    this->second->XuatThongTin();
}

MemberShip::MemberShip()
{
    
}

KhachVangLai::KhachVangLai()
{

}
float KhachVangLai::TinhTongGiaHoaDon(float v)
{
    return v;
}
void KhachVangLai::XuatThongTin()
{
    cout<<"Khanh vang lai\n";
}

KhachHangThanThiet::KhachHangThanThiet()
{

}
float KhachHangThanThiet::TinhTongGiaHoaDon(float v)
{
    return 0.9*v;   
}
void KhachHangThanThiet::XuatThongTin()
{
    cout<<"Khach hang than thiet\n";
}

KhachHangDinamon::KhachHangDinamon()
{

}
float KhachHangDinamon::TinhTongGiaHoaDon(float v) 
{
    this->soDiemDaTich+=v*0.1;
    if(soDiemDaTich>=200000)
    {
        return v*0.7;
    }
    
    return v*0.95;
}
void KhachHangDinamon::XuatThongTin()
{
    cout<<"Khach hang dinamon\n";
}