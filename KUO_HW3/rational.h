#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>

class Rational {
public:
    Rational(int n, int d) : numerator(n), denominator(d) {}
    Rational Add(Rational const& b) const;
    Rational Sub(Rational const& b) const;
    Rational Mul(Rational const& b) const;
    Rational Div(Rational const& b) const;

    void print(std::ostream& os) const;

private:
    int numerator;
    int denominator;
};

#endif