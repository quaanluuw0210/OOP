#include<iostream>
#include<vector>
#include<string>

#include"BieuThuc.hpp"

int main()
{
    // ===== Test 1: Biểu thức đơn giản =====
    BieuThuc* a = new So(5);
    BieuThuc* b = new So(3);
    BieuThuc *e1 = &(*a + *b);
    cout << "Exprestion 1: " << e1->Xuat() << endl;
    cout << "Value    : " << e1->getValue() << endl;
    cout << "--------------------------" << endl;

    // ===== Test 2: Kết hợp nhiều toán tử =====
    BieuThuc* c = new So(2);
    BieuThuc* d = new So(10);

    // (5 + 3) * 2
    BieuThuc *e2 =&((*a + *b) * (*c));
    cout << "Exprestion 2: " << e2->Xuat() << endl;
    cout << "Value    : " << e2->getValue() << endl;
    cout << "--------------------------" << endl;

    // ===== Test 3: Biểu thức phức tạp =====
    // (5 + 3) * (10 - 2) / 4
    BieuThuc *e3 = &(((*a + *b) * (*d - *c)) / *new So(4));
    cout << "Exprestion 3: " << e3->Xuat() << endl;
    cout << "Value    : " << e3->getValue() << endl;
    cout << "--------------------------" << endl;

    // ===== Test 4: So sánh kết quả =====
    if (e2->getValue() > e1->getValue())
        cout << "Exp 2 > Exp 1" << endl;
    else
        cout << "Exp 2 <= Exp 1" << endl;

    // ===== Giải phóng bộ nhớ =====
    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}