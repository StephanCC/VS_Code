#include<iostream>
using namespace std;

class Complex{
public:
    Complex(double real=0.0, double image=0.0):re(real),im(image){};
    Complex operator+(const Complex c2)const;
    Complex operator-(const Complex c2)const;
    void display() const;
private:
    double re,im;
};

Complex Complex::operator+(const Complex c2)const{
    return Complex(re+c2.re,im+c2.im);
}

Complex Complex::operator-(const Complex c2)const{
    return Complex(re-c2.re,im-c2.im);
}



void Complex::display()const{
    cout<<"The real part is  "<< re<<" ,the imag part is  "<<im<<endl;
}


int main(){
    Complex a(1,2),b(3,4),c,d;
    c=a+b;
    c.display();
    d.display();
    
    return 0;
}

