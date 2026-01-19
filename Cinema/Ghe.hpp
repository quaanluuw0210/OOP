#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Seat
{
    protected:
    float giaGhe;
    public:
    Seat(float g=0);
    virtual float TinhGiaGhe(int soLuong)=0;
    virtual void SetGiaGhe(float newPrice);
    virtual void XuatThongTin()=0;
};

class NormalSeat:public Seat
{
    public:
    NormalSeat(float g=0);
    float TinhGiaGhe(int soLuong) override;
    void XuatThongTin() override;
};
class VipSeat:public Seat // phu thu them phi
{
    private:
    float phiPhuThu;
    public:
    VipSeat(float g=0,float p=0);
    float TinhGiaGhe(int soLuong) override;
    void XuatThongTin() override;
};

class SweetBox:public Seat // tinh gia theo cap
{
    private:
    public:
    SweetBox(float g=0);
    float TinhGiaGhe(int soLuong) override;
    void XuatThongTin() override;
};

class Ve2D;
class Ve3D;
class VeIMax;
class DieuKhienGia
{
    private:
    Ve2D* ve2d;
    Ve3D* ve3d;
    VeIMax* veimaxl;
    public:
    DieuKhienGia();
    void ThemVe2D(Ve2D* new2D);
    void ThemVe3D(Ve3D* new3D);
    void ThemVeIMax(VeIMax* newImax);
    void DieuChinhGiaVe(float newPrice);
};
class TicKet
{
    protected:
    float giaVe;
    DieuKhienGia* control;
    public:
    TicKet(float g=0);
    float LayGiaVe();
    void ThemControl(DieuKhienGia* dk);
    virtual void CapNhatGiaVe(float newPrice)=0;
    virtual int LoaiVe()=0;
    virtual void XuatThongTin()=0;
};

class Ve3D:public TicKet // gia ve phu thuoc vo 2d
{
    public:
    Ve3D(float g=0);
    int LoaiVe() override;
    void CapNhatGiaVe(float newPrice) override;
    void XuatThongTin() override;
};

class Ve2D:public TicKet // gia ve duoc dieu chinh
{
    public:
    Ve2D(float g=0);
    int LoaiVe() override;
    void CapNhatGiaVe(float newPrice) override;
    void XuatThongTin() override;
};

class VeIMax:public TicKet // gia ve phu thuoc 2d
{
    public:
    VeIMax(float g=0);
    int LoaiVe() override;
    void CapNhatGiaVe(float newPrice) override;
    void XuatThongTin() override;
};


class Food
{
    protected:
    string nameFood;
    float foodvalue;
    public:
    Food(string name="",float v=0);
    virtual float TinhGia(TicKet* ticket);
    virtual void XuatThongTin();
};

class ComBo:public Food
{
    private:
    Food* first;
    Food* second;
    public:
    ComBo(Food* f=nullptr,Food* s=nullptr);
    float TinhGia(TicKet* ticket) override;
    void XuatThongTin();
};

class MemberShip
{
    protected:
    public:
    MemberShip();
    virtual float TinhTongGiaHoaDon(float v)=0;
    virtual void XuatThongTin()=0;
};

class KhachVangLai:public MemberShip //Khong co uu dai 
{
    public:
    KhachVangLai();
    float TinhTongGiaHoaDon(float v) override;
    void XuatThongTin() override;
};

class KhachHangThanThiet:public MemberShip // Giam 10% gia tri hoa don
{
    public:
    KhachHangThanThiet();
    float TinhTongGiaHoaDon(float v) override;
    void XuatThongTin() override;
};

class KhachHangDinamon:public MemberShip //TichDiem 10% gia tri hoa don
{
    private:
    float soDiemDaTich;
    public:
    KhachHangDinamon();
    float TinhTongGiaHoaDon(float v) override;
    void XuatThongTin() override;
};


class PhienDatVe
{
    private:
    TicKet* loaiVe;
    Seat* loaiGhe;
    int soLuongGhe;
    Food* loaiDoAn;
    MemberShip* loaiThanhVien;
    public:
    PhienDatVe();
    void XuatThongTin();
    float TinhTongHoaDon();
    void ChonLoaiGhe(Seat* loaighe);
    void ChonLoaiVe(TicKet* loaive);
    void ChonLoaiDoAn(Food* loaiFood);
    void ChonloaiThanhVien(MemberShip* loaiMember);
    void ChonSoGhe(int ghe);
};

