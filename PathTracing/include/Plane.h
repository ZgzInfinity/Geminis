
#include "Direction.h"
#include "RGB.h"


struct Plane {
    Direction normal;
    float distance2origin;
    RGB emission;

    Plane();

    Plane(const Direction _normal, const float _distance2origin, const RGB _emission);
};