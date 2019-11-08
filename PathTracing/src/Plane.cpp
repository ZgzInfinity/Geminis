
#include "../include/Plane.h"


Plane::Plane(){}

Plane::Plane(const Direction _normal, const float _distance2origin, const RGB _emission){
    normal = _normal;
    distance2origin = _distance2origin;
    emission = _emission;
}