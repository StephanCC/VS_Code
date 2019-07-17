#include"Calculator.h"
#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;

void Calculator::enter(double num){
    S.push(num);
}

bool Calculator::getTwoOperands(double &opnd1,double &opnd2){
    if (S.isEmpty()){
        cerr<<"Mising operand!"<<endl;
        return false;
    }
    opnd1=S.pop();
    if(S.isEmpty()){
        cerr<<"Missing operand"<<endl;
        return false;
    }
    opnd2=S.pop();
    return true;
}

void Calculator::compute(char op){
    double operand1,operand2;
    bool result=getTwoOperands(operand1,operand2);

    if (result){
        switch(op){
            case '+':
                S.push(operand2+operand1);
                break;
            case '-':
                S.push(operand2-operand1);
                break;
            case '*':
                S.push(operand2*operand1);
                break;
            case '/':
                if (operand1==0){
                    cerr<<"ERROR, Divided by 0!!"<<endl;
                    S.clear();
                }
                else
                    S.push(operand2/operand1);
                break;
            case '^':
                S.push(pow(operand2,operand1));
                break;
            default:
                cerr<<"Unrecognized operator"<<endl;
                S.clear();
                break;
        }
        cout<<"="<<S.peek()<<"  ";
    }
    else
    {
        S.clear();
    }
}

inline double stringToDouble(const string &str){
    istringstream stream(str);
    double result;
    stream>>result;
    return result;
}
void Calculator::run(){
    string str;
    while(cin>>str,str!="q"){
        switch (str[0])
        {
        case 'c':
            S.clear();
            break;
        case '-':
            if(str.size()>1)
                enter(stringToDouble(str));
            else
            {
                compute(str[0]);
            }
            break;
        case '+':
        case '*':
        case '/':
        case '^':
            compute(str[0]);
            break;
        
        default:
            enter(stringToDouble(str));
            break;
        }
    }
}

void Calculator::clear(){
    S.clear();
}





    
