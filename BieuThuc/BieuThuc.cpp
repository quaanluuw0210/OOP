#include<iostream>
#include<string>
#include<vector>
#include"BieuThuc.hpp"
using namespace std;

BieuThuc::BieuThuc()
{
    
}
void BieuThuc::AddLeft(BieuThuc*l)
{
    return;
}
 void BieuThuc::AddRight(BieuThuc*r)
 {
    return;
 }
string BieuThuc::Xuat()
{
    return "";
}
 int BieuThuc::getValue()
 {
    return 0;
 }
BieuThuc::~BieuThuc()
{

}
BieuThuc& BieuThuc::operator+(BieuThuc&orther)
{
    return *new PhepCong(this,&orther);
}
BieuThuc& BieuThuc::operator-(BieuThuc&orther)
{
    return *new PhepTru(this,&orther);
}
BieuThuc& BieuThuc::operator*(BieuThuc&orther)
{
    return *new PhepNhan(this,&orther);
}
BieuThuc& BieuThuc::operator/(BieuThuc&orther)
{
    return *new PhepChia(this,&orther);
}

PhepToan::PhepToan()
{
    this->left=nullptr;
    this->right=nullptr;
}
PhepToan::PhepToan(BieuThuc*l,BieuThuc*r)
{
    this->left=l;
    this->right=r;
}
void PhepToan::AddLeft(BieuThuc*l)
{
    this->left=l;
}
void PhepToan::AddRight(BieuThuc*r)
{
    this->right=r;
}
string PhepToan::Xuat()
{
    return"";
}
int  PhepToan::getValue()
{
    return 0;
}

PhepCong::PhepCong():PhepToan()
{
    
}
PhepCong::PhepCong(BieuThuc*l,BieuThuc*r):PhepToan(l,r)
{

}
string PhepCong::Xuat()
{
    string chuoi="("+this->left->Xuat()+"+"+this->right->Xuat()+")";
    return chuoi;
}
int PhepCong::getValue()
{
    return this->left->getValue()+this->right->getValue();
}

PhepTru::PhepTru():PhepToan()
{
    
}
PhepTru::PhepTru(BieuThuc*l,BieuThuc*r):PhepToan(l,r)
{

}
string PhepTru::Xuat()
{
    string chuoi="("+this->left->Xuat()+"-"+this->right->Xuat()+")";
    return chuoi;
}
int PhepTru::getValue()
{
    return this->left->getValue()-this->right->getValue();
}

PhepNhan::PhepNhan():PhepToan()
{
    
}
PhepNhan::PhepNhan(BieuThuc*l,BieuThuc*r):PhepToan(l,r)
{

}
string PhepNhan::Xuat()
{
    string chuoi="("+this->left->Xuat()+"*"+this->right->Xuat()+")";
    return chuoi;
}
int PhepNhan::getValue()
{
    return this->left->getValue()*this->right->getValue();
}

PhepChia::PhepChia():PhepToan()
{
    
}
PhepChia::PhepChia(BieuThuc*l,BieuThuc*r):PhepToan(l,r)
{

}
string PhepChia::Xuat()
{
    string chuoi="("+this->left->Xuat()+"/"+this->right->Xuat()+")";
    return chuoi;
}
int PhepChia::getValue()
{
    return this->left->getValue()/this->right->getValue();
}

So::So()
{
    this->value=0;
}
So::So(int value)
{
    this->value=value;
}
string So::Xuat()
{
    return to_string(value);
}
int So::getValue()
{
    return this->value;
}