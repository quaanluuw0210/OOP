#include<iostream>
#include<vector>
#include<string>
#include"CongTy.hpp"
#include"NhanVien.hpp"
#include"PhongBan.hpp"


using namespace std;

int main()
{
    CongTy ct=CongTy::getInstance();
    ifstream is("save.bin",ios::binary);
    if(is.is_open())
    {
        cout<<"Doc file binary\n";
        NhanSu*p=CongTy::getInstance().DocFileBin(is);
        p->Print();
        is.close();
        cout << "\n===== TONG LUONG =====\n";
        cout << p->TinhLuong() << endl;

    }
    else
    {
        cout<<"Doc file text\n";
        ifstream fs("run.txt",ios::in);
         NhanSu* root = ct.TaoCongTyVoiFileText(fs);

        cout << "===== CAY NHAN SU =====\n";
        root->Xuat(0);

        cout << "\n===== TONG LUONG =====\n";
        cout << root->TinhLuong() << endl;

        // ---- GHI FILE BIN ----
        ofstream fout("save.bin", ios::binary);
        if (fout.is_open())
        {
            root->Write(fout);
            fout.close();
            cout << "\nDa ghi file save.bin\n";
        }
        fs.close();
        delete root;
   
    }
       
   
    return 0;
}
