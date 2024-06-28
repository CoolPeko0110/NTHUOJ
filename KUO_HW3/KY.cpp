#include "KYfunction.h"
#include "KYfunction.cpp"
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;
int n, k, q;

int main() {
    cin >> n >> k >> q;
    assert(k <= 4000);
    KuoYangPresent present = KuoYangPresent(k);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        assert(x <= 10000);
        present.Push(x);
    }
    while (q--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            assert(x <= 10000);
            present.Push(x);
            present.PrintList();
        } else if (op == "pop") {
            present.Pop();
            present.PrintList();
        } else if (op == "reverse") {
            present.Reverse();
            present.PrintList();
        } else {
            cin >> op;
            present.ProgrammingTanoshi();
            present.PrintList();
        }
    }
    present.KuoYangTeTe();
    present.PrintList();
}
