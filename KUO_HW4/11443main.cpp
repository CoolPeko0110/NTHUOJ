#include "11443function.h"
using namespace oj;

Sphere::Sphere(double r, double pi){
    if(r<0||pi<0) setVolume(0);
    else setVolume(pi*r*r*r*4/3);
}

Cone::Cone(double r, double h, double pi){
    if(r<0||h<0||pi<0) setVolume(0);
    else setVolume(pi*r*r*h/3);
}

Cuboid::Cuboid(double l, double w, double h){
    if(l<0||w<0||h<0) setVolume(0);
    else setVolume(l*w*h);
}

Cube::Cube(double l):Cuboid(l, l, l){};