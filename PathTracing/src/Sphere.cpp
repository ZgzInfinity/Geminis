

#include "../include/Sphere.h"


Sphere::Sphere(){}

Sphere::Sphere(const Point _center, const float _radius, const RGB _emission){
    center = _center;
    radius = _radius;
    emission = _emission;
}