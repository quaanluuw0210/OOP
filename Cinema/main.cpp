#include<iostream>
#include<vector>
#include<string>
#include"Ghe.hpp"
using namespace std;

int main() {
    // --- 1. KHOI TAO DU LIEU GOC (MASTER DATA) ---
    // Tao bo dieu khien gia de lien ket cac loai ve
    DieuKhienGia* controlCenter = new DieuKhienGia();

    Ve2D* v2d = new Ve2D(80000); // Gia goc 80k
    Ve3D* v3d = new Ve3D(0);      // Gia se tu cap nhat theo 2D
    VeIMax* vimax = new VeIMax(0);

    v2d->ThemControl(controlCenter);
    v3d->ThemControl(controlCenter);
    vimax->ThemControl(controlCenter);

    controlCenter->ThemVe2D(v2d);
    controlCenter->ThemVe3D(v3d);
    controlCenter->ThemVeIMax(vimax);

    // Thiet lap gia goc ban dau (kich hoat tinh da hinh cap nhat gia)
    controlCenter->DieuChinhGiaVe(100000); 

    // Khoi tao cac loai ghe
    Seat* gheThuong = new NormalSeat(0); // Khong phu thu
    Seat* gheVip = new VipSeat(0, 20000); // Phu thu 20k
    Seat* gheDoi = new SweetBox(50000);   // Gia 50k/ghe (tinh theo cap)

    // Khoi tao do an
    Food* bap = new Food("Bap Rang Bo", 50000);
    Food* nuoc = new Food("Coca Cola", 30000);
    ComBo* combo1 = new ComBo(bap, nuoc);

    // --- 2. KICH BAN TEST 1: KHACH VANG LAI XEM VE 2D ---
    cout << "--- PHIEN DAT VE 1: KHACH VANG LAI ---" << endl;
    PhienDatVe phien1;
    phien1.ChonLoaiVe(v2d);
    phien1.ChonLoaiGhe(gheThuong);
    phien1.ChonSoGhe(2);
    phien1.ChonLoaiDoAn(bap);
    phien1.ChonloaiThanhVien(new KhachVangLai());
    
    phien1.XuatThongTin();
    cout << "TONG HOA DON 1: " << phien1.TinhTongHoaDon() << " VND" << endl << endl;

    // --- 3. KICH BAN TEST 2: KHACH DIAMOND XEM IMAX + GHE VIP ---
    cout << "--- PHIEN DAT VE 2: KHACH DIAMOND (UU DAI IMAX) ---" << endl;
    PhienDatVe phien2;
    phien2.ChonLoaiVe(vimax); // Ve IMax thuong dat hon 2D 50%
    phien2.ChonLoaiGhe(gheVip);
    phien2.ChonSoGhe(1);
    phien2.ChonLoaiDoAn(combo1); // Neu la IMax, combo se duoc giam gia
    phien2.ChonloaiThanhVien(new KhachHangDinamon());
    
    phien2.XuatThongTin();
    // Luu y: Neu ban da cai Decorator nhu toi huong dan, hay goi ham XuatHoaDonCuoi()
    cout << "TONG HOA DON 2: " << phien2.TinhTongHoaDon() << " VND" << endl << endl;

    // --- 4. KICH BAN TEST 3: THAY DOI GIA THI TRUONG ---
    cout << "--- THAY DOI GIA VE 2D LEN 120K ---" << endl;
    controlCenter->DieuChinhGiaVe(120000);
    cout << "Gia ve 3D moi (tu dong cap nhat): " << v3d->LayGiaVe() << " VND" << endl;

    // --- 5. DON DEP BO NHO (CLEAN UP) ---
    // Trong thuc te ban can viet destructor cho cac lop de delete cac con tro
    delete v2d; delete v3d; delete vimax;
    delete gheThuong; delete gheVip; delete gheDoi;
    delete bap; delete nuoc; delete combo1;
    delete controlCenter;

    return 0;
}