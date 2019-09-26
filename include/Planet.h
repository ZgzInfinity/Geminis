#ifndef PLANET_H
#define PLANET_H

#include <iostream>

#include "Direction.h"
#include "Point.h"
#include "SharedOps.h"

using namespace std;

struct Planet {
    Point center;
    Direction axis;
    Point refCity;
    Planet(Point _center, Direction _axis, Point _refCity);
};

#endif /* PLANET_H */