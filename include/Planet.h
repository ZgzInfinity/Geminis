/*
 *******************************************
 *** Geminis - Computer Graphics Project ***
 *** Authors: Name - Surname - NIP *********
 *** Victor Peñasco EStivalez - 741294 *****
 *** Ruben Rodriguez Esteban - 737215 ******
 *** Course: 2019 - 2020 *******************
 *******************************************
 */ 


/*
 * Planet.h interface file of Planet module
 */

#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include "Direction.h"
#include "Point.h"
#include "SharedOps.h"


using namespace std;


/*
 * Definition of data type Planet
 */
struct Planet {
    // Center of the planet
    Point center;
    // Axis of the planet
    Direction axis;
    // Referenced city of the planet
    Point refCity;
    // Radius of the planet
    float radius;


    /**
     * Build a Planet type object
     * @param _center center of the planet
     * @param _axis axis of the planet
     * @param _refCity referenced-city of the planet
     * @returns a Planet type object
     */
    Planet(Point _center, Direction _axis, Point _refCity);

    Planet();
};

#endif /* PLANET_H */