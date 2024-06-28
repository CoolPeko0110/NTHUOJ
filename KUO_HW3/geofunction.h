#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>

class Vector {
private:
    double x, y;

public:
    Vector() = delete;
    Vector(double _x, double _y) : x(_x), y(_y) {}
    [[nodiscard]] Vector operator+(Vector const& rhs) const;
    [[nodiscard]] double operator*(Vector const& rhs) const;
    [[nodiscard]] double operator^(Vector const& rhs) const;

    [[nodiscard]] double area(Vector const& rhs) const;
    [[nodiscard]] Vector projection(Vector const& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, Vector const& v);
};

#endif