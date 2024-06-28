#include "geofunction.h"
#include <math.h>
using du = double;

Vector Vector::operator+(Vector const& rhs) const {
    du tx, ty;
    tx = x + rhs.x;
    ty = y + rhs.y;
    return Vector(tx, ty);
}

double Vector::operator*(Vector const& rhs) const {
    du temp;
    temp = x*rhs.x + y*rhs.y;
    return temp;
}

double Vector::operator^(Vector const& rhs) const {
    du temp;
    temp = x*rhs.y - y*rhs.x;
    return temp;
}

double Vector::area(Vector const& rhs) const {
    du temp;
    temp = (x*rhs.y - y*rhs.x)/2;
    temp = temp>0?temp:-temp;
    return temp;
}

Vector Vector::projection(Vector const& rhs) const {
    du tx, ty, temp;
    tx = (x*rhs.x + y*rhs.y) * rhs.x / (rhs.x*rhs.x + rhs.y*rhs.y);
    ty = (x*rhs.x + y*rhs.y) * rhs.y / (rhs.x*rhs.x + rhs.y*rhs.y);
    return Vector(tx, ty);
}