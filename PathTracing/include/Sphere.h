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
 * Sphere.h interface file of the Sphere module
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "Point.h"
#include "RGB.h"


struct Sphere {

    Point center;
    float radius;
    RGB emission;

    Sphere();

    Sphere(const Point _center, const float _radius, const RGB _emission);
};

#endif