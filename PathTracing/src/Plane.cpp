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
  * Plane.cpp implementation file of Plane module
  */

#include "../include/Plane.h"


/**
 * Default builder without parameters
 */
Plane::Plane(){}



/**
 * Build a Plane type object
 * @param _normal is the normal direction vector 
 * @param _distance2origin is the distance between the plane and the origin point
 * @param _emission is a color emission ray
 * @returns a Point type object
 */
Plane::Plane(const Direction _normal, const float _distance2origin, const RGB _emission){
    normal = _normal;
    distance2origin = _distance2origin;
    emission = _emission;
}