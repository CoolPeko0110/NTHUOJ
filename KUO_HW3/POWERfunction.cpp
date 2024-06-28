#include "POWERfunction.h"
using ll = long long;
special_power::special_power(int n) {
    this->n = n;
}
int special_power::fpow(int x) {
    ll temp = x;
    for(int i=1;i<n;i++){
        temp = (temp*x)%880301;
    }
    return temp;
}
int special_power::fpow(int x, int m) {
    ll temp = x;
    for(int i=1;i<n;i++){
        temp = (temp*x)%m;
    }
    return temp;
}
int special_power::fpow() {
    ll temp = 1;
    for(int i=0;i<n;i++){
        temp = (temp*2)%880301;
    }
    return temp;
}
string special_power::fpow(string s) {
    string str;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<n;j++){
            str += s[i];
        }
    }
    return str;
}
string special_power::fpow(string s, int m) {
    string str; int count = 0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<n;j++){
            str += s[i];
            count++;
            if(count == m) return str;
        }
    }
    return str;
}