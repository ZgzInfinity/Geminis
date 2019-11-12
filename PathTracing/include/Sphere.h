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


/*
 * Definition of data type Sphere
 */
struct Sphere {
    // Center of the sphere
    Point center;
    // Radius of the sphere
    float radius;
    // Color emission ray
    RGB emission;



    /**
     * Default builder without parameters
     */
    Sphere();



    /**
     * Build a Sphere type object
     * @param _center is the center of the sphere
     * @param _radius is the radius of the sphere
     * @param _emission is a color emission ray
     * @returns a Sphere type object
     */
    Sphere(const Point _center, const float _radius, const RGB _emission);
    
};

#endif