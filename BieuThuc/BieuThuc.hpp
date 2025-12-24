#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;





class BieuThuc
{
    public:
    BieuThuc();
    virtual void AddLeft(BieuThuc*l);
    virtual  void AddRight(BieuThuc*r);
    virtual string Xuat();
    virtual int getValue();
    BieuThuc& operator+(BieuThuc&orther);
    BieuThuc& operator-(BieuThuc&orther);
    BieuThuc& operator*(BieuThuc&orther);
    BieuThuc& operator/(BieuThuc&orther);
    virtual ~BieuThuc();
};

class PhepToan:public BieuThuc
{
    protected:
    BieuThuc* left;
    BieuThuc*right;
    public:
    PhepToan();
    PhepToan(BieuThuc*l,BieuThuc*r);
    void AddLeft(BieuThuc*l);
    void AddRight(BieuThuc*r);
    virtual string Xuat();
    virtual int  getValue();
};
class PhepCong:public PhepToan
{
    public:
    PhepCong();
    PhepCong(BieuThuc*l,BieuThuc*r);
    string Xuat();
    int getValue();
};
class PhepTru:public PhepToan
{
    public:
    PhepTru();
    PhepTru(BieuThuc*l,BieuThuc*r);
    string Xuat();
    int getValue();
};
class PhepChia:public PhepToan
{
    public:
    PhepChia();
    PhepChia(BieuThuc*l,BieuThuc*r);
    string Xuat();
    int getValue();
};

class PhepNhan:public PhepToan
{
    public:
    PhepNhan();
    PhepNhan(BieuThuc*l,BieuThuc*r);
    string Xuat();
    int getValue();
};
class So:public BieuThuc
{
    private:
    int value;
    public:
    So();
    So(int value);
    string Xuat();
    int getValue();
};


