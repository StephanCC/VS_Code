#include<iostream>
using namespace std;

class Clock{
public:
    Clock(int Hour=0,int Min=0, int Sec=0);
    void showTime()const;
    Clock& operator++();
    Clock operator++(int);
private:
    int H,M,S;
};

// Clock::Clock(int Hour, int Min, int Sec):H(Hour),M(Min),S(Sec){}

Clock::Clock(int Hour, int Min, int Sec){
    if(0<=Hour && Hour<24 && 0<=Min && Min<24 && Sec>=0 && Sec<24){
        this->H=Hour;
        this->M=Min;
        this->S=Sec;
    }else
    {
        cout<<"Time Error!"<<endl;
    }
    
}

void Clock::showTime()const{
    cout<<H<<" : "<<M<<" : "<<S<<endl;
}

Clock& Clock::operator++(){
    S++;
    if(S>60)
        S-=61;
        M++;
        if(M>60)
            M-=61;
            H++;
            if(H==24)
                *this=Clock();
}

Clock Clock::operator++(int){
    Clock old=*this;
    ++(*this);
    return old;
}


int main(){
    Clock myClock(23,59,59);
    cout<<"First time output:  ";
    myClock.showTime();
    cout<<"show myClock++:  ";
    (myClock++).showTime();
    cout<<"show ++myClock:  ";
    (++myClock).showTime();
    return 0;
}