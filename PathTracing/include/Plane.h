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
  * Plane.h interface file of Plane module
  */


#include "Direction.h"
#include "RGB.h"


/*
 * Definition of data type Plane
 */
struct Plane {
    // The normal direction vector 
    Direction normal;
    // Distance between the plane and the origin point
    float distance2origin;
    // Color emission ray
    RGB emission;



    /**
     * Default builder without parameters
     */
    Plane();



    /**
     * Build a Plane type object
     * @param _normal is the normal direction vector 
     * @param _distance2origin is the distance between the plane and the origin point
     * @param _emission is a color emission ray
     * @returns a Point type object
     */
    Plane(const Direction _normal, const float _distance2origin, const RGB _emission);
};