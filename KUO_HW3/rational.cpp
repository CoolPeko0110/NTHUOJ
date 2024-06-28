#include "rational.h"
using ll = long long;

Rational Rational::Add(Rational const& b) const {
    ll n1 = this->numerator; ll n2 = b.numerator;
    ll d1 = this->denominator; ll d2 = b.denominator;
    ll n = n1*d2+n2*d1;
    ll d = d1*d2;
    ll gcd;
    ll t1 = n>0?n:-n, t2 = d>0?d:-d;
    while(t1%t2){
        ll temp = t1%t2;
        t1 = t2;
        t2 = temp;
    }
    gcd = t2;
    n /= gcd;
    d /= gcd;
    if(d<0){
        d = -d;
        n = -n;
    }
    return Rational(n, d);
}
Rational Rational::Sub(Rational const& b) const {
    ll n1 = this->numerator; ll n2 = b.numerator;
    ll d1 = this->denominator; ll d2 = b.denominator;
    ll n = n1*d2-n2*d1;
    ll d = d1*d2;
    ll gcd;
    ll t1 = n>0?n:-n, t2 = d>0?d:-d;
    while(t1%t2){
        ll temp = t1%t2;
        t1 = t2;
        t2 = temp;
    }
    gcd = t2;
    n /= gcd;
    d /= gcd;
    if(d<0){
        d = -d;
        n = -n;
    }
    return Rational(n, d);
}
Rational Rational::Mul(Rational const& b) const {
    ll n1 = this->numerator; ll n2 = b.numerator;
    ll d1 = this->denominator; ll d2 = b.denominator;
    ll n = n1*n2;
    ll d = d1*d2;
    ll gcd;
    ll t1 = n>0?n:-n, t2 = d>0?d:-d;
    while(t1%t2){
        ll temp = t1%t2;
        t1 = t2;
        t2 = temp;
    }
    gcd = t2;
    n /= gcd;
    d /= gcd;
    if(d<0){
        d = -d;
        n = -n;
    }
    return Rational(n, d);
}
Rational Rational::Div(Rational const& b) const {
    ll n1 = this->numerator; ll n2 = b.numerator;
    ll d1 = this->denominator; ll d2 = b.denominator;
    ll n = n1*d2;
    ll d = n2*d1;
    ll gcd;
    ll t1 = n>0?n:-n, t2 = d>0?d:-d;
    while(t1%t2){
        ll temp = t1%t2;
        t1 = t2;
        t2 = temp;
    }
    gcd = t2;
    n /= gcd;
    d /= gcd;
    if(d<0){
        d = -d;
        n = -n;
    }
    return Rational(n, d);
}
void Rational::print(std::ostream& os) const {
    std::cout<<numerator<<"/"<<denominator;
}