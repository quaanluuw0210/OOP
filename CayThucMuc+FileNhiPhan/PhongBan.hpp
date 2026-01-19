#include"CongTy.hpp"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


class PhongBan:public NhanSu
{
    private:
    vector<NhanSu*>dsCon;
    public:
    PhongBan();
    PhongBan(string name);
    void Add(NhanSu*moi);
    void Xuat(int depth);
    int TinhLuong();
    int SoLuong();
    NhanSu* TimBangTen(string name);
    void Write(ofstream&of);
    void Load(ifstream&is);
};