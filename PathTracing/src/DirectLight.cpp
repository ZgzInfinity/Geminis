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
 * DirectLight.cpp implementation file of DirectLight module
 */


#include "../include/DirectLight.h"


/**
 * Default builder without parameters
 */
DirectLight::DirectLight(){}



/**
 * Build a Sphere type object
 * @param _location is the point in the space of the direct light source 
 * @param _power is the power of the direct light source
 * @param _color is the color of the direct light source
 * @returns a DirectLight type object
 */
DirectLight::DirectLight(const Point _location, const float _power, const RGB _color){
    location = _location;
    power = _power;
    color = _color;
}


