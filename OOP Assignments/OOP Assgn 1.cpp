#include <iostream>
#include <conio.h>
using namespace std;
class Complex {
    public:
    float real,img;
    Complex(){}
    Complex operator+ (Complex);
    Complex operator- (Complex);
    Complex operator* (Complex);
    friend ostream &operator<<(ostream &,Complex&);
    friend istream &operator>>(istream &,Complex&);
};

Complex Complex::operator+ (Complex obj) {
    Complex temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return (temp);
}

istream &operator>>(istream &is, Complex &obj) {
    is>>obj.real;
    is>>obj.img;
    return is;
}

ostream &operator<<(ostream &outt, Complex &obj) {
    outt<<" "<<obj.real;
    outt<<"+"<<obj.img<<"i";
    return outt;
}
Complex Complex::operator- (Complex obj) {
    Complex temp;
    temp.real=real-obj.real;
    temp.img=img-obj.img;
    return (temp);
}

Complex Complex::operator* (Complex obj) {
    Complex temp;
    temp.real=real*obj.real-img*obj.img;
    temp.img=img*obj.real+real*obj.img;
    return (temp);
}

int main() {
    Complex a,b,c,d,e;
    int ch;

    cout<<"For 1st complex number"<<endl;
    cout << "Enter real and imaginary:" << endl;
    cin >> a;

    cout<<"For 2nd complex number"<<endl;
    cout << "Enter real and imaginary:" << endl;
    cin >> b;

    bool repeat = true;
    while(repeat) {
        cout << "Menu" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice:" << flush;
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Addition is:" << flush;
                c=a+b;
                cout << c << endl;
                break;

            case 2:
                cout << "Subtraction is:" << flush;
                d=a-b;
                cout << d << endl;
                break;

            case 3:
                cout << "Multiplication is:" << flush;
                e=a*b;
                cout << e << endl;
                break;

            case 4:
                cout<<"exitting the code"<<endl;
                repeat=false;
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    getch();
    return 0;
}