#include "geofunction.h"
#include "geofunction.cpp"
#include <iomanip>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, Vector const& v) {
    return os << '(' << v.x << ',' << v.y << ')';
}

signed main() {
    double x, y;
    cin >> x >> y;
    Vector v1(x, y);
    cin >> x >> y;
    Vector v2(x, y);

    cout.precision(3);
    cout.setf(ios::fixed);
    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 dot v2 = " << v1 * v2 << endl;
    cout << "v1 cross v2 = " << (v1 ^ v2) << endl;
    cout << "Area of v1 v2: " << v1.area(v2) << endl;
    cout << "project v1 onto v2 = " << v1.projection(v2) << endl;

    return 0;
}
