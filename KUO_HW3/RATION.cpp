#include "rational.h"
#include "rational.cpp"
#include <cassert>
#include <cctype>
#include <iostream>

#define NDEBUG

using namespace std;

void solve(void) {
    int n1, d1, n2, d2;
    char op;
    cin >> n1;
    assert(cin.peek() == '/');
    cin.ignore();
    cin >> d1;
    assert(cin.peek() == ' ');
    cin.ignore();
    cin >> op;
    assert(cin.peek() == ' ');
    cin.ignore();
    cin >> n2;
    assert(cin.peek() == '/');
    cin.ignore();
    cin >> d2;

    switch (op) {
        case '+':
            Rational(n1, d1).Add(Rational(n2, d2)).print(cout);
            break;
        case '-':
            Rational(n1, d1).Sub(Rational(n2, d2)).print(cout);
            break;
        case '*':
            Rational(n1, d1).Mul(Rational(n2, d2)).print(cout);
            break;
        case '/':
            Rational(n1, d1).Div(Rational(n2, d2)).print(cout);
            break;
        default:
            assert(false);
    }

    cout << "\n";
}

int main() {
    int n;
    cin >> n;

    while (n--) solve();

    cout << flush;

    return 0;
}
