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
 * DirectLight.h interface file of the DirectLight module
 */

#ifndef DIRECT_LIGHT_H
#define DIRECT_LIGHT_H


#include "Point.h"
#include "RGB.h"


const int DIM_DIRECT_LIGHT = 3;


/*
 * Definition of data type DirectLight
 */
struct DirectLight {
    // Point in the space
    Point location;
    // RGB color 
    RGB color;


    /**
     * Default builder without parameters
     */
    DirectLight();



    /**
     * Build a Sphere type object
     * @param _location is the point in the space of the direct light source 
     * @param _color is the color of the direct light source
     * @returns a DirectLight type object
     */
    DirectLight(const Point _location, const RGB _color);

};

#endif