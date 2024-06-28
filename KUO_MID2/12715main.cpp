#include "12715.h"
#include <cstring>
#include <iostream>

using namespace oj;

BigInt::BigInt(char *s){
    int len = strlen(s);
    _val = new char[len+1];
    strcpy(_val, s);
    _val[len] = 0;
}
BigInt::~BigInt(){
    delete[] _val;
}
BigInt& BigInt::operator++(){
    int len = strlen(_val);
    int carry = 1;
    for(int i=len-1;i>=0;i--){
        _val[i] += carry;
        if(_val[i]>'9'){
            _val[i] = '0';
        }
        else{
            carry = 0;
            break;
        }
    }
    if(_val[0] == '0' && carry){
        char *now = new char[len+1];
        now[0] = '1';
        strcpy(&now[1], _val);
        _val = now;
    }
    return *this;
}
BigInt BigInt::operator++(int){
    BigInt *newB = new BigInt(_val);
    this->operator++();
    return *newB;
}
BigInt& BigInt::operator--(){
    if(_val[0] == '1' && !_val[1]){
        _val[0] = '0';
        return *this;
    }
    if(_val[0] == '0') return *this;
    int len = strlen(_val);
    int carry = 1;
    for(int i=len-1;i>=0;i--){
        _val[i] -= carry;
        if(_val[i]<'0'){
            _val[i] = '9';
        }
        else{
            carry = 0;
            break;
        }
    }
    if(_val[0] == '0'){
        char *now = new char[len-1];
        strcpy(now, &_val[1]);
        _val = now;   
    }
    return *this;
}
BigInt BigInt::operator--(int){
    BigInt *newB = new BigInt(_val);
    this->operator--();
    return *newB;
}
char* BigInt::to_s(){
    return _val;
}