#include<iostream>
#include"PhongBan.hpp"
#include"CongTy.hpp"
using namespace std;


PhongBan::PhongBan():NhanSu()
{

}
PhongBan::PhongBan(string name):NhanSu(name)
{

}
void PhongBan::Add(NhanSu* moi)
{
    this->dsCon.push_back(moi);
}
int PhongBan::TinhLuong()
{
    int total=0;
    for(int i=0;i<this->dsCon.size();i++)
    {
        total+=this->dsCon[i]->TinhLuong();
    }
    return total;
}
int PhongBan::SoLuong()
{
    int total=0;
    for(int i=0;i<this->dsCon.size();i++)
    {
        total+=this->dsCon[i]->SoLuong();
    }
    return total;
}

NhanSu* PhongBan::TimBangTen(string name)
{
    if(this->name==name)
    {
        return this;
    }
    else
    {
        NhanSu*temp=NULL;
        
    for(int i=0;i<this->dsCon.size();i++)
    {
      temp=dsCon[i]->TimBangTen(name);
      if(temp!=NULL)
      {
        return temp;
      }
    }
    }
    return NULL;
}

void PhongBan::Xuat(int depth)
{
    NhanSu::Xuat(depth);
    cout<<this->name<<endl;
    for(int i=0;i<this->dsCon.size();i++)
    {
       this->dsCon[i]->Xuat(depth+1);
    }
}
void PhongBan::Write(ofstream&of)
{
    int type=0;
    of.write((char*)&type,sizeof(type));
    int len=this->name.size();
    of.write((char*)&len,sizeof(len));
    of.write(name.c_str(),len);
    int count=this->dsCon.size();
    of.write((char*)&count,sizeof(count));
    for(int i=0;i<count;i++)
    {
        this->dsCon[i]->Write(of);
    }
}
void PhongBan::Load(ifstream&is)
{
    int len;
    is.read((char*)&len,sizeof(len));
    this->name.resize(len);
    is.read(&name[0],len);
    int count;
    is.read((char*)&count,sizeof(count));
    for(int i=0;i<count;i++)
    {
        this->dsCon.push_back(CongTy::getInstance().DocFileBin(is));
    }
}